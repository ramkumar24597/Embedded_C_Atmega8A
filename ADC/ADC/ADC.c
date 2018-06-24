/*
 * ADC.c
 *
 * Created: 6/24/2018 12:38:43 PM
 *  Author: Ram
 */ 


#include <avr/io.h>
#include "ADC.h"

void ADC_init(void)
{
	/* Selecting Reference Voltage */
	ADMUX = (0<<REFS0);
	
	/* Enabling ADC & configuring ADC pre-scalar */
	ADCSRA = (1<<ADEN)|(1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2);
}

uint16_t ADC_read(uint8_t channel)
{
	/* setting bit 7-3 to 0 */
	channel &= 0b00000111;
	
	/* selecting ADC channel */
	ADMUX = (ADMUX & 0xF8)|channel;
	
	/* ADC starting conversion */
	ADCSRA |= (1<<ADSC);
	
	/* wait until conversion full */
	while(ADCSRA & (1<<ADSC));

	return ADC;
}