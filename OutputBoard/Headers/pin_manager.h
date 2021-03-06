/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC18F27Q43
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
        MPLAB 	          :  MPLAB X 5.45	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RED aliases
#define RED_TRIS                 TRISAbits.TRISA0
#define RED_LAT                  LATAbits.LATA0
#define RED_PORT                 PORTAbits.RA0
#define RED_WPU                  WPUAbits.WPUA0
#define RED_OD                   ODCONAbits.ODCA0
#define RED_ANS                  ANSELAbits.ANSELA0
#define RED_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define RED_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define RED_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define RED_GetValue()           PORTAbits.RA0
#define RED_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define RED_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define RED_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define RED_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define RED_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define RED_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define RED_SetAnalogMode()      do { ANSELAbits.ANSELA0 = 1; } while(0)
#define RED_SetDigitalMode()     do { ANSELAbits.ANSELA0 = 0; } while(0)

// get/set GREEN aliases
#define GREEN_TRIS                 TRISAbits.TRISA1
#define GREEN_LAT                  LATAbits.LATA1
#define GREEN_PORT                 PORTAbits.RA1
#define GREEN_WPU                  WPUAbits.WPUA1
#define GREEN_OD                   ODCONAbits.ODCA1
#define GREEN_ANS                  ANSELAbits.ANSELA1
#define GREEN_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define GREEN_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define GREEN_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define GREEN_GetValue()           PORTAbits.RA1
#define GREEN_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define GREEN_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define GREEN_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define GREEN_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define GREEN_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define GREEN_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define GREEN_SetAnalogMode()      do { ANSELAbits.ANSELA1 = 1; } while(0)
#define GREEN_SetDigitalMode()     do { ANSELAbits.ANSELA1 = 0; } while(0)

// get/set DAC_Out aliases
#define DAC_Out_TRIS                 TRISAbits.TRISA2
#define DAC_Out_LAT                  LATAbits.LATA2
#define DAC_Out_PORT                 PORTAbits.RA2
#define DAC_Out_WPU                  WPUAbits.WPUA2
#define DAC_Out_OD                   ODCONAbits.ODCA2
#define DAC_Out_ANS                  ANSELAbits.ANSELA2
#define DAC_Out_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define DAC_Out_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define DAC_Out_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define DAC_Out_GetValue()           PORTAbits.RA2
#define DAC_Out_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define DAC_Out_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define DAC_Out_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define DAC_Out_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define DAC_Out_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define DAC_Out_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define DAC_Out_SetAnalogMode()      do { ANSELAbits.ANSELA2 = 1; } while(0)
#define DAC_Out_SetDigitalMode()     do { ANSELAbits.ANSELA2 = 0; } while(0)

// get/set LCD_Enable aliases
#define LCD_Enable_TRIS                 TRISAbits.TRISA3
#define LCD_Enable_LAT                  LATAbits.LATA3
#define LCD_Enable_PORT                 PORTAbits.RA3
#define LCD_Enable_WPU                  WPUAbits.WPUA3
#define LCD_Enable_OD                   ODCONAbits.ODCA3
#define LCD_Enable_ANS                  ANSELAbits.ANSELA3
#define LCD_Enable_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define LCD_Enable_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define LCD_Enable_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define LCD_Enable_GetValue()           PORTAbits.RA3
#define LCD_Enable_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define LCD_Enable_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define LCD_Enable_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define LCD_Enable_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)
#define LCD_Enable_SetPushPull()        do { ODCONAbits.ODCA3 = 0; } while(0)
#define LCD_Enable_SetOpenDrain()       do { ODCONAbits.ODCA3 = 1; } while(0)
#define LCD_Enable_SetAnalogMode()      do { ANSELAbits.ANSELA3 = 1; } while(0)
#define LCD_Enable_SetDigitalMode()     do { ANSELAbits.ANSELA3 = 0; } while(0)

