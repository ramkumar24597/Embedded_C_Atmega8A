/*
 * Timer__CTC_Mode_.c
 *
 * Created: 6/10/2018 3:58:17 PM
 *  Author: Ram
 *	Info : CTC Mode only avails on Timer1 and Timer2, not on Timer0
 *
 */


#include <avr/io.h>

#define F_CPU 8000000UL

static void Timer1AB_ICR_Init(void)
{
	/* Timer1 is configured in CTC mode using ICR1 */
	TCCR1A |= (0<<WGM11)|(0<<WGM10)|(1<<COM1A0)|(1<<COM1B0);
	TCCR1B |= (1<<WGM13)|(1<<WGM12)|(1<<CS10);
	
	/* Initialize Timer1 */
	TCNT1 = 0;
	
	/* Here, the Compare Reg is OCR */
	ICR1 = 0x3FFF;
	
	/* Set OC1A & OC1B as Output */
	DDRB = (1<<PB1)|(1<<PB2);
}

static void Timer1AB_OCR_Init(void)
{
	/* Timer1 is configured in CTC mode using OCR */
	TCCR1A |= (0<<WGM11)|(0<<WGM10)|(1<<COM1A0)|(1<<COM1B0);
	TCCR1B |= (0<<WGM13)|(1<<WGM12)|(1<<CS10);
	
	/* Initialize Timer1 */
	TCNT1 = 0;
	
	/* Here, the Compare Reg is OCR */
	OCR1A = 0x7FFF;

	/* Set OC1B as Output */
	DDRB = (1<<PB1)|(1<<PB2);
}

static void Timer2_Init(void)
{
	/* Timer2 is configured to CTC mode */
	TCCR2 |= (1<<WGM21)|(0<<WGM20)|(1<<COM20)|(1<<CS22)|(1<<CS21)|(1<<CS20);
	
	/* Initialize Timer2 */
	TCNT2 = 0;
	
	/* Set Time Limit to toggle */
	OCR2 = 64;
	
	/* Set OC2 as Output */
	DDRB = (1<<PB3);
}

int main(void)
{
	/* Anyone of the mode should be enabled at a time */
//	Timer1AB_ICR_Init();
	Timer1AB_OCR_Init();
//	Timer2_Init();
	
	while(1)
	{
		//TODO:: Please write your application code
	}
}