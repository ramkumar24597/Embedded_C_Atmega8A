/*
 * I2C_Master_RecvMode.h
 *
 * Created: 7/1/2018 4:17:31 PM
 *  Author: Ram
 */ 


#ifndef I2C_MASTER_RECVMODE_H_
#define I2C_MASTER_RECVMODE_H_

#include <stdint.h>

void I2C_init(void);

void I2C_start(void);

void I2C_write(uint8_t slave_address);

unsigned char I2C_Read(void);

void I2C_stop(void);


#endif /* I2C_MASTER_RECVMODE_H_ */