// get/set LCD_RW aliases
#define LCD_RW_TRIS                 TRISAbits.TRISA4
#define LCD_RW_LAT                  LATAbits.LATA4
#define LCD_RW_PORT                 PORTAbits.RA4
#define LCD_RW_WPU                  WPUAbits.WPUA4
#define LCD_RW_OD                   ODCONAbits.ODCA4
#define LCD_RW_ANS                  ANSELAbits.ANSELA4
#define LCD_RW_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define LCD_RW_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define LCD_RW_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define LCD_RW_GetValue()           PORTAbits.RA4
#define LCD_RW_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define LCD_RW_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define LCD_RW_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define LCD_RW_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define LCD_RW_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define LCD_RW_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define LCD_RW_SetAnalogMode()      do { ANSELAbits.ANSELA4 = 1; } while(0)
#define LCD_RW_SetDigitalMode()     do { ANSELAbits.ANSELA4 = 0; } while(0)

// get/set LCD_RS aliases
#define LCD_RS_TRIS                 TRISAbits.TRISA5
#define LCD_RS_LAT                  LATAbits.LATA5
#define LCD_RS_PORT                 PORTAbits.RA5
#define LCD_RS_WPU                  WPUAbits.WPUA5
#define LCD_RS_OD                   ODCONAbits.ODCA5
#define LCD_RS_ANS                  ANSELAbits.ANSELA5
#define LCD_RS_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define LCD_RS_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define LCD_RS_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define LCD_RS_GetValue()           PORTAbits.RA5
#define LCD_RS_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define LCD_RS_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define LCD_RS_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define LCD_RS_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define LCD_RS_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define LCD_RS_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define LCD_RS_SetAnalogMode()      do { ANSELAbits.ANSELA5 = 1; } while(0)
#define LCD_RS_SetDigitalMode()     do { ANSELAbits.ANSELA5 = 0; } while(0)

// get/set BLUE aliases
#define BLUE_TRIS                 TRISAbits.TRISA7
#define BLUE_LAT                  LATAbits.LATA7
#define BLUE_PORT                 PORTAbits.RA7
#define BLUE_WPU                  WPUAbits.WPUA7
#define BLUE_OD                   ODCONAbits.ODCA7
#define BLUE_ANS                  ANSELAbits.ANSELA7
#define BLUE_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define BLUE_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define BLUE_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define BLUE_GetValue()           PORTAbits.RA7
#define BLUE_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define BLUE_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define BLUE_SetPullup()          do { WPUAbits.WPUA7 = 1; } while(0)
#define BLUE_ResetPullup()        do { WPUAbits.WPUA7 = 0; } while(0)
#define BLUE_SetPushPull()        do { ODCONAbits.ODCA7 = 0; } while(0)
#define BLUE_SetOpenDrain()       do { ODCONAbits.ODCA7 = 1; } while(0)
#define BLUE_SetAnalogMode()      do { ANSELAbits.ANSELA7 = 1; } while(0)
#define BLUE_SetDigitalMode()     do { ANSELAbits.ANSELA7 = 0; } while(0)

// get/set RB0 procedures
#define RB0_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define RB0_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define RB0_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define RB0_GetValue()              PORTBbits.RB0
#define RB0_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define RB0_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define RB0_SetPullup()             do { WPUBbits.WPUB0 = 1; } while(0)
#define RB0_ResetPullup()           do { WPUBbits.WPUB0 = 0; } while(0)
#define RB0_SetAnalogMode()         do { ANSELBbits.ANSELB0 = 1; } while(0)
#define RB0_SetDigitalMode()        do { ANSELBbits.ANSELB0 = 0; } while(0)

// get/set RB1 procedures
#define RB1_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define RB1_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define RB1_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define RB1_GetValue()              PORTBbits.RB1
#define RB1_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define RB1_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define RB1_SetPullup()             do { WPUBbits.WPUB1 = 1; } while(0)
#define RB1_ResetPullup()           do { WPUBbits.WPUB1 = 0; } while(0)
#define RB1_SetAnalogMode()         do { ANSELBbits.ANSELB1 = 1; } while(0)
#define RB1_SetDigitalMode()        do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set RB2 procedures
#define RB2_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define RB2_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define RB2_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define RB2_GetValue()              PORTBbits.RB2
#define RB2_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define RB2_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define RB2_SetPullup()             do { WPUBbits.WPUB2 = 1; } while(0)
#define RB2_ResetPullup()           do { WPUBbits.WPUB2 = 0; } while(0)
#define RB2_SetAnalogMode()         do { ANSELBbits.ANSELB2 = 1; } while(0)
#define RB2_SetDigitalMode()        do { ANSELBbits.ANSELB2 = 0; } while(0)

