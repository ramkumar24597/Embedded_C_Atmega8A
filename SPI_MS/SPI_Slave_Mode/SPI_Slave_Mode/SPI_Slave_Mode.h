/*
 * SPI_Slave_Mode.h
 *
 * Created: 8/25/2018 3:36:16 PM
 *  Author: Ram
 */ 


#ifndef SPI_SLAVE_MODE_H_
#define SPI_SLAVE_MODE_H_

#include <stdint.h>

#define MISO	4


void SPI_Init(void);

void SPI_Send(uint8_t ReturnData);

uint8_t SPI_Recv(void);


#endif /* SPI_SLAVE_MODE_H_ */