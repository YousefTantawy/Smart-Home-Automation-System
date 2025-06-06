/*------------------------------------------------------------------------------
 *  Module      : lm35_sensor Driver
 *  File        : lm35_sensor.c
 *  Description : Source file for the lm35_sensor
 *  Author      : Yousef Tantawy
 *----------------------------------------------------------------------------*/

#include "lm35_sensor.h"
#include "adc.h"

/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
uint8 LM35_getTemperature(void)
{
	uint8 temp_value = 0;

	uint16 adc_value = 0;

	/* Read ADC channel where the temperature sensor is connected */
	adc_value = ADC_readChannel(LM35_SENSOR_CHANNEL_ID);

	/* Calculate the temperature from the ADC value*/
	temp_value = (uint8)(((uint32)adc_value*LM35_SENSOR_MAX_TEMPERATURE*ADC_REF_VOLT)/(ADC_MAX_VALUE*LM35_SENSOR_MAX_VOLT_VALUE));

	return temp_value;
}

