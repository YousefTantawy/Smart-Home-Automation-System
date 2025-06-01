	/*------------------------------------------------------------------------------
 *  Module      : ADC Driver
 *  File        : adc.c
 *  Description : Source file for the ADC driver
 *  Author      : Yousef Tantawy
 *----------------------------------------------------------------------------*/

#include "gpio.h"
#include "adc.h"
#include "avr/io.h"
#include "common_macros.h"

/*
 * Description:
 * Initialize the ADC to needed specifications
 */
void ADC_init(void){

	/* ADPS1 = 1 & ADPS2 = 1 & ADPS0 = 1 to activate 128 prescalar
	 * ADEN = 1 to activate ADC
	 * ADATE = 0  we will not use auto trigger mode
	 */
	ADCSRA |= 1 << ADPS2 | 1 << ADPS1 | 1 << ADPS0 | 1 << ADEN;

	/* REFS1 = 1 and REFS0 = 1 to activate 2.56 internal volt
	 * MUX = 0 to initialize at channel 0
	 * ADLAR = 0 for ADC value right adjustment
	 */
	ADMUX |= 1 << REFS1 | 1 << REFS0;
}

/*
 * Description:
 * read and store value given from ADC
 */
uint16 ADC_readChannel(uint8 channel_num){

	/*
	 * To ensure that the number only affects the ADMUX numbers
	 */
	channel_num &= 0x07;
	/*
	 * Ensure that the ADMUX numbers are 0
	 */
	ADMUX &= 0xE0;
	ADMUX |= channel_num;
	/*
	 * Start converting analogue to digital
	 */
	SET_BIT(ADCSRA, ADSC);
	while(BIT_IS_CLEAR(ADCSRA, ADIF));
	SET_BIT(ADCSRA, ADIF);
	return ADC;
}
