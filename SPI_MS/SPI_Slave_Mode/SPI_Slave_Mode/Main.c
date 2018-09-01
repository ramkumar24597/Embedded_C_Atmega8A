/*
 * Main.c
 *
 * Created: 8/25/2018 3:35:52 PM
 *  Author: Ram
 */ 


#include "SPI_Slave_Mode.h"
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
		/* Recv data to the SPI lines */
		RecvData = SPI_Recv();
		PORTD = RecvData;
		
		RecvData = ~RecvData;
		/* Transmit data to the SPI lines */
		SPI_Send(RecvData);
	}
}