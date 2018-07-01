/*
 * main.c
 *
 * Created: 7/1/2018 4:18:26 PM
 *  Author: Ram
 */ 


#include "I2C_Slave_TransMode.h"
#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{
	/* Initializing I2C Protocol */
	I2C_init();
	
	while(1)
	{
		//TODO:: Please write your application code
		
		/* Returning slave match ACK */
		I2C_SlaveMatchACK();
		
		/* Reading data from the master */
		I2C_write('C');
	}
}

