/*
 * main.c
 *
 * Created: 6/24/2018 7:34:24 PM
 *  Author: Ram
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>
#include "UART.h"
#define BAUDRATE 9600

int main(void)
{	
	char data;
	
	UART_init(BAUDRATE, false);
	
	UART_write("Hello its Ram here..");
	_delay_ms(100);
	
	while(1)
	{
		//TODO:: Please write your application code
		data = UART_rx();
		UART_tx(data);
	}
}