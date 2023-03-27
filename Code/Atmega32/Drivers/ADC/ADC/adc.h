/*
 * adc.h
 *
 * Created: 3/25/2023 3:58:41 PM
 *  Author: ahmed
 */ 


#ifndef ADC_H_
#define ADC_H_
#include "common.h"

void adc_init();

uint16_t adc_read(uint8_t channel);


#endif /* ADC_H_ */