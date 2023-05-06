/*
 * dio.c
 *
 * Created: 9/8/2018 9:49:51 PM
 *  Author: ahmed
 */ 
#include "dio.h"
void dio_set_port_dir(port_base port,dir mode)
{
	if (mode==OUTPUT)
	{
		(*(volatile port_base*)(port-1))=0xFF;
	}
	else if(mode == INPUT)
	{
		(*(volatile port_base*)(port-1))=0x00;
	}
	else
	{
	 (*(volatile port_base*)(port-1))=mode;	
	}
}
void dio_set_pin_dir(port_base port,u8 pin,dir mode)
{
	if (mode==OUTPUT)
	{
		(*(volatile port_base*)(port-1))|=(1<<pin);
	}
	else
	{
		(*(volatile port_base*)(port-1))&=~(1<<pin);
	}
}
void dio_write_port(port_base port,state mode)
{
	if (mode==HIGH)
	{
		(*(volatile port_base*)(port))=0xFF;
	}
	else if(mode == LOW)
	{
		(*(volatile port_base*)(port))=0x00;
	}
	else
	{
		(*(volatile port_base*)(port))=mode;
	}
}
void dio_write_pin(port_base port,u8 pin,state mode)
{
	if (mode==HIGH)
	{
		(*(volatile port_base*)(port))|=(1<<pin);
	}
	else
	{
		(*(volatile port_base*)(port))&=~(1<<pin);
	}
}
u8 dio_read_port(port_base port)
{
	return(*(volatile port_base*)(port-2));
}
u8 dio_read_pin(port_base port,u8 pin)
{
	return ((*(volatile port_base*)(port-2))&(1<<pin))>>pin;	
}