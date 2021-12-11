#include "header.h"

void ADC_Init(void)
{
    //Configure Input Port
    ANSELA = ANSELB = 0;        //Default values are 0 to disable analog
    TRISAbits.TRISA0 = 1;       //Set AN0 as input
    ANSELAbits.ANSA0 = 1;       //Configures 0th bit of PORTA for analog
    
    //Configure ADC Module
    AD1CON1bits.AD12B = 1;      //12-bit, 1-channel ADC
    AD1CON1bits.FORM = 0;       //Unsigned integer format
    AD1CON1bits.SSRCG = 0;      //Sample Trigger Source Group bit
    AD1CON1bits.SSRC = 0b000;   //Sample Trigger Source Select bits
    AD1CON1bits.ASAM = 1;       //Sampling begins immediately after the last conversion
    
    AD1CON2bits.VCFG = 0b000;   //Voltage reference
    AD1CON2bits.CSCNA = 0;      //Input Scan Select bit
    AD1CON2bits.SMPI = 0b00000; //Generates interrupt after completion of every sample/conversion operation
    
    AD1CON3bits.ADRC = 0;       //ADC1 Conversion Clock Source bit
    AD1CON3bits.SAMC = 0;       //Auto-Sample Time bits
    AD1CON3bits.ADCS = 1;       //Clock selection
    
    AD1CON4bits.ADDMAEN = 0;    //Disables the use of DMA with the ADC module
    
    AD1CON1bits.ADON = 1;       //Enable the ADC module
}
