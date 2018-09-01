/*
 * SPI_Slave_Mode.c
 *
 * Created: 8/25/2018 3:35:32 PM
 *  Author: Ram
 */ 


#include <avr/io.h>
#include "SPI_Slave_Mode.h"

void SPI_Init(void)
{
	/* Set MISO as Output */
	DDRB = (1<<MISO);
	
	/* Enable SPI, Set as Slave*/
	SPCR = (1<<SPE);
}

void SPI_Send(uint8_t ReturnData)
{
	/* Load the 8-Bit data into the Data register */
	SPDR = ReturnData;
	
	/* wait for transmission to complete */
	while(!(SPSR & (1 << SPIF)));
}

uint8_t SPI_Recv(void)
{
	/* return 8-bit data of the spi data register */
	return SPDR;
}
