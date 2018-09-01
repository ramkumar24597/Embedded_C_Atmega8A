/*
 * Main.c
 *
 * Created: 8/26/2018 6:24:19 AM
 *  Author: Ram
 */ 


#include "System.h"
#include "DIGTEMP_TC72.h"
#include "SPI_REG_BASED.h"
#include "EEPROM_25AA256.h"


int main(void)
{
	uint32_t DigitalTemperatureData = 55;
	uint16_t Eeprom_Address = 0;
	
	/* Initializing SPI Protocol as Master */
	SPI_Init(Spi_Master);
	_delay_ms(100);
			
	/* Select SPI operation mode into CPOL = 1 (High Idle Line) & CPHA = 1 (Sample on Rising edge) */
	SPI_OperationMode(Mode3);
	_delay_ms(100);
	
	/* Initializing Digital Temperature Sensor */
	DigitalTemp_Init();
	_delay_ms(100);
	
	/* Initializing 256-kbit EEPROM */
	EEPROM_Init();
	_delay_ms(100);
	
	while(1)
	{
		//TODO:: Please write your application code
		/* Reading Temperature */
		DigitalTemperatureData = DigitalTemp_Read();
		_delay_ms(1000);
		
		/* Write the Temperature Data into the EEPROM */
		EEPROM_Write(Eeprom_Address, DigitalTemperatureData);
		_delay_ms(1000);
		
		/* Read the data on the wrote address (For Verification) */
		EEPROM_Read(Eeprom_Address);
		_delay_ms(1000);
		
		Eeprom_Address += 3;
	}
}
