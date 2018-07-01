/*
 * I2C_Master_RecvMode.c
 *
 * Created: 7/1/2018 4:13:49 PM
 *  Author: Ram
 */ 


#include <avr/io.h>
#include "I2C_Master_RecvMode.h"

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

void I2C_write(uint8_t slave_address)
{
	/* storing slave address to the data buffer */
	TWDR = slave_address;
	
	/* Enabling transfer */
	TWCR = (1<<TWINT)|(1<<TWEN);
	
	/* waiting to finish the writing condition */
	while((TWCR & (1<<TWINT)) == 0);
	
	/* waiting until req status is obtained */
	while((TWSR & (0xF8)) != 0x40);
}

unsigned char I2C_Read(void)
{
	uint8_t recvdata;
	
	/* Enabling transfer */
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	
	/* waiting to finish the reading condition */
	while((TWCR & (1<<TWINT)) == 0);
	
	/* waiting until req status is obtained */
	while((TWSR & (0xF8)) != 0x50);
	
	/* getting data from the data buffer */
	recvdata = TWDR;
	
	return recvdata;
}

void I2C_stop(void)
{
	/* setting stop condition */
	TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
}

