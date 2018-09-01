/*
 * DIGTEMP_TC72.c
 *
 * Created: 8/26/2018 11:25:47 AM
 *  Author: Ram
 */ 


#include "SPI_REG_BASED.h"
#include "DIGTEMP_TC72.h"

void DigitalTemp_Init(void)
{
	/* Make & Configure Chip Select pin for DIGTEMP */
	DDRB |= (1<<DIGTEMP_CHIPSELECT);
	PORTB &= ~(1<<DIGTEMP_CHIPSELECT);
	_delay_ms(100);
	
	/* Configure the sensor settings */
	PORTB |= (1<<DIGTEMP_CHIPSELECT);		// PORTB.1 to HIGH to select the Digital Temp Sensor
	SPI_Send(0x80);
	SPI_Send(0x04);
	PORTB &= ~(1<<DIGTEMP_CHIPSELECT);		// PORTB.1 to LOW to De-select the Digital Temp Sensor
	_delay_ms(100);
}

uint32_t DigitalTemp_Read(void)
{
	uint32_t RecvData;
	
	/* Read the Temperature in order of MSB, LSB, & Config */
	PORTB |= (1<<DIGTEMP_CHIPSELECT);
	SPI_Send(MSB_READ_ADDR);
	RecvData = SPI_Recv(0xFF);
	RecvData = RecvData << 8;
	RecvData |= SPI_Recv(0xFF);
	RecvData = RecvData << 8;
	RecvData |= SPI_Recv(0xFF);
	PORTB &= ~(1<<DIGTEMP_CHIPSELECT);
	
	return RecvData;
}