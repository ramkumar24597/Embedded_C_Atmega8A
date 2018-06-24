/*
 * main.c
 *
 * Created: 6/24/2018 5:25:18 PM
 *  Author: Ram
 */ 

#include <stdlib.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "ADC.h"
#include "LCD.h"

int main(void)
{
	uint16_t ADC_Result;
	char data[10];
	
	/* Initializing ADC */
	ADC_init();
	
	/* Initializing LCD */
	LCD_init();
	
	while(1)
	{
		//TODO:: Please write your application code
		
		/* Read ADC value respective channel */
		ADC_Result = ADC_read(0);
		
		/* integer to string conversion */
		itoa(ADC_Result, data, 10);
		
		/* printing in LCD */
		LCD_print(1, data);
		
		_delay_ms(1000);
	}
}