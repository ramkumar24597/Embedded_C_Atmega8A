/*
 * main.c
 *
 * Created: 7/21/2018 2:49:31 PM
 *  Author: Ram
 */ 

#include "I2C_BitBanging.h"
#include "DS1307.h"
#include "LCD.h"
#include <string.h>
#define F_CPU 8000000
#include <util/delay.h>

int main(void)
{
	DataDateTime SetDateTime;
	DataDateTime GetDateTime;
	
	/* Initializing LCD */
	LCD_init();
	
	/* Initializing I2C Module */
	I2C_init();
	
	/* Set the current date, day and time */
	strcpy((char*)SetDateTime.Time, "11:59:55 PM");
//	strcpy((char*)SetDateTime.Time, "23:59:55");
	strcpy((char*)SetDateTime.Date, "26-07-18");
	SetDateTime.eDay = Sunday;

	/* Writing current Date, Day and Time into RTC */
	DS1307_Write(SetDateTime);
	
	while(1)
	{
		/* Reading Date and Time from RTC */
		GetDateTime = DS1307_Read();
		
		/* Printing the result into LCD */
		LCD_print(1, (char*)GetDateTime.Time);
		LCD_print(2, (char*)GetDateTime.Date);
		_delay_ms(3000);
	}
}

