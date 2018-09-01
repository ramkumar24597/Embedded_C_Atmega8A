/*
 * DIGTEMP_TC72.h
 *
 * Created: 8/26/2018 11:26:05 AM
 *  Author: Ram
 */ 


#ifndef DIGTEMP_TC72_H_
#define DIGTEMP_TC72_H_

#include "System.h"

#define DIGTEMP_CHIPSELECT			1
#define CONFIG_READ_ADDR			0x00
#define LSB_READ_ADDR				0x01
#define MSB_READ_ADDR				0x02
#define MANUFACTURE_ID				0x03
#define CONFIG_WRITE_ADDR			0x80


void DigitalTemp_Init(void);

uint32_t DigitalTemp_Read(void);


#endif /* DIGTEMP_TC72_H_ */