/*
 * Motorcycle_controller.c
 *
 * Created: 3/27/2023 7:01:56 PM
 * Author : ahmed
 */ 


#include "MotorCycle_Sensors/Fuel_Level_sensor/fuel_level_sensor.h"

int main(void)
{
  tank_level_init();
   while (1) 
    {
		tank_level_read(FUEL_TANK_PIN);
		_delay_ms(1000);
		 
    }
}

