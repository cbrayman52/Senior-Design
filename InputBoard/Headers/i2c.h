#ifndef _I2C_H
#define	_I2C_H

#include <xc.h> // include processor files - each processor file is guarded.  

#define MAX30205_ADDRESS        0x90    //Slave device address
#define TEMPERATURE             0x00
#define CONFIGURATION           0x01

void I2C_Init(void);

uint16_t getTemperature(void);

#endif	/* _I2C_H */