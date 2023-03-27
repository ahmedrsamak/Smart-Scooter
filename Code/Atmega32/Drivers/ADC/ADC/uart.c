/*
 * uart.c
 *
 * Created: 3/25/2023 2:31:08 AM
 *  Author: ahmed
 */ 

#include "uart.h"

void uart_init(uint32_t baud_rate)
{
	// Calculate UBRR value
	uint16_t UBRR_value = (((F_CPU / (baud_rate * 16UL))) - 1);
	
	// Set baud rate
	UBRRH = (uint8_t)(UBRR_value >> 8);
	UBRRL = (uint8_t)(UBRR_value);
	
	// Enable transmitter and receiver
	UCSRB |= (1 << TXEN) | (1 << RXEN);
	
	// Set frame format: 8 data bits, 1 stop bit, no parity
	UCSRC |= (1<<URSEL) | (1<<UCSZ0) | (1<<UCSZ1);
}

void uart_write_char(char data)
{
	// Wait for the transmitter to be ready
	while (!(UCSRA & (1 << UDRE)));
	
	// Send the data
	UDR = data;
}

void uart_write_string(char* data)
{
	// Loop through each character in the string
	while (*data != '\0')
	{
		// Send the current character
		uart_write_char(*data);
		
		// Move to the next character
		data++;
	}
}


void uart_write_num(uint16_t number)
{
	char buffer[10];
	itoa(number,buffer,10);
	uart_write_string(buffer); // Send the string via UART
}


void uart_read_string(char* buffer, uint8_t buffer_size)
{
	// Loop through each character in the buffer
	for (uint8_t i = 0; i < buffer_size; i++)
	{
		// Receive the current character
		buffer[i] = uart_read_char();
		
		// Stop if a null terminator is received
		if (buffer[i] == '\r' || buffer[i] == '\0' )
		{
			break;
		}
	}
}


char uart_read_char(void)
{
	// Wait for data to be received
	while (!(UCSRA & (1 << RXC)));
	
	// Return the received data
	return UDR;
}