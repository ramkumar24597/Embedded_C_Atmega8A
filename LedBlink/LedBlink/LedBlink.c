/*
 * LedBlink.c
 *
 * Created: 5/26/2018 12:19:38 PM
 *  Author: Ram
 */ 


#include <avr/io.h>
#define F_CPU 8000000UL

static void ioinit(void);
static void led_on(void);
static void led_off(void);

int main(void)
{
	ioinit();
    while(1)
    {
        //TODO:: Please write your application code 
		if(bit_is_clear(PINC, 0))
		{
			led_on();
		}
		else
		{
			led_off();	
		}
    }
}

static void ioinit (void)
{
	DDRC = 0b11111110;
	PORTC = 0b00000001;
}

static void led_on(void)
{
	PORTC = 0b00000011; 
}

static void led_off(void)
{
	PORTC = 0b00000001;
}

