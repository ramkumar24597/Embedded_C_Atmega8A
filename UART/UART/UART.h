/*
 * UART.h
 *
 * Created: 6/24/2018 7:35:16 PM
 *  Author: Ram
 */ 


#ifndef UART_H_
#define UART_H_

#include <avr/io.h>
#include <stdbool.h>

void UART_init(uint16_t BaudRate, bool DoubleBaudRate);

void UART_tx(uint8_t txdata);

uint8_t UART_rx(void);

void UART_write(char * DataBuffer);

#endif /* UART_H_ */