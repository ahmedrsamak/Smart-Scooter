/*
 * dio.h
 *
 * Created: 9/8/2018 9:49:26 PM
 *  Author: ahmed
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "../../common.h"
typedef enum
{
	INVALID_MIN_INDEX=0x2F,
	pind = 0X30,
	ddrd,
	portd,
	pinc,
	ddrc,
	portc,
	pinb,
	ddrb,
	portb,
	pina,
	ddra,
	porta,
	INVALID_MAX_INDEX,
}port_base;

typedef enum
{
OUTPUT=1,
INPUT =0,
}dir;
typedef enum
{
HIGH=1,
LOW =0,
}state;

void dio_set_port_dir(port_base port,dir mode);
void dio_set_pin_dir(port_base port,u8 pin,dir mode);
void dio_write_port(port_base port,state mode);
void dio_write_pin(port_base port,u8 pin,state mode);
u8 dio_read_port(port_base port);
u8 dio_read_pin(port_base port,u8 pin);
#endif /* DIO_H_ */