/*
 * dio.c
 *
 * Created: 3/25/2023 3:30:03 AM
 *  Author: ahmed
 */ 
#include "dio.h"



void pinMode(uint8_t pin, uint8_t mode)
{
	if (mode == OUTPUT)
	{
		/* Set the data direction of the pin to output */
		switch (pin / 8)
		{
			case 0: DDRB |= (1 << (pin % 8)); break;
			case 1: DDRC |= (1 << (pin % 8)); break;
			case 2: DDRD |= (1 << (pin % 8)); break;
		}
	}
	else if (mode == INPUT)
	{
		/* Set the data direction of the pin to input */
		switch (pin / 8)
		{
			case 0: DDRB &= ~(1 << (pin % 8)); break;
			case 1: DDRC &= ~(1 << (pin % 8)); break;
			case 2: DDRD &= ~(1 << (pin % 8)); break;
		}
	}
}



void digitalWrite(uint8_t pin, uint8_t value)
{
	if (value == HIGH)
	{
		/* Set the pin to high */
		switch (pin / 8)
		{
			case 0: PORTB |= (1 << (pin % 8)); break;
			case 1: PORTC |= (1 << (pin % 8)); break;
			case 2: PORTD |= (1 << (pin % 8)); break;
		}
	}
	else if (value == LOW)
	{
		/* Set the pin to low */
		switch (pin / 8)
		{
			case 0: PORTB &= ~(1 << (pin % 8)); break;
			case 1: PORTC &= ~(1 << (pin % 8)); break;
			case 2: PORTD &= ~(1 << (pin % 8)); break;
		}
	}
}


uint8_t digitalRead(uint8_t pin)
{
	uint8_t value = LOW;

	/* Read the pin value */
	switch (pin / 8)
	{
		case 0: value = (PINB >> (pin % 8)) & 0x01; break;
		case 1: value = (PINC >> (pin % 8)) & 0x01; break;
		case 2: value = (PIND >> (pin % 8)) & 0x01; break;
	}

	return value;
}