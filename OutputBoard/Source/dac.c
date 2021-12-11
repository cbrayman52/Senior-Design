#include "header.h"

void DAC_Init(void) {
    TRISAbits.TRISA2 = 0;
    LATAbits.LATA2 = 0;
    
    DAC1CONbits.DAC1EN = 1;
    DAC1CONbits.DAC1OE = 0b10;
    DAC1CONbits.DAC1PSS1 = 0;
    DAC1CONbits.DAC1PSS0 = 0;
    DAC1CONbits.DAC1NSS = 0;
    
    return;
}
