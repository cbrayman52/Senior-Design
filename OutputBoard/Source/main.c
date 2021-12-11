#include "mcc_generated_files/mcc.h"
#include "header.h"

char triangle[64] = 
{
    0x08,0x10,0x18,0x20,0x28,0x30,0x38,0x40,0x48,0x50,0x58,0x60,0x68,0x70,0x78,0x80,
    0x87,0x8f,0x97,0x9f,0xa7,0xaf,0xb7,0xbf,0xc7,0xcf,0xd7,0xdf,0xe7,0xef,0xf7,0xff,
    0xf7,0xef,0xe7,0xdf,0xd7,0xcf,0xc7,0xbf,0xb7,0xaf,0xa7,0x9f,0x97,0x8f,0x87,0x80,
    0x78,0x70,0x68,0x60,0x58,0x50,0x48,0x40,0x38,0x30,0x28,0x20,0x18,0x10,0x08,0x00
};

uint8_t start_condition = 0xFF;
uint8_t counter = 0;
volatile uint8_t flag = 0;

volatile uint8_t data_in;
uint8_t rpm = 0;
uint8_t bpm = 0;
uint8_t gsr = 0;
uint8_t bdt = 0;
uint8_t lie;
uint8_t mode; 

int i = 0;
int time = 0;

void uart_isr(void)
{
    if (U1ERRIRbits.U1RXFOIF == 1)
        while(1);
    data_in = U1RXB;
    flag = 1;    
    PIR4bits.U1RXIF = 0;            //Clear interrupt flag
}

int main(void) {
    SYSTEM_Initialize();
    DAC_Init();
    GLCD_Init();
   
    UART1_SetRxInterruptHandler(uart_isr);
    INTERRUPT_GlobalInterruptEnable();
   
    while(1)
    {      
        if (flag == 1)
        {
            flag = 0;
            
            if ((data_in == start_condition) && (counter == 0))
            {
                UART1_Write(0x10);
                
                counter = 1;
            }
            else if (counter == 1)
            {
                rpm = data_in;
                LCD_DataDisplay(2, 7, 0, rpm);
                
                UART1_Write(0x20);
                
                counter = 2;
            }
            else if (counter == 2)
            {
                bpm = data_in;
                LCD_DataDisplay(2, 1, 0, bpm);
                
                UART1_Write(0x30);
                
                counter = 3;
            }
            else if (counter == 3)
            {
                gsr = data_in;
                LCD_DataDisplay(2, 5, 0, gsr);
                
                UART1_Write(0x40);
                
                counter = 4;
            }
            else if (counter == 4)
            {
                bdt = data_in;
                LCD_DataDisplay(2, 3, 0, bdt);
                
                UART1_Write(0x50);
                
                counter = 5;
            }
            else if (counter == 5)
            {
                mode = data_in;
                if (mode == 0) //liar
                {
                    BLUE_SetLow();
                    GREEN_SetLow();
                    RED_SetHigh();
                }
                else if (mode == 1) //truther
                {
                    BLUE_SetLow();
                    GREEN_SetHigh();
                    RED_SetLow();
                }
                else if (mode == 2) //trainer 
                {
                    BLUE_SetHigh();
                    GREEN_SetLow();
                    RED_SetLow();
                }
                else 
                {
                    BLUE_SetLow();
                    GREEN_SetLow();
                    RED_SetLow();
                }
                
                UART1_Write(0x60);
                                
                counter = 0;
            }
        }
        
        if (mode == 0)
        {
            DAC1DATL = triangle[i++ & 0x3F];
        }
    }  
    return 0;
}