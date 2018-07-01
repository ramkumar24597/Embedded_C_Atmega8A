/*
 * main.c
 *
 * Created: 7/1/2018 4:15:38 PM
 *  Author: Ram
 */ 


#include "I2C_Master_RecvMode.h"
#define F_CPU 8000000UL
#include <util/delay.h>


int main(void)
{
	uint8_t data;
	
	/* Initializing I2C Protocol */
	I2C_init();
	
	while(1)
	{
		//TODO:: Please write your application code
		
		/* Starting the I2C Protocol Sequence */
		I2C_start();
		_delay_ms(100);
		
		/* Writing slave device address */
		I2C_write(0x21);
		_delay_ms(100);
		
		/* Reading data from the slave device whose address is 0x21 */
		data = I2C_Read();
		_delay_ms(100);
		
		/* Stopping the I2C Protocol Sequence */
		I2C_stop();
		_delay_ms(100);
	}
}