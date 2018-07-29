/*
 * I2C_TWI.h
 *
 * Created: 7/22/2018 6:12:31 AM
 *  Author: Ram
 */ 


#ifndef I2C_TWI_H_
#define I2C_TWI_H_


#include <stdint.h>
#define SLAVE_ADDRESS 0xD0
#define SLAVE_REG_ADDRESS 0x00


typedef enum
{
	WriteAddress,
	ReadAddress,
	WriteData
	
} WriteMode;


typedef enum
{
	ACK,
	NACK
	
} AckReturn;


void I2C_init(void);

void I2C_start(void);

void I2C_write(WriteMode eMode, uint8_t data);

unsigned char I2C_Read(AckReturn eAckType);

void I2C_stop(void);



#endif /* I2C_TWI_H_ */