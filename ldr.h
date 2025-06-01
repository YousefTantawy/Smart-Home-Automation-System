/*------------------------------------------------------------------------------
 *  Module      : LDR Driver
 *  File        : LDR.h
 *  Description : Header file for the LDR driver
 *  Author      : Yousef Tantawy
 *----------------------------------------------------------------------------*/

#ifndef LDR_H_
#define LDR_H_

#include "std_types.h"

/*------------------------------------------------------------------------------
 * 					 Pre-Processor Constants and Configurations
 *----------------------------------------------------------------------------*/

#define LDR_SENSOR_CHANNEL_ID				0
#define LDR_SENSOR_MAX_VOLT_VALUE			2.56
#define LDR_SENSOR_MAX_LIGHT_INTENSITY  	100

/*------------------------------------------------------------------------------
 *  							Function Declarations
 *----------------------------------------------------------------------------*/

/* Description:
 * This function reads the number converted from the ADC and returns the intensity
 */
uint16 LDR_getLightIntensity(void);


#endif /* LDR_H_ */
