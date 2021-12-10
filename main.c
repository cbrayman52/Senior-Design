#define FCY 921250
#include <libpic30.h>
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/mcc.h"
#include "i2c.h"
#include <stdint.h>
#include <stdio.h>
#include <math.h>

uint8_t convertTemperature(uint16_t temp);

volatile uint8_t flag = 0;
volatile uint8_t acknowledge;
volatile uint8_t transmit_ready = 1;
uint8_t transmit_failed = 0;
uint8_t start_condition = 0xFF;

uint8_t rpm_buffer[8];
uint8_t bpm_buffer[8];
uint8_t index = 0;
uint8_t buffer_full = 0;
uint8_t timer_flag = 0;

uint16_t gsr_result;
uint16_t temperature;
volatile uint8_t resp_count = 0;
volatile uint8_t ppg_count = 0;

volatile uint8_t training_rpm = 0;
volatile uint8_t training_bpm = 0;
uint8_t training_gsr = 0;
uint8_t training_bdt = 0;
volatile uint8_t count_rpm = 1;
volatile uint8_t count_bpm = 1;
uint8_t count_gsr = 1;
uint8_t count_bdt= 1;

uint8_t previous_rpm[2] = {0, 0};
uint8_t previous_bpm[2] = {0, 0};
uint8_t previous_gsr[2] = {0, 0};
uint8_t previous_bdt[2] = {0, 0};

volatile uint8_t rpm = 0;    //Respiratory rate
volatile uint8_t bpm = 0;    //Pulse Rate
uint8_t gsr = 0;    //GSR
uint8_t bdt = 0;    //Body temp
uint8_t lie_detected;
uint8_t possible_lie = 0;
uint8_t mode;       /* 
                     * 0. Truth
                     * 1. Lie
                     * 2. Train
                     */

void timer_isr(void)
{    
    timer_flag = 1;
    
    rpm_buffer[index & 0x07] = resp_count;
    bpm_buffer[index++ & 0x07] = ppg_count;
    
    ppg_count = 0;
    resp_count = 0;
    
    if (index == 8)
        buffer_full = 1;
}

void start_transmission(void)
{
    UART1_Write(start_condition);
}

void uart_isr(void)
{        
    IFS0bits.U1RXIF = 0;
    while (U1STAbits.URXDA == 1)
        acknowledge = U1RXREG;
        
    flag = 1;
    
    IFS4bits.U1EIF = 0;
}

