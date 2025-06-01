/*------------------------------------------------------------------------------
 *  Module      : ADC Driver
 *  File        : adc.h
 *  Description : Header file for the ADC driver
 *  Author      : Yousef Tantawy
 *----------------------------------------------------------------------------*/
#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/*------------------------------------------------------------------------------
 * 					 Pre-Processor Constants and Configurations
 *----------------------------------------------------------------------------*/

#define ADC_REF_VOLT				2.56
#define ADC_MAX_VALUE				1023

/*------------------------------------------------------------------------------
 *  							Function Declarations
 *----------------------------------------------------------------------------*/

/*
 * Description:
 * Initialize the ADC to needed specifications
 */
void ADC_init(void);

/*
 * Description:
 * read and store value given from ADC
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
