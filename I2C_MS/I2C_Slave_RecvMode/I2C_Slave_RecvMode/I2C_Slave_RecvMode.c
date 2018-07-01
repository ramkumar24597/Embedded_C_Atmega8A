/*
 * I2C_Slave_RecvMode.c
 *
 * Created: 7/1/2018 2:15:44 PM
 *  Author: Ram
 */


#include <avr/io.h>
#include "I2C_Slave_RecvMode.h"
#define F_CPU 8000000UL
#include <util/delay.h>

void I2C_init(uint8_t slave_address)
{
	/* defining this slave address */
	TWAR = slave_address;
}

void I2C_SlaveMatchACK(void)
{
	/* Enabling transfer */
	TWCR = (1<<TWEN)|(1<<TWEA);
	
	/* waiting until req status is obtained */
	while((TWSR & (0xF8)) != 0x60);
}

unsigned char I2C_ReadData(void)
{
	uint8_t recvdata;
	
	/* Enabling transfer */
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	
	/* waiting to finish the reading condition */
	while((TWCR & (1<<TWINT)) == 0);
	
	/* waiting until req status is obtained */
	while((TWSR & (0xF8)) != 0x80);
	
	/* getting data from the data buffer */
	recvdata = TWDR;
	
	return recvdata;
}


