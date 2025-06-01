/*------------------------------------------------------------------------------
 *  Module      : lm35_sensor Driver
 *  File        : lm35_sensor.h
 *  Description : Header file for the lm35_sensor
 *  Author      : Yousef Tantawy
 *----------------------------------------------------------------------------*/

#ifndef LM35_SENSOR_H_
#define LM35_SENSOR_H_

#include "std_types.h"

/*------------------------------------------------------------------------------
 * 					 Pre-Processor Constants and Configurations
 *----------------------------------------------------------------------------*/


#define LM35_SENSOR_CHANNEL_ID         1
#define LM35_SENSOR_MAX_VOLT_VALUE     1.5
#define LM35_SENSOR_MAX_TEMPERATURE    150

/*------------------------------------------------------------------------------
 *  							Function Declarations
 *----------------------------------------------------------------------------*/

/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
uint8 LM35_getTemperature(void);

#endif /* LM35_SENSOR_H_ */
