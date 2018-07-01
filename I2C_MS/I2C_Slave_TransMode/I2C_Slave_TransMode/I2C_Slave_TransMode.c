/*
 * I2C_Slave_TransMode.c
 *
 * Created: 7/1/2018 4:17:57 PM
 *  Author: Ram
 */ 


#include <avr/io.h>
#include "I2C_Slave_TransMode.h"


void I2C_init(void)
{
	/* defining this slave address 0b0010 000X X-define general call */
	TWAR = 0x20;
}

void I2C_SlaveMatchACK(void)
{
	/* Enabling transfer */
	TWCR = (1<<TWEN)|(1<<TWEA);
	
	/* waiting until req status is obtained */
	while((TWSR & (0xF8)) != 0xA8);
}

void I2C_write(uint8_t data)
{
	/* storing data to the data buffer */
	TWDR = data;
	
	/* Enabling transfer */
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	
	/* waiting to finish the writing condition */
	while((TWCR & (1<<TWINT)) == 0);
	
	/* waiting until req status is obtained */
	while((TWSR & (0xF8)) != 0xA8);
}

