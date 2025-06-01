/*------------------------------------------------------------------------------
 *  Module      : LDR Driver
 *  File        : LDR.C
 *  Description : Source file for the LDR driver
 *  Author      : Yousef Tantawy
 *----------------------------------------------------------------------------*/

#include "ldr.h"

#include "adc.h"

/* Description:
 * This function reads the number converted from the ADC and returns the intensity
 */

uint16 LDR_getLightIntensity(void){
	uint8 light_value = 0;

	uint16 adc_value = 0;

	/* Read ADC channel where the temperature sensor is connected */
	adc_value = ADC_readChannel(LDR_SENSOR_CHANNEL_ID);

	/* Calculate the temperature from the ADC value*/
	light_value = (uint8)(((uint32)adc_value*LDR_SENSOR_MAX_LIGHT_INTENSITY*ADC_REF_VOLT)/(ADC_MAX_VALUE*LDR_SENSOR_MAX_VOLT_VALUE));
	return light_value;
}
