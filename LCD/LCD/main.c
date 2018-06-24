/*
 * main.c
 *
 * Created: 6/24/2018 5:25:18 PM
 *  Author: Ram
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>
#include "LCD.h"

int main(void)
{
	/* Initializing LCD */
	LCD_init();
	
	while(1)
	{
		//TODO:: Please write your application code
		
		LCD_print(1, "Ram Kumar D");
		_delay_ms(1000);
		LCD_print(2, "EmbeddedEngineer");
		_delay_ms(1000);
	}
}