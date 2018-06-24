/*
 * ADC.h
 *
 * Created: 6/24/2018 5:16:59 PM
 *  Author: Ram
 */ 


#ifndef ADC_H_
#define ADC_H_

void ADC_init(void);

uint16_t ADC_read(uint8_t channel);

#endif /* ADC_H_ */