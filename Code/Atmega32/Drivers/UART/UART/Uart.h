#ifndef UART_H
#define UART_H

#include "common.h"

void uart_init(uint32_t baud_rate);
void uart_write_char(char data);
void uart_write_string(char* data);
void uart_write_num(float number);
void uart_read_string(char* buffer, uint8_t buffer_size);
char uart_read_char(void);

#endif /* UART_H */