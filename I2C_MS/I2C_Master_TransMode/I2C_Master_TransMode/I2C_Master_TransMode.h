/*
 * I2C_Master_TransMode.h
 *
 * Created: 7/1/2018 2:39:20 PM
 *  Author: Ram
 */ 


#ifndef I2C_MASTER_TRANSMODE_H_
#define I2C_MASTER_TRANSMODE_H_


#include <stdint.h>

typedef enum
{
	WriteAddress,
	WriteData
	
} WriteMode;


void I2C_init(void);

void I2C_start(void);

void I2C_write(WriteMode eMode, uint8_t data);

void I2C_stop(void);


#endif /* I2C_MASTER_TRANSMODE_H_ */