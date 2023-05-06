/*
 * fuel_level_sensor.h
 *
 * Created: 3/28/2023 2:36:04 AM
 *  Author: ahmed
 */ 


#ifndef FUEL_LEVEL_SENSOR_H_
#define FUEL_LEVEL_SENSOR_H_

#include "../../Drivers/MCAL/ADC/adc.h"
#include "../../Drivers/MCAL/UART/uart.h"
#include "../../Drivers/MCAL/DIO/dio.h"

#define FUEL_TANK_PIN 0 // ADC pin input for fuel tank level sensor
#define ADC_VALUE_MIN 50 // min adc value reading for fuel tank level sensor
#define ADC_VALUE_MAX 1023 // max adc value reading for fuel tank level sensor
#define Fuel_Tank_MAX_SIZE 6500



void tank_level_init();
f32 tank_level_read(u8 tank_level_pin);
#endif /* FUEL_LEVEL_SENSOR_H_ */