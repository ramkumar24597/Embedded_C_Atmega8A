/*
 * SPI_REG_BASED.h
 *
 * Created: 8/26/2018 6:24:42 AM
 *  Author: Ram
 */ 


#ifndef SPI_REG_BASED_H_
#define SPI_REG_BASED_H_

#include "System.h"

#define SS		2
#define MOSI	3
#define MISO	4
#define SCK		5

typedef enum
{
	Spi_Master,
	Spi_Slave
	
} SpiMode;

typedef enum
{
	Mode0,
	Mode1,
	Mode2,
	Mode3
	
} SpiOpMode;

typedef enum
{
	ChipSelect,
	ChipDeselect
	
} ChipMode;

void SPI_Init(SpiMode State);

void SPI_OperationMode(SpiOpMode eSpiOpMode);

void SPI_Send(uint8_t Data);

uint8_t SPI_Recv(uint8_t Data);


#endif /* SPI_REG_BASED_H_ */