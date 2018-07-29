/*
 * I2C_BitBanging.c
 *
 * Created: 7/22/2018 11:40:11 AM
 *  Author: Ram
 */ 


#include <avr/io.h>
#include "I2C_BitBanging.h"
#define F_CPU 8000000
#include <util/delay.h>

void I2C_init(void)
{
	/* Initializing I2C SCL */
	SCL_HIGH;
	SCL_OUTPUT;
	
	/* Initializing I2C SDA */
	SDA_HIGH;
	SDA_OUTPUT;
}

void I2C_start(void)
{
	/* Set I2C SDA as OUTPUT */
	SDA_OUTPUT;
	
	/* Set SCL & SDA HIGH */
	SCL_HIGH;
	SDA_HIGH;
	
	/* Set SCL & SDA LOW */
	SDA_LOW;
	SCL_LOW;
}

void I2C_write(WriteMode eMode, uint8_t data)
{
	int bitcounter;
	
	/* Set I2C SDA as OUTPUT */
	SDA_OUTPUT;
	
	/* Make LSB as 1 in case read from slave */
	if(eMode == ReadAddress)
	{
		data |= 1;
	}

	/* Send Data starts from MSB to LSB */
	for(bitcounter=0; bitcounter<8; bitcounter++)
	{
		/* Format SDA Line as per Data */
		if((data & 0x80))
		{
			SDA_HIGH;
		}
		else
		{
			SDA_LOW;
		}
		
		/* Do one clock transaction */
		SCL_HIGH;
		SCL_LOW;	
		data <<= 1;
	}
	
	/* Set SDA to LOW in case if the last bit is one to make line availble for slave */
	if((PORTC & 0x10))
	{
		SDA_LOW;
	}

	/* check for ACK */
	SCL_HIGH;
	while((PORTC & 0x10));
	SCL_LOW;
}

unsigned char I2C_Read(AckReturn eAckType)
{	
	int bitcounter;
	unsigned char Data = 0x00;
	
	/* Set I2C SDA as INPUT */
	SDA_INPUT;
	
	/* Read Data starts from MSB to LSB */
	for(bitcounter=0; bitcounter<8; bitcounter++)
	{
		Data <<= 1;
		SCL_HIGH;
		
		if((INPUT_PIN & 0x10))
		{
			Data |= 1;
		}
		else
		{
			Data |= 0;
		}
		
		SCL_LOW;
	}
	
	/* Send ACK or NACK depending upon the situation */
	if(eAckType == ACK)
	{
		I2C_ACK();
	}
	else if(eAckType == NACK)
	{
		I2C_NACK();
	}
	
	return Data;
}

void I2C_stop(void)
{
	/* Set I2C SDA as OUTPUT */
	SDA_OUTPUT;
	
	/* Set SCL & SDA LOW */
	SCL_LOW;
	SDA_LOW;	
	
	/* Set SCL & SDA HIGH */
	SCL_HIGH;
	SDA_HIGH;
}


void I2C_ACK(void)
{
	/* Set I2C SDA as OUTPUT */
	SDA_OUTPUT;
	
	/* Set SDA to HIGH to make ACK */
	SDA_LOW;
	
	/* Do one clock transaction */
	SCL_HIGH;
	SCL_LOW;
}

void I2C_NACK(void)
{
	/* Set I2C SDA as OUTPUT */
	SDA_OUTPUT;
	
	/* Set SDA to HIGH to make NACK */
	SDA_HIGH;
	
	/* Do one clock transaction */
	SCL_HIGH;
	SCL_LOW;
}