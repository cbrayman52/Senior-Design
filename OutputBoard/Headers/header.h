#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include "mcc_generated_files/mcc.h"

void DAC_Init(void);

void GLCD_Init(void);
void LCD_TextDisplayString(uint8_t line, uint8_t offset, uint8_t space, char* string);
void LCD_DataDisplay(uint8_t line, uint8_t offset, uint8_t space, uint8_t output);
void glcd_command(unsigned char c);
void glcd_data(unsigned char d);

#endif	/* XC_HEADER_TEMPLATE_H */

