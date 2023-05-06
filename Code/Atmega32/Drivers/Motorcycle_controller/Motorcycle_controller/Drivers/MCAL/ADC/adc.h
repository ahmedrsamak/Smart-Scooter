/*
 * adc.h
 *
 * Created: 3/25/2023 3:58:41 PM
 *  Author: ahmed
 */ 


#ifndef ADC_H_
#define ADC_H_
#include "../../common.h"
typedef enum
{
	INTERNAL_REF, // 2.56 VOLT
	EXTERNAL_VCC, // external with AVCC and VREF
}v_ref_selc;


void adc_init(v_ref_selc v_ref);

uint16_t adc_read(u8 channel);


#endif /* ADC_H_ */