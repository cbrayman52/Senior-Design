/****************************************************
*         144x32 Display Interface Selection        *
****************************************************/

#include "header.h"

#define WRITE_CUSTOM_CHARACTER 1

void glcd_command(unsigned char c)
{
    LATC = c;
    LATAbits.LATA5 = 0;   //digitalWrite(RS, LOW);      // Command
    LATAbits.LATA4 = 0;   //digitalWrite(RW, LOW);      // Write
    LATAbits.LATA3 = 1;   //digitalWrite(E, HIGH);
    __delay_ms(2);
    LATAbits.LATA3 = 0;   //digitalWrite(E, LOW);
    __delay_ms(2);
}

void glcd_data(unsigned char d)
{
    LATC = d;
    LATAbits.LATA5 = 1;   //digitalWrite(RS, HIGH);   // Data
    LATAbits.LATA4 = 0;   //digitalWrite(RW, LOW);    // Write
    LATAbits.LATA3 = 1;   //digitalWrite(E, HIGH);
    __delay_ms(2);
    LATAbits.LATA3 = 0;   //digitalWrite(E, LOW);
    __delay_ms(2);      
}

void LCD_TextDisplayString(uint8_t line, uint8_t offset, uint8_t space, char* string)
{  
    unsigned char addr; 
    if(line==1) 
        addr=0x80;  //The first line address
    else 
        addr=0x90;  //The second line address
    
    glcd_command(addr + offset);
    
    if (space == 1)
        glcd_data(0x20);
    for(int i = 0; i < 16; i++)
    {
        glcd_data(*string++);
        if(*string == NULL)
            break;
    }
}

void LCD_DataDisplay(uint8_t line, uint8_t offset, uint8_t space, uint8_t output)
{  
    //char test = output;
    uint8_t ones;
    uint8_t tens;
    uint8_t hundreds;
    float num;
    float num1;
    int display;    
 
    tens = 0xF0 & output;
    ones = 0x0F & output;
    tens = tens >> 4;
    num = tens * 16.0; 
    num1 = ones * 1.0;
    num = num + num1;
    
    unsigned char addr; 
    if(line==1) 
        addr=0x80;  //The first line address
    else 
        addr=0x90;  //The second line address
    
    glcd_command(addr + offset);
    
    if (num < 100.0)
    {
        num1 = num / 10.0;
        display = num1;
        tens = display + 0x30;
        num1 = display * 10.0;
        num = num - num1;
        ones = num + 0x30;
        
        if (space == 1)
            glcd_data(0x20);
        glcd_data(tens);
        glcd_data(ones);
        glcd_data(0x20);    //Blank space
    }
    else
    {
        num1 = num / 100.0;
        display = num1;
        hundreds = display + 0x30;
        num1 = display * 100.0;
        num = num - num1;
        num1 = num / 10.0;
        display = num1;
        tens = display + 0x30;
        num1 = display * 10.0;
        num = num - num1;
        ones = num + 0x30;
        
        if (space == 1)
            glcd_data(0x20);
        glcd_data(hundreds);
        glcd_data(tens);
        glcd_data(ones);
    }    
}

void LCD_CustomCharacterDisplay(void)
{
    if (WRITE_CUSTOM_CHARACTER)
    {
        const uint8_t heart[] =
        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x70, 
            0x1f, 0xf8, 0x3f, 0xfc, 0x3f, 0xfc, 0x3f, 0xfc, 
            0x3f, 0xfc, 0x1f, 0xf8, 0x0f, 0xf0, 0x07, 0xe0, 
            0x03, 0xc0, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00
        };

        glcd_command(0x40);     //Set CGRAM address to 0x0000
        for (int i = 0; i < 32; i++)
        {
            glcd_data(heart[i]);
        }

        const uint8_t thermometer[] =
        {
            0x00, 0x00, 0x00, 0x00, 0x03, 0xc0, 0x02, 0x40, 
            0x02, 0x40, 0x02, 0x40, 0x02, 0x40, 0x03, 0xc0, 
            0x03, 0xc0, 0x07, 0xe0, 0x0f, 0xf0, 0x0f, 0xf0, 
            0x0f, 0xf0, 0x07, 0xe0, 0x03, 0xc0, 0x00, 0x00
        };

        for (int i = 0; i < 32; i++)
        {
            glcd_data(thermometer[i]);
        }
        
        const uint8_t ohm[] =
        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xe0, 
            0x08, 0x10, 0x10, 0x08, 0x20, 0x04, 0x20, 0x04, 
            0x20, 0x04, 0x20, 0x04, 0x10, 0x08, 0x08, 0x10, 
            0x24, 0x24, 0x3e, 0x7c, 0x00, 0x00, 0x00, 0x00
        };

        for (int i = 0; i < 32; i++)
        {
            glcd_data(ohm[i]);
        }

        const uint8_t breath[] =
        {
            0x00, 0x00, 0x00, 0xc0, 0x01, 0xb0, 0x00, 0x10, 
            0x00, 0x30, 0x3f, 0xe0, 0x00, 0x00, 0x00, 0x00, 
            0x3f, 0xf8, 0x00, 0x00, 0x3f, 0xe0, 0x00, 0x30, 
            0x00, 0x10, 0x01, 0xb0, 0x00, 0xc0, 0x00, 0x00
        };

        //glcd_command(0x46);     //Set CGRAM address to 0x0006
        for (int i = 0; i < 32; i++)
        {
            glcd_data(breath[i]);
        }
    }
    
    glcd_command(0x81);
    glcd_data(0x00);
    glcd_data(0x00);
    
    glcd_command(0x83);
    glcd_data(0x00);
    glcd_data(0x02);
    
    glcd_command(0x85);
    glcd_data(0x00);
    glcd_data(0x04);
    
    glcd_command(0x87);
    glcd_data(0x00);
    glcd_data(0x06);
}

/****************************************************
            Initialization For controller
*****************************************************/

void GLCD_Init(void) {
    TRISC = 0;              //Port C is data output
    TRISAbits.TRISA3 = 0;   //Enable output
    TRISAbits.TRISA4 = 0;   //R/W output
    TRISAbits.TRISA5 = 0;   //RS output
    
    __delay_ms(40);
    glcd_command(0x38);  //Function set (8 bit mode)
    __delay_ms(5);
    glcd_command(0x38);  //Function set (8 bit mode)
    __delay_ms(5);
    glcd_command(0x0C);  //Display On
    __delay_ms(5);
    glcd_command(0x01);  //Display Clear
    __delay_ms(5);
    glcd_command(0x06);  //Entry mode set
    __delay_ms(5);
    glcd_command(0x02);  //Cursor returns home   
    
    LCD_CustomCharacterDisplay();
}