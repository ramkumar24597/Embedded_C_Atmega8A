/*
 * I2C_Slave_RecvMode.h
 *
 * Created: 7/1/2018 2:16:16 PM
 *  Author: Ram
 */ 


#ifndef I2C_SLAVE_RECVMODE_H_
#define I2C_SLAVE_RECVMODE_H_

#include <stdint.h>


void I2C_init(uint8_t slave_address);

void I2C_SlaveMatchACK(void);

unsigned char I2C_ReadData(void);


#endif /* I2C_SLAVE_RECVMODE_H_ */