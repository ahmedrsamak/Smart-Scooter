/*
 * adc.c
 *
 * Created: 3/25/2023 3:58:31 PM
 *  Author: ahmed
 */ 

#include "adc.h"
void adc_init(void){
DDRA= 0x00;
ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); /* 128 pre-scale for 8Mhz */
ADCSRA |= (1 << ADEN);   							  /* Enable the ADC */
}
uint16_t adc_read(uint8_t channel){
	uint8_t  ADC_LOW;
	uint8_t  ADC_high;
	uint16_t ADC_value;
	ADMUX  = channel;            /* define which ADC channel 				 */
	ADMUX |=  (1 << REFS0);         /* use AVcc as the reference 				 */
	ADMUX &= ~(1 << ADLAR);   		/* making ADCH has the MSbit 				 */
	ADCSRA |= (1<<ADSC);		    /* Start Conversion							 */
	while(!(ADCSRA & (1<<ADIF)));   /* wait until conversion complete 			 */
	ADCSRA |= (1<<ADIF);			/* clear hardware "conversion complete" flag */
	ADC_LOW = ADCL; 				/* read ADC data low REG before high REG     */
	ADC_high= ADCH;
	ADC_value = (ADC_high<<8)|(ADC_LOW & 0xFF);
	return(ADC_value);                             // Returns the ADC value of the chosen channel
}