/*------------------------------------------------------------------------------
 *  Module      : Flame Sensor Driver
 *  File        : FlameSensor.h
 *  Description : Header file for the Flame Sensor driver
 *  Author      : Yousef Tantawy
 *----------------------------------------------------------------------------*/

#ifndef FLAME_H_
#define FLAME_H_

#include "std_types.h"

/*------------------------------------------------------------------------------
 * 					 Pre-Processor Constants and Configurations
 *----------------------------------------------------------------------------*/

#define FLAME_PORT_ID					PORTD_ID
#define FLAME_PIN_ID					PIN2_ID

/*------------------------------------------------------------------------------
 *  							Function Declarations
 *----------------------------------------------------------------------------*/

/* Description:
 * Initialize the Flame sensor pins
 */
void FlameSensor_init(void);

/* Description:
 * Get value of Flame sensor if there is fire or not
 */
uint8 FlameSensor_getValue(void);

#endif /* FLAME_H_ */
