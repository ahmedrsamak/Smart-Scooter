/*
 * adc.c
 *
 * Created: 3/25/2023 3:58:31 PM
 *  Author: ahmed
 */ 

#include "adc.h"
void adc_init(v_ref_selc v_ref){
switch(v_ref)
{
	case INTERNAL_REF:
	ADMUX |=  (1 << REFS0);         /* use internal 2.56 				 */
	ADMUX |=  (1 << REFS1);         /* use internal 2.56 				 */
	break;
	case EXTERNAL_VCC:
	ADMUX |=  (1 << REFS0);         /* use AVcc as the reference 				 */
	ADMUX &= ~(1 << REFS1);         /* use AVcc as the reference 				 */
	break;
}
   ADCSRA |= (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
}
uint16_t adc_read(u8 channel){
	 // Set ADC channel
	 ADMUX = (ADMUX & 0xF0) | (channel & 0x0F);
	 
	 // Start ADC conversion
	 ADCSRA |= (1 << ADSC);
	 
	 // Wait for conversion to complete
	 while (ADCSRA & (1 << ADSC));
	 
	 // Return ADC value
	 return ADC;
}