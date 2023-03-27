/*
 * ADC.c
 *
 * Created: 3/25/2023 3:58:08 PM
 * Author : ahmed
 */ 

#include "adc.h"
#include "uart.h"
#include "dio.h"
int x=0;
int main(void)
{
	pinMode(19,OUTPUT);
	
    adc_init(1);
	uart_init(9600);
    while (1) 
    {
		x=adc_read(0);
		digitalWrite(19,HIGH);
		uart_write_num(x);
		uart_write_string("\r\n");
		_delay_ms(500);
		digitalWrite(19,LOW);
		_delay_ms(500);
    }
}

