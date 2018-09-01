/*
 * EEPROM_25AA256.h
 *
 * Created: 8/26/2018 11:46:15 AM
 *  Author: Ram
 */ 


#ifndef EEPROM_25AA256_H_
#define EEPROM_25AA256_H_

#include "System.h"

#define EEPROM_CHIPSELECT		0
#define WRITE					0x02
#define READ					0x03
#define RDSR					0x05
#define WREN					0x06


void EEPROM_Init(void);

void EEPROM_Write(uint16_t address, uint32_t Data);

uint32_t EEPROM_Read(uint16_t address);


#endif /* EEPROM_25AA256_H_ */