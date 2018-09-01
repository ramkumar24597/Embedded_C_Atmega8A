/*
 * SPI_Master_Mode.h
 *
 * Created: 8/25/2018 1:22:53 PM
 *  Author: Ram
 */ 


#ifndef SPI_MASTER_MODE_H_
#define SPI_MASTER_MODE_H_

#include <stdint.h>

#define SS	2
#define MOSI	3
#define SCK		5


void SPI_Init(void);

void SPI_Send(uint8_t Data);

uint8_t SPI_Recv(void);


#endif /* SPI_MASTER_MODE_H_ */