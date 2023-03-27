
#include "uart.h"


 char x[10];
int main(void)
{
	uart_init(9600);
	uart_write_string("Hello");
	uart_read_string(x,10);
	uart_write_string(x);
}