// get/set RB3 procedures
#define RB3_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define RB3_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define RB3_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define RB3_GetValue()              PORTBbits.RB3
#define RB3_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define RB3_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define RB3_SetPullup()             do { WPUBbits.WPUB3 = 1; } while(0)
#define RB3_ResetPullup()           do { WPUBbits.WPUB3 = 0; } while(0)
#define RB3_SetAnalogMode()         do { ANSELBbits.ANSELB3 = 1; } while(0)
#define RB3_SetDigitalMode()        do { ANSELBbits.ANSELB3 = 0; } while(0)

// get/set LCD_D0 aliases
#define LCD_D0_TRIS                 TRISCbits.TRISC0
#define LCD_D0_LAT                  LATCbits.LATC0
#define LCD_D0_PORT                 PORTCbits.RC0
#define LCD_D0_WPU                  WPUCbits.WPUC0
#define LCD_D0_OD                   ODCONCbits.ODCC0
#define LCD_D0_ANS                  ANSELCbits.ANSELC0
#define LCD_D0_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define LCD_D0_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define LCD_D0_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define LCD_D0_GetValue()           PORTCbits.RC0
#define LCD_D0_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define LCD_D0_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define LCD_D0_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define LCD_D0_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define LCD_D0_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define LCD_D0_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define LCD_D0_SetAnalogMode()      do { ANSELCbits.ANSELC0 = 1; } while(0)
#define LCD_D0_SetDigitalMode()     do { ANSELCbits.ANSELC0 = 0; } while(0)

// get/set LCD_D1 aliases
#define LCD_D1_TRIS                 TRISCbits.TRISC1
#define LCD_D1_LAT                  LATCbits.LATC1
#define LCD_D1_PORT                 PORTCbits.RC1
#define LCD_D1_WPU                  WPUCbits.WPUC1
#define LCD_D1_OD                   ODCONCbits.ODCC1
#define LCD_D1_ANS                  ANSELCbits.ANSELC1
#define LCD_D1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define LCD_D1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define LCD_D1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define LCD_D1_GetValue()           PORTCbits.RC1
#define LCD_D1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define LCD_D1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define LCD_D1_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define LCD_D1_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define LCD_D1_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define LCD_D1_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define LCD_D1_SetAnalogMode()      do { ANSELCbits.ANSELC1 = 1; } while(0)
#define LCD_D1_SetDigitalMode()     do { ANSELCbits.ANSELC1 = 0; } while(0)

// get/set LCD_D2 aliases
#define LCD_D2_TRIS                 TRISCbits.TRISC2
#define LCD_D2_LAT                  LATCbits.LATC2
#define LCD_D2_PORT                 PORTCbits.RC2
#define LCD_D2_WPU                  WPUCbits.WPUC2
#define LCD_D2_OD                   ODCONCbits.ODCC2
#define LCD_D2_ANS                  ANSELCbits.ANSELC2
#define LCD_D2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define LCD_D2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define LCD_D2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define LCD_D2_GetValue()           PORTCbits.RC2
#define LCD_D2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define LCD_D2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define LCD_D2_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define LCD_D2_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define LCD_D2_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define LCD_D2_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define LCD_D2_SetAnalogMode()      do { ANSELCbits.ANSELC2 = 1; } while(0)
#define LCD_D2_SetDigitalMode()     do { ANSELCbits.ANSELC2 = 0; } while(0)

// get/set LCD_D3 aliases
#define LCD_D3_TRIS                 TRISCbits.TRISC3
#define LCD_D3_LAT                  LATCbits.LATC3
#define LCD_D3_PORT                 PORTCbits.RC3
#define LCD_D3_WPU                  WPUCbits.WPUC3
#define LCD_D3_OD                   ODCONCbits.ODCC3
#define LCD_D3_ANS                  ANSELCbits.ANSELC3
#define LCD_D3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define LCD_D3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define LCD_D3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define LCD_D3_GetValue()           PORTCbits.RC3
#define LCD_D3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define LCD_D3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define LCD_D3_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define LCD_D3_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define LCD_D3_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define LCD_D3_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define LCD_D3_SetAnalogMode()      do { ANSELCbits.ANSELC3 = 1; } while(0)
#define LCD_D3_SetDigitalMode()     do { ANSELCbits.ANSELC3 = 0; } while(0)