int main(void)
{
    //Initialize System
    SYSTEM_Initialize();
    
    //Initialize ADC
    ADC1_ChannelSelect(GSR_AN0);    //Selects the pin to be connected to the ADC unit
    
    //Initialize I2C
    I2C_Init();
    
    //Initialize UART Receive Interrupt
    UART1_SetRxInterruptHandler(uart_isr);
    
    while(1)
    {   
        if (Switch_Input_GetValue() == 1)   //Testing mode
        {
            if (bdt > previous_bdt[0] + 1)
                possible_lie++;
            else if ((bdt > previous_bdt[0]) && (previous_bdt[0] > previous_bdt[1]))
                possible_lie++;
            
            /*if (gsr < training_gsr - 3)
                possible_lie++;*/
            if (gsr < previous_gsr[0] - 2)
                possible_lie++;
            else if ((gsr < previous_gsr[0]) && (previous_gsr[0] < previous_gsr[1]))
                possible_lie++;
            
            if (bpm > previous_bpm[0] + 2)
                possible_lie++;
            else if (bpm > previous_bpm[1] + 2)
                possible_lie++;
            
            if (rpm > training_rpm + 3)
                possible_lie++;
            
            if (possible_lie > 1)
                lie_detected = 1;
            else
                lie_detected = 0;
            
            possible_lie = 0;
        }
        
        if ((buffer_full == 1) && (timer_flag == 1))
        {
            timer_flag = 0;
            
            previous_rpm[1] = previous_rpm[0];
            previous_rpm[0] = rpm;
            
            previous_bpm[1] = previous_bpm[0];
            previous_bpm[0] = bpm;
            
            rpm = (rpm_buffer[0] + rpm_buffer[1] + rpm_buffer[2] + rpm_buffer[3]
                    + rpm_buffer[4] + rpm_buffer[5] + rpm_buffer[6] + rpm_buffer[7]) * 2;    
            bpm = (bpm_buffer[0] + bpm_buffer[1] + bpm_buffer[2] + bpm_buffer[3]
                    + bpm_buffer[4] + bpm_buffer[5] + bpm_buffer[6] + bpm_buffer[7]) * 2;
            
            if (Switch_Input_GetValue() == 0)
            {
                training_rpm = (((count_rpm - 1) * training_rpm) + rpm) / count_rpm;
                training_bpm = (((count_bpm - 1) * training_bpm) + bpm) / count_bpm;
                
                count_rpm++;
                count_bpm++;
            }
        }
        
        if (flag == 1)
        {
            flag = 0;
            
            if (acknowledge == 0x10)
            {
                if (Switch_Input_GetValue() == 0)
                    UART1_Write(training_rpm);
                else
                    UART1_Write(rpm);
            }
            else if (acknowledge == 0x20)
            {
                if (Switch_Input_GetValue() == 0)
                    UART1_Write(training_bpm);
                else
                    UART1_Write(bpm);
            }
            else if (acknowledge == 0x30)
            {
                /***** GSR *****/
                if (ADC1_IsConversionComplete(GSR_AN0))             //Returns a True if the ADC unit has finished the conversion.
                    gsr_result = ADC1_ConversionResultGet(GSR_AN0); //Returns the value of the last conversion.
                ADC1_SoftwareTriggerDisable();                      //Clear sample bit to end sampling and start conversion
                
                previous_gsr[1] = previous_gsr[0];
                previous_gsr[0] = gsr;
                
                gsr = (uint8_t) (((float) gsr_result * 255.0) / 4095.0);
                
                if ((Switch_Input_GetValue() == 0) && (gsr > 0))
                {
                    training_gsr = (((count_gsr - 1) * training_gsr) + gsr) / count_gsr;
                    count_gsr++;
                    UART1_Write(training_gsr);
                }
                else                
                    UART1_Write(gsr);
            }
            else if (acknowledge == 0x40)
            {
                /***** Body Temperature *****/
                temperature = getTemperature();
                
                previous_bdt[1] = previous_bdt[0];
                previous_bdt[0] = bdt;
                
                bdt = convertTemperature(temperature);
                
                if ((Switch_Input_GetValue() == 0) && (bdt != 0))
                {
                    training_bdt = (((count_bdt - 1) * training_bdt) + bdt) / count_bdt;
                    count_bdt++;
                    UART1_Write(training_bdt);
                }
                else
                    UART1_Write(bdt);
            }
            else if (acknowledge == 0x50)
            {
                if (Switch_Input_GetValue() == 0)
                    mode = 2;
                else if (lie_detected == 0)
                    mode = 1;
                else if (lie_detected == 1)
                    mode = 0;
                else
                    mode = 4;
                UART1_Write(mode);
            }
            else if (acknowledge == start_condition)
            {
                EXT_INT_Initialize();   //Initialize external interrupts
                
                //Timer 1 -> 15 second timer to calculate heart rate/respiratory rate
                TMR1_SetInterruptHandler(timer_isr);     //Registers a user defined function as the ISR for TMR1
                TMR1_Start();           //Start timer for respiratory/ppg rates
                
                //Timer 2 -> 1 second timer to initiate UART Transmission sequence
                TMR2_SetInterruptHandler(start_transmission);
                TMR2_Start();           //Start timer for transmissions
                
            }
        }
    }
    return 0;
}

uint8_t convertTemperature(uint16_t temp)
{
    float wholeNumber = temp >> 8;
    
    uint8_t decimalNumber = temp;
    float decimal = 0.0;
    uint8_t i;
    for(i = 0; i < 8; i++)
    {
        decimal += ((decimalNumber >> i) & 0x01) * pow(2.0,-8+i);
    }
    
    float temperature = wholeNumber + decimal;
    
    temperature = (temperature * (9.0/5.0)) + 32.0;
    
    return (uint8_t) temperature;
}