/*
 * hal_uart.h
 *
 * Created: 9/23/2018 2:18:32 PM
 *  Author: ahmed
 */ 


#ifndef UART_H_
#define UART_H_

#include "./../../common.h"

typedef enum
{
	NONE,
	EVEN=2,
	ODD,
}parity_sel;

typedef enum
{
	ONE_BIT,
	TWO_BITS,
}stop_bits_sel;

void uart_init(u32 baud_rate,parity_sel parity,stop_bits_sel stop_bits);
void uart_write_byte(char write_byte);
char uart_read_byte();
void uart_write_text(char * write_text);
void uart_write_float(f32 num);
void uart_write_num(u16 num);

#endif /* UART_H_ */