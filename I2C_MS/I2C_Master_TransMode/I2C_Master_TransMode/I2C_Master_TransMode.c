/*
 * I2C_Master_TransMode.c
 *
 * Created: 7/1/2018 2:38:50 PM
 *  Author: Ram
 */ 


#include <avr/io.h>
#include "I2C_Master_TransMode.h"

void I2C_init(void)
{
	/* Clearing status register */
	TWSR = 0x00;
	
	/* setting up bit rate */
	TWBR = 0x0C;
}

void I2C_start(void)
{
	/* setting start condition */
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTA);
	
	/* waiting to finish the start condition */
	while((TWCR & (1<<TWINT)) == 0);
	
	/* waiting until req status is obtained */
	while((TWSR & (0xF8)) != 0x08);
}

void I2C_write(WriteMode eMode, uint8_t data)
{
	/* storing slave address or data to the data buffer */
	TWDR = data;
	
	/* Enabling transfer */
	TWCR = (1<<TWINT)|(1<<TWEN);
	
	/* waiting to finish the writing condition */
	while((TWCR & (1<<TWINT)) == 0);
	
	if(eMode)
	{
		/* waiting until req status is obtained */
		while((TWSR & (0xF8)) != 0x28);
	}
	else
	{
		/* waiting until req status is obtained */
		while((TWSR & (0xF8)) != 0x18);	
	}
}

void I2C_stop(void)
{
	/* setting stop condition */
	TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
}


