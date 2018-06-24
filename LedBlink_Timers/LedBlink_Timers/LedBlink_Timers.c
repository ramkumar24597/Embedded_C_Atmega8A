/*
 * LedBlink_Timers.c
 *
 * Created: 5/26/2018 6:59:30 PM
 *  Author: Ram
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 8000000UL

static void timer0_init(void);
static void timer1_init(void);
static void timer2_init(void);
static void board_io(void);

volatile uint8_t timer0_overflow;
volatile uint8_t timer2_overflow;

ISR(TIMER0_OVF_vect)
{
	// keep a track of number of overflows
	timer0_overflow++;	
}

ISR(TIMER2_OVF_vect)
{
	// keep a track of number of overflows
	timer2_overflow++;
}

int main(void)
{
	board_io();
	timer0_init();
	timer1_init();
	timer2_init();
	sei();
		
    while(1)
    {
		int i=0;
        //TODO:: Please write your application code 
		if(bit_is_clear(PINC,0))
		{
			timer0_overflow = 0;
			while(i<4)
			{
				if(timer0_overflow >= 61)
				{
					PORTC ^=  1 << 3;
					TCNT0 = 0;
					timer0_overflow = 0;
					i++;
				}	
			}
		}
		else if(bit_is_clear(PINC,1))
		{
			while(i<4)
			{
				if(TCNT1 >= 62500)
				{
					PORTC ^= 1 << 4;
					TCNT1 = 0;
					i++;
				}
			}
		}
		else if(bit_is_clear(PINC,2))
		{
			timer2_overflow = 0;
			while(i<4)
			{
				if(timer2_overflow >= 61)
				{
					PORTC ^=  1 << 5;
					TCNT2 = 0;
					timer2_overflow = 0;
					i++;
				}
			}
		}
    }
}

static void board_io(void)
{
	DDRC = 0b11111000;
	PORTC = 0b00000111;	
}

static void timer0_init(void)
{
	TCCR0 |= (5 << CS00)|(1 << CS02);
	TCNT0 = 0;
	TIMSK |= 1 << TOIE0; 
	timer0_overflow = 0;
}

static void timer1_init(void)
{
	TCCR1B |= 1 << CS12;
	TCNT1 = 0;
}

static void timer2_init(void)
{
	TCCR2 |= (1 << CS20)|(1 << CS21)|(1 << CS22);
	TCNT2 = 0;
	TIMSK |= 1 << TOIE2;
	timer2_overflow = 0;
}
