#include "i2c.h"

void I2C_Init(void) 
{
    I2C1BRG = 0x08;         //100 kHz baud rate
                            //(921.25 kHz / 100 kHz) - (921.25 kHz / 10 MHz) - 1 = 8.12
                            //Actual Baud Rate = 101.324 kHz
        
    I2C1CONbits.SEN = 0;    //Start condition is not in progress
    I2C1CONbits.RSEN = 0;   //Repeated Start condition is not in progress
    I2C1CONbits.PEN = 0;    //Stop condition is not in progress
    I2C1CONbits.RCEN = 0;   //Receive sequence is not in progress
    I2C1CONbits.ACKEN = 0;  //Acknowledge sequence is not in progress
    I2C1CONbits.ACKDT = 0;  //Sends ACK during Acknowledge
    I2C1CONbits.STREN = 0;  //Disables software or receives clock stretching
    I2C1CONbits.GCEN = 0;   //General call address disabled
    I2C1CONbits.SMEN = 0;   //Disables SMBus input thresholds
    I2C1CONbits.DISSLW = 0; //Slew rate control is enabled
    I2C1CONbits.A10M = 0;   //7-bit address mode
    I2C1CONbits.IPMIEN = 0; //IPMI mode disabled
    I2C1CONbits.SCLREL = 0; //Holds SCLx clock low (clock stretch)
    I2C1CONbits.I2CSIDL = 0;//Continues module operation in Idle mode
    I2C1CONbits.I2CEN = 1;  //I2C enable bit
    
    I2C1CONbits.SEN = 1;        //Initiates start condition on SDAx and SCLx pins
    while (I2C1CONbits.SEN);    //Wait for start to be detected
    
    I2C1TRN = MAX30205_ADDRESS; //Select slave address
    while (I2C1STATbits.TRSTAT);
    
    I2C1TRN = CONFIGURATION;    //Select configuration register
    while (I2C1STATbits.TRSTAT);
    
    I2C1TRN = 0x00;             //Configuration register data bits
    while (I2C1STATbits.TRSTAT);
    
    I2C1CONbits.PEN = 1;        //Initiates stop condition on SDAx and SCLx pins
    while (I2C1CONbits.PEN);
}

uint16_t getTemperature(void)
{
    I2C1CONbits.SEN = 1;        //Initiates start condition on SDAx and SCLx pins
    while (I2C1CONbits.SEN);    //Wait for start to be detected
    
    I2C1TRN = MAX30205_ADDRESS; //Select slave address
    while (I2C1STATbits.TRSTAT);
    
    I2C1TRN = TEMPERATURE;      //Select temperature register
    while (I2C1STATbits.TRSTAT);
    
    I2C1CONbits.RSEN = 1;       //Initiate restart condition on SDAx and SCLx pins 
    while (I2C1CONbits.RSEN);
    
    I2C1TRN = MAX30205_ADDRESS + 1; //Select slave address
    while (I2C1STATbits.TRSTAT);
    
    I2C1CONbits.RCEN = 1;           //Enables Receive mode for I2C    
    while (I2C1CONbits.RCEN);       //Wait for receive buffer to fill up
    
    uint16_t temperature = I2C1RCV; //Read data from receive buffer
    temperature = temperature << 8;
    
    I2C1CONbits.ACKDT = 0;          //Sends ACK during Acknowledge
    I2C1CONbits.ACKEN = 1;          //Send an acknowledge bit
    while (I2C1CONbits.ACKEN);
    
    I2C1CONbits.RCEN = 1;           //Enables Receive mode for I2C    
    while (I2C1CONbits.RCEN);       //Wait for receive buffer to fill up
    
    temperature += I2C1RCV;
    
    I2C1CONbits.ACKDT = 1;          //Sends NACK during Acknowledge
    I2C1CONbits.ACKEN = 1;          //Send an acknowledge bit
    while (I2C1CONbits.ACKEN);
    
    I2C1CONbits.PEN = 1;            //Initiates stop condition on SDAx and SCLx pins
    while (I2C1CONbits.PEN);
    
    return temperature;
}