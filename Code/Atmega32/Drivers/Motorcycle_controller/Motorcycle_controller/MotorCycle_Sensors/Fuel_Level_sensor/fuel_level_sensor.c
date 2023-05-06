/*
 * fuel_level_sensor.c
 *
 * Created: 3/28/2023 2:36:19 AM
 *  Author: ahmed
 */ 
#include "fuel_level_sensor.h"
void tank_level_init()
{
	#ifdef _DEBUG
	uart_init(9600,NONE,ONE_BIT);
	uart_write_text("UART BEGIN\r\n");
#endif // _DEBUG

	 adc_init(INTERNAL_REF);
}

f32 tank_level_read(u8 tank_level_pin)
{
		  f32 tank_level; // tank level reading will be stored
		  tank_level = map(adc_read(tank_level_pin),ADC_VALUE_MIN,ADC_VALUE_MAX,Fuel_Tank_MAX_SIZE,0);
		  tank_level = tank_level/1000;
		  
		  #ifdef _DEBUG
		   uart_write_text("Fuel Level: ");
		   uart_write_float(tank_level);
		   uart_write_text(" L\r\n");
		   uart_write_text("ADC value for fuel level sensor: ");
		   uart_write_num(adc_read(tank_level_pin));
		   uart_write_text("\r\n");
#endif // _DEBUG

return tank_level;
}