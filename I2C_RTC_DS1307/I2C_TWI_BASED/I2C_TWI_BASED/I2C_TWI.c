/*
 * I2C_TWI.c
 *
 * Created: 7/22/2018 6:12:15 AM
 *  Author: Ram
 */ 


#include <avr/io.h>
#include "I2C_TWI.h"

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
	
	if(eMode == ReadAddress)
	{
		TWDR |= 0x01;
	}
	
	/* Enabling transfer */
	TWCR = (1<<TWINT)|(1<<TWEN);
	
	/* waiting to finish the writing condition */
	while((TWCR & (1<<TWINT)) == 0);
	
	if(eMode == WriteAddress)
	{
		/* waiting until req status is obtained (Write Address ACK status) */
		while((TWSR & (0xF8)) != 0x18);
	}
	else if(eMode == ReadAddress)
	{
		/* waiting until req status is obtained (Read Address ACK status) */
		while((TWSR & (0xF8)) != 0x40);
	}
	else
	{
		/* waiting until req status is obtained (Write Data ACK status) */
		while((TWSR & (0xF8)) != 0x28);
	}
}

unsigned char I2C_Read(AckReturn eAckType)
{
	uint8_t recvdata;
	
	if(eAckType == ACK)
	{
		/* Enabling transfer */
		TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
		
		/* waiting to finish the reading condition */
		while((TWCR & (1<<TWINT)) == 0);
		
		/* waiting until req status is obtained (Read Data ACK status) */
		while((TWSR & (0xF8)) != 0x50);
	}
	else if(eAckType == NACK)
	{
		/* Enabling transfer */
		TWCR = (1<<TWINT)|(1<<TWEN);
		
		/* waiting to finish the reading condition */
		while((TWCR & (1<<TWINT)) == 0);
		
		/* waiting until req status is obtained (Last Read Data Byte NACK status) */
		while((TWSR & (0xF8)) != 0x58);
	}
	
	/* getting data from the data buffer */
	recvdata = TWDR;
	
	return recvdata;
}

void I2C_stop(void)
{
	/* setting stop condition */
	TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
}
