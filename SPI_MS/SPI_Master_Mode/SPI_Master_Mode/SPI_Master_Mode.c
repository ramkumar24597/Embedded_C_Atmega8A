/*
 * SPI_Master_Mode.c
 *
 * Created: 8/25/2018 1:22:32 PM
 *  Author: Ram
 */ 


#include <avr/io.h>
#include "SPI_Master_Mode.h"

void SPI_Init(void)
{
	/* Set MOSI, SCK as Output */
	DDRB = (1<<MOSI)|(1<<SS)|(1<<SCK);
	
	/* Enable SPI, Set as Master, Pre-scaler: Fosc/16 */
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}

void SPI_Send(uint8_t Data)
{
	/* Pull down the SS line to make the slave ready for transmission */
	PORTB = (0<<SS);
	
	/* Load the 8-Bit data into the Data register */
	SPDR = Data;
	
	/* wait for transmission to complete */
	while(!(SPSR & (1 << SPIF)));
}

uint8_t SPI_Recv(void)
{
	/* return 8-bit data of the spi data register */
	return SPDR;
}
