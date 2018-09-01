/*
 * SPI_REG_BASED.c
 *
 * Created: 8/26/2018 6:17:46 AM
 *  Author: Ram
 */ 

#include "SPI_REG_BASED.h"

void SPI_Init(SpiMode eSpiState)
{	
	/* Define SPI State */
	if(eSpiState == Spi_Slave)
	{
		/* Setting MISO as OUTPUT */
		DDRB = (1<<MISO);
		
		/* Slave SPI Setting */
		SPCR = (1<<SPE);
	}
	else
	{	
		/* Setting SS, MOSI, & SCK as OUTPUT */
		DDRB = (1<<SS)|(1<<MOSI)|(1<<SCK);
		
		/* Master SPI Setting */
		SPCR = (1<<SPE)|(1<<MSTR);
	}
}

void SPI_OperationMode(SpiOpMode eSpiOpMode)
{
	/* Selecting the operation mode of the SPI */
	switch(eSpiOpMode)
	{
		case Mode0:
			/* LOW Idle Line & Rising Edge Data Sampling */ 
			SPCR &= ~(1<<CPOL);
			SPCR &= ~(1<<CPHA);
			break;
		case Mode1:
			/* LOW Idle Line & Falling Edge Data Sampling */
			SPCR &= ~(1<<CPOL);
			SPCR |= (1<<CPHA);
			break;
		case Mode2:
			/* HIGH Idle Line & Falling Edge Data Sampling */
			SPCR |= (1<<CPOL);
			SPCR &= ~(1<<CPHA);
			break;
		case Mode3:
			/* HIGH Idle Line & Rising Edge Data Sampling */
			SPCR |= (1<<CPOL);
			SPCR |= (1<<CPHA);
			break;
		default:
			break;	
	}
}


void SPI_Send(uint8_t Data)
{	
	/* loading Data into the SPI Data register */
	SPDR = Data;
	
	/* Wait until transmission completion */
	while(!(SPSR & (1<<SPIF)));
}

uint8_t SPI_Recv(uint8_t Data)
{
	/* loading Dummy Data into the SPI Data register */
	SPDR = Data;
	
	/* Wait until transmission completion */
	while(!(SPSR & (1<<SPIF)));
	
	return SPDR;
}

