/*
 * LCD.c
 *
 * Created: 6/24/2018 2:41:08 PM
 *  Author: Ram
 */ 


#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "LCD.h"

void LCD_init(void)
{
	/* LCD control bus */
	DDRB |= 0xFF;
	
	/* LCD data bus */
	DDRD |= 0xFF;
	
	/* Initialize the bus to zero */
	PORTB = 0x00;
	PORTD = 0x00;
	
	/* 8bit LCD control */
	LCD_cmd(0x38);
	
	/* Display ON and cursor ON (blinking off) */
	LCD_cmd(0x0E);
	
	/* clear last print */
	LCD_cmd(0x01);
	
	_delay_ms(5);
}

void LCD_cmd(uint8_t command)
{
	/* set LCD into the command reg mode & disabling the LCD enable pin*/	
	PORTB = (0<<PORTB0)|(1<<PORTB2);
	_delay_ms(5);
	
	/* Loading command into the PORTD */
	PORTD = command;
	
	/* Keeping LCD into the command reg mode & latching command to LCD using enable */
	PORTB = (0<<PORTB0)|(0<<PORTB2);
	_delay_ms(5);
}

void LCD_data(uint8_t data)
{
	/* set LCD into the data reg mode & disabling the LCD enable pin*/
	PORTB = (1<<PORTB0)|(1<<PORTB2);
	_delay_ms(5);
	
	/* Loading data into the PORTD */
	PORTD = data;

	/* Keeping LCD into the data reg mode & latching data to LCD using enable */
	PORTB = (1<<PORTB0)|(0<<PORTB2);
	_delay_ms(5);
}

void LCD_print(int line_no, char *info)
{
	int i;
	
	/* clear last print */
//	LCD_cmd(0x01);
	
	if(line_no == 1)
	{
		/* cursor to first row of LCD */
		LCD_cmd(0x80);
	}
	else
	{
		/* cursor to second row of LCD */
		LCD_cmd(0xC0);	
	}

	for(i=0;info[i] != 0;i++)
	{
		LCD_data(info[i]);
	}	
}
