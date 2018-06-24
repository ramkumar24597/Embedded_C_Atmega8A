/*
 * PWM__Fast_PWM_Mode_.c
 *
 * Created: 6/5/2018 8:46:02 AM
 *  Author: Ram
 *	Info : Fast PWM Mode 
 *	-->	ATMEGA8A doesn't have any OCR Register for timer0, but in timer1 and timer2 it do have those registers
 *	
 */ 


#include <avr/io.h>

#define F_CPU 8000000UL

int flag;

static void PWM1AB_Init(void)
{
	/* Fast PWM Mode using ICR in Timer 1 */
	/* both OC1A and OC1B are accessible in this mode */
	TCCR1A |= (1<<WGM11)|(0<<WGM10)|(1<<COM1A1)|(1<<COM1B1);
	TCCR1B |= (1<<WGM13)|(1<<WGM12)|(1<<CS10);
	
	/* Here, Compare Reg is ICR1 */
	ICR1 = 0xFFFF;
	DDRB |= (1<<PB1)|(1<<PB2);
	
	flag = 1;
}

static void PWM1B_Init(void)
{
	/* Fast PWM Mode using OCR in Timer 1 */
	/* In this Mode OC1A cannot be accessible */
	TCCR1A |= (1<<WGM11)|(1<<WGM10)|(1<<COM1B1);
	TCCR1B |= (1<<WGM13)|(1<<WGM12)|(1<<CS10);
	
	/* Here, Compare Reg is OCR1A */
	OCR1A = 0xFFFF;
	DDRB |= (1<<PB2);
	
	flag = 0;
}

static void PWM2_Init(void)
{
	/* Fast PWM Mode using OCR in Timer 2 */
	TCCR2 |= (1<<WGM20)|(1<<COM21)|(1<<WGM21)|(1<<CS22)|(1<<CS21)|(1<<CS20);
	
	DDRB |= (1<<PB3);
}


int main(void)
{
	uint16_t PWM1A_DutyCycle;
	uint16_t PWM1B_DutyCycle;
	uint8_t PWM2_DutyCycle;
	
	/* Anyone One of the Mode should be active at a time PWM1AB or PWM1B */
	PWM1AB_Init();
//	PWM1B_Init();
	
	PWM2_Init();
	
	if(flag)
	{
		PWM1A_DutyCycle = 0x3FFF;
		PWM1B_DutyCycle = 0x6FFF;
		
		OCR1A = PWM1A_DutyCycle;
		OCR1B = PWM1B_DutyCycle;
	}
	else
	{
		PWM1B_DutyCycle = 0x3FFF;
		OCR1B = PWM1B_DutyCycle;
	}
	
	PWM2_DutyCycle = 64;
	OCR2 = PWM2_DutyCycle;
	
    while(1)
    {
        //TODO:: Please write your application code 
		
    }
}