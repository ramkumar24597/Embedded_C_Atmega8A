/*
 * main.c
 *
 * Created: 7/1/2018 2:39:38 PM
 *  Author: Ram
 */ 


#define F_CPU 8000000UL
#include <util/delay.h>
#include "I2C_Master_TransMode.h"

int main(void)
{
	/* Initializing I2C Protocol */
	I2C_init();
	
	while(1)
	{
		//TODO:: Please write your application code
		
		/* Starting the I2C Protocol Sequence */
		I2C_start();
		_delay_ms(100);
		
		/* Writing slave device address */
		I2C_write(WriteAddress, 0x20);
		_delay_ms(100);
		
		/* Writing slave data */
		I2C_write(WriteData, 'B');
		_delay_ms(100);
		
		/* Stopping the I2C Protocol Sequence */
		I2C_stop();
		_delay_ms(100);
	}
}