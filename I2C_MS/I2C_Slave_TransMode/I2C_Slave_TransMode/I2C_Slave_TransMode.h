/*
 * I2C_Slave_TransMode.h
 *
 * Created: 7/1/2018 4:19:06 PM
 *  Author: Ram
 */ 


#ifndef I2C_SLAVE_TRANSMODE_H_
#define I2C_SLAVE_TRANSMODE_H_

#include <stdint.h>

void I2C_init(void);

void I2C_SlaveMatchACK(void);

void I2C_write(uint8_t data);


#endif /* I2C_SLAVE_TRANSMODE_H_ */