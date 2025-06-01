/*------------------------------------------------------------------------------
 *  Module      : Flame Sensor Driver
 *  File        : FlameSensor.c
 *  Description : Source file for the Flame Sensor driver
 *  Author      : Yousef Tantawy
 *----------------------------------------------------------------------------*/

#include "gpio.h"
#include "std_types.h"
#include "common_macros.h"
#include "flame.h"

/* Description:
 * Initialize the Flame sensor pin
 */

void FlameSensor_init(void){
	GPIO_setupPinDirection(FLAME_PORT_ID, FLAME_PIN_ID, PIN_INPUT);
}

/* Description:
 * Read value of PD2 to check if there is a fire or not
 */
uint8 FlameSensor_getValue(void){
	return GPIO_readPin(FLAME_PORT_ID ,FLAME_PIN_ID);
}
