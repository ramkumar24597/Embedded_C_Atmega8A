/*
 * EEPROM_25AA256.c
 *
 * Created: 8/26/2018 11:46:35 AM
 *  Author: Ram
 */ 


#include "SPI_REG_BASED.h"
#include "EEPROM_25AA256.h"

void EEPROM_Init(void)
{
	/* Make & Configure Chip Select pin for EEPROM */
	DDRB |= (1<<EEPROM_CHIPSELECT);
	PORTB |= (1<<EEPROM_CHIPSELECT);
}

void EEPROM_Write(uint16_t address, uint32_t Data)
{
	/* Set Write-Enable-Latch bit */
	PORTB &= ~(1<<EEPROM_CHIPSELECT);		// PORTB.0 to LOW to select the EEPROM
	SPI_Send(WREN);
	PORTB |= (1<<EEPROM_CHIPSELECT);		// PORTB.0 to HIGH to de-select the EEPROM
	_delay_ms(100);
	
	/* Read Status Register (for Verification) */
	PORTB &= ~(1<<EEPROM_CHIPSELECT);
	SPI_Send(RDSR);
	SPI_Recv(0xFF);
	PORTB |= (1<<EEPROM_CHIPSELECT);
	_delay_ms(100);
	
	/* Write the Data */
	PORTB &= ~(1<<EEPROM_CHIPSELECT);
	SPI_Send(WRITE);
	SPI_Send(address >> 8);
	SPI_Send(address);
	SPI_Send(Data >> 16);
	SPI_Send(Data >> 8);
	SPI_Send(Data);
	PORTB |= (1<<EEPROM_CHIPSELECT);
	_delay_ms(100);
	
	/* Read Status Register (for Verification) */
	PORTB &= ~(1<<EEPROM_CHIPSELECT);
	SPI_Send(RDSR);
	SPI_Recv(0xFF);
	PORTB |= (1<<EEPROM_CHIPSELECT);
	_delay_ms(100);
}

uint32_t EEPROM_Read(uint16_t address)
{
	uint32_t ReadData;
	
	/* Read the Data */
	PORTB &= ~(1<<EEPROM_CHIPSELECT);
	SPI_Send(READ);
	SPI_Send(address >> 8);
	SPI_Send(address);
	ReadData = SPI_Recv(0xFF);
	ReadData = (ReadData << 8);
	ReadData |= SPI_Recv(0xFF);
	ReadData = (ReadData << 8);
	ReadData |= SPI_Recv(0xFF);
	PORTB |= (1<<EEPROM_CHIPSELECT);
	_delay_ms(100);
	
	return ReadData;
}
