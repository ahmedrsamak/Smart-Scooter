/*
 * dio.h
 *
 * Created: 3/25/2023 3:30:15 AM
 *  Author: ahmed
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "common.h"
#define OUTPUT 1
#define INPUT 0
#define HIGH 1
#define LOW 0


void pinMode(uint8_t pin, uint8_t mode);

void digitalWrite(uint8_t pin, uint8_t value);

uint8_t digitalRead(uint8_t pin);

#endif /* DIO_H_ */