// get/set LCD_D4 aliases
#define LCD_D4_TRIS                 TRISCbits.TRISC4
#define LCD_D4_LAT                  LATCbits.LATC4
#define LCD_D4_PORT                 PORTCbits.RC4
#define LCD_D4_WPU                  WPUCbits.WPUC4
#define LCD_D4_OD                   ODCONCbits.ODCC4
#define LCD_D4_ANS                  ANSELCbits.ANSELC4
#define LCD_D4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define LCD_D4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define LCD_D4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define LCD_D4_GetValue()           PORTCbits.RC4
#define LCD_D4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define LCD_D4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define LCD_D4_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define LCD_D4_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define LCD_D4_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define LCD_D4_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define LCD_D4_SetAnalogMode()      do { ANSELCbits.ANSELC4 = 1; } while(0)
#define LCD_D4_SetDigitalMode()     do { ANSELCbits.ANSELC4 = 0; } while(0)

// get/set LCD_D5 aliases
#define LCD_D5_TRIS                 TRISCbits.TRISC5
#define LCD_D5_LAT                  LATCbits.LATC5
#define LCD_D5_PORT                 PORTCbits.RC5
#define LCD_D5_WPU                  WPUCbits.WPUC5
#define LCD_D5_OD                   ODCONCbits.ODCC5
#define LCD_D5_ANS                  ANSELCbits.ANSELC5
#define LCD_D5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define LCD_D5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define LCD_D5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define LCD_D5_GetValue()           PORTCbits.RC5
#define LCD_D5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define LCD_D5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define LCD_D5_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define LCD_D5_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define LCD_D5_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define LCD_D5_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define LCD_D5_SetAnalogMode()      do { ANSELCbits.ANSELC5 = 1; } while(0)
#define LCD_D5_SetDigitalMode()     do { ANSELCbits.ANSELC5 = 0; } while(0)

// get/set LCD_D6 aliases
#define LCD_D6_TRIS                 TRISCbits.TRISC6
#define LCD_D6_LAT                  LATCbits.LATC6
#define LCD_D6_PORT                 PORTCbits.RC6
#define LCD_D6_WPU                  WPUCbits.WPUC6
#define LCD_D6_OD                   ODCONCbits.ODCC6
#define LCD_D6_ANS                  ANSELCbits.ANSELC6
#define LCD_D6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define LCD_D6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define LCD_D6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define LCD_D6_GetValue()           PORTCbits.RC6
#define LCD_D6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define LCD_D6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define LCD_D6_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define LCD_D6_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define LCD_D6_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define LCD_D6_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define LCD_D6_SetAnalogMode()      do { ANSELCbits.ANSELC6 = 1; } while(0)
#define LCD_D6_SetDigitalMode()     do { ANSELCbits.ANSELC6 = 0; } while(0)

// get/set LCD_D7 aliases
#define LCD_D7_TRIS                 TRISCbits.TRISC7
#define LCD_D7_LAT                  LATCbits.LATC7
#define LCD_D7_PORT                 PORTCbits.RC7
#define LCD_D7_WPU                  WPUCbits.WPUC7
#define LCD_D7_OD                   ODCONCbits.ODCC7
#define LCD_D7_ANS                  ANSELCbits.ANSELC7
#define LCD_D7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define LCD_D7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define LCD_D7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define LCD_D7_GetValue()           PORTCbits.RC7
#define LCD_D7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define LCD_D7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define LCD_D7_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define LCD_D7_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define LCD_D7_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define LCD_D7_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define LCD_D7_SetAnalogMode()      do { ANSELCbits.ANSELC7 = 1; } while(0)
#define LCD_D7_SetDigitalMode()     do { ANSELCbits.ANSELC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/