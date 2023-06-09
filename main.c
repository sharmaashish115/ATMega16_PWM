/*
 * ATMega16_PWM.c
 *
 * Created: 2023-06-08 8:52:12 PM
 * Author : a_shi
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

unsigned int i;

int main(void)
{
    //Set mode of the Timer1
	TCCR1B &= ~(1<<WGM13);
	TCCR1B |= (1<<WGM12);
	TCCR1A |= (1<<WGM10) | (1<<WGM11);		//FAST PWM 10 BIT MODE
	
	//Set PWM Mode
	TCCR1A |= (1<<COM1A1);
	TCCR1A &= ~(1<<COM1A0);				//PWM in Non Inverting Mode
	
	//Clock is 8MHz and prescaler is 256. So, 8000000/256 =31250
	TCCR1B |= (1<<CS12);
	
	//Configure the Output compare pin as O/P
	DDRD |= (1<<DDD5);
	
	
    while (1) 
    {
		for (i=0; i<1023; i++)
		{
			OCR1A = i;
			_delay_ms(2);
		}
		
		_delay_ms(4000);
		
		for (i=1023; i<0; i--)
		{
			OCR1A =i;
			_delay_ms(2);
		}
		
		_delay_ms(4000);
		
    }
}

