/*
 * I2C_BitBanging.h
 *
 * Created: 7/22/2018 11:40:39 AM
 *  Author: Ram
 */ 


#ifndef I2C_BITBANGING_H_
#define I2C_BITBANGING_H_


#include <stdint.h>

#define I2C_SDA					(4)
#define I2C_SCL					(5)

#define SLAVE_ADDRESS			0xD0
#define SLAVE_REG_ADDRESS		0x00

#define INPUT_PIN				PINC
#define SDA_INPUT				DDRC &= ~(1<<I2C_SDA);
#define SDA_OUTPUT				DDRC |= (1<<I2C_SDA);
#define SDA_HIGH				PORTC |= (1<<I2C_SDA);
#define SDA_LOW					PORTC &= ~(1<<I2C_SDA);

#define SCL_INPUT				DDRC &= ~(1<<I2C_SCL);
#define SCL_OUTPUT				DDRC |= (1<<I2C_SCL);
#define SCL_HIGH				PORTC |= (1<<I2C_SCL);
#define SCL_LOW					PORTC &= ~(1<<I2C_SCL);

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

void I2C_ACK(void);

void I2C_NACK(void);

void I2C_stop(void);


#endif /* I2C_BITBANGING_H_ */