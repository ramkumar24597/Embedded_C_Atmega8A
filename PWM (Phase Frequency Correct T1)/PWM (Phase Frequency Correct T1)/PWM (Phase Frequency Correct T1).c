/*
 * PWM__Phase_Frequency_Correct_T1_.c
 *
 * Created: 6/5/2018 8:46:02 AM
 *  Author: Ram
 *	Info : Phase Correct Mode 
 *	-->	ATMEGA8A doesn't have any OCR Register for timer0, but in timer1 and timer2 it do have those registers
 *	
 */ 


#include <avr/io.h>

#define F_CPU 8000000UL

int flag;

static void PWM1AB_Init(void)
{
	/* Phase & Freq Correct PWM Mode using ICR1 in Timer1 */
	TCCR1A |= (0<<WGM11)|(0<<WGM10)|(1<<COM1A1)|(1<<COM1B1);
	TCCR1B |= (1<<WGM13)|(0<<WGM12)|(1<<CS10);
	
	/* Here, the Compare Reg is ICR1 */
	ICR1 = 0xFFFF;
	DDRB |= (1<<PB1)|(1<<PB2);
	
	flag = 1;
	
}

static void PWM1B_Init(void)
{
	/* Phase & Freq Correct PWM Mode using OCR in Timer1 */
	/* Only OC1A cannot be accessible in this OCR mode */
	TCCR1A |= (0<<WGM11)|(1<<WGM10)|(1<<COM1B1);
	TCCR1B |= (1<<WGM13)|(0<<WGM12)|(1<<CS10);
	
	/* Here, the Compare Reg is OCR1A */
	OCR1A = 0xFFFF;
	DDRB |= (1<<PB2);
	
	flag = 0;
}

int main(void)
{
	uint16_t PWM1A_DutyCycle;
	uint16_t PWM1B_DutyCycle;
	
	/* Only one mode is enabled at a time either PWM1AB or PWM1B */
	PWM1AB_Init();
//	PWM1B_Init();
	
	if(flag)
	{
		PWM1A_DutyCycle = 0x3FFF;
		PWM1B_DutyCycle = 0x5FFF;
		
		OCR1A = PWM1A_DutyCycle;
		OCR1B = PWM1B_DutyCycle;
	}
	else
	{
		PWM1B_DutyCycle = 0x3FFF;
		OCR1B = PWM1B_DutyCycle;
	}

    while(1)
    {
        //TODO:: Please write your application code 
		
    }
}