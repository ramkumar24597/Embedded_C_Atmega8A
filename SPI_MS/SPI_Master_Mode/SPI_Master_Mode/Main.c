/*
 * Main.c
 *
 * Created: 8/25/2018 1:23:06 PM
 *  Author: Ram
 */ 

#include "SPI_Master_Mode.h"
#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{
	uint8_t RecvData;
	
	/* Set PORTD as Output */
	DDRD = 0xFF;
	
	/* Initializing SPI Protocol */
	SPI_Init();
	
	while(1)
	{
		//TODO:: Please write your application code
		/* Transmit data to the SPI lines */
		SPI_Send(0x60);
		
		/* Recv data to the SPI lines */
		RecvData = SPI_Recv();
		PORTD = RecvData;
		
		_delay_ms(1000);
	}
}