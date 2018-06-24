/*
 * UART.c
 *
 * Created: 6/24/2018 7:33:58 PM
 *  Author: Ram
 */ 


#include <avr/io.h>
#include "UART.h"
#define F_CPU 8000000UL

void UART_init(uint16_t BaudRate, bool DoubleBaudRate)
{
	uint16_t BaudRegValue;
	
	if(DoubleBaudRate)
	{
		UCSRA = (1<<U2X);
		
		BaudRegValue = ((F_CPU)/(BaudRate*8UL)-1);
		
	}
	else
	{
		/* Not necessary to do it, bcoz it is initially zero */
		UCSRA = (0<<U2X);
		
		BaudRegValue = ((F_CPU)/(BaudRate*16UL)-1);
	}
	
	UCSRB = (1<<RXEN)|(1<<TXEN);
	UCSRC = (1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
	UBRRH = (BaudRegValue>>8);
	UBRRL = BaudRegValue;
}

void UART_tx(uint8_t txdata)
{
	while(!(UCSRA & (1<<UDRE)));
	UDR = txdata;
}

uint8_t UART_rx(void)
{
	while(!(UCSRA & (1<<RXC)));
	return UDR;
}

void UART_write(char * DataBuffer)
{
	int i;
	
	for(i=0;DataBuffer[i]!='\0';i++)
	{
		UART_tx(DataBuffer[i]);
	}
}
