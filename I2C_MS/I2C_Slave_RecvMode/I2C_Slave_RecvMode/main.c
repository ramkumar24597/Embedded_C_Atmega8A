/*
 * main.c
 *
 * Created: 7/1/2018 2:16:32 PM
 *  Author: Ram
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>
#include "I2C_Slave_RecvMode.h"

int main(void)
{
	uint8_t data;
	
	/* Initializing I2C Protocol */
	I2C_init(0x20);
	
	while(1)
	{
		//TODO:: Please write your application code
		
		/* Returning slave match ACK */
		I2C_SlaveMatchACK();
		
		/* Reading data from the master */
		data = I2C_ReadData();
	}
}