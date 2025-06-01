/*------------------------------------------------------------------------------
 *  Module      : Application Driver
 *  File        : Main.c
 *  Description : Source file for the Application driver
 *  Author      : Yousef Tantawy
 *----------------------------------------------------------------------------*/

#include "adc.h"
#include "buzzer.h"
#include "gpio.h"
#include "std_types.h"
#include "led.h"
#include "lcd.h"
#include "common_macros.h"
#include <util/delay.h>
#include <avr/io.h>

#include "flame.h"
#include "ldr.h"
#include "motor.h"
#include "pwm.h"

int main(void)
{

	/*
	 * FLAME = Store value of FlameSensor
	 * temp = Store temperature read from ADC
	 * light = Store light intensity read from ADC
	 */
	uint8 flame;
	uint8 temp;
	uint8 light;


	/*
	 * Initialize all components
	 */
	LCD_init();
	DcMotor_Init();
	LED_init();
	BUZZER_init();
	ADC_init();
	FlameSensor_init();

    for(;;)
    {
    	/*
    	 * Update value of Flame Sensor to display either critical error or normal functions
    	 */
    	flame = FlameSensor_getValue();

    	if(!(flame)){
    		/*
    		 * Clear any string on the screen
    		 */
    		LCD_clearScreen();

    		/*
    		 * Turn off Buzzer
    		 */
    		BUZZER_off();

    		/*
    		 * Display Fan state, temperature and Light intensity
    		 */
    		LCD_displayStringRowColumn(0, 4,"FAN is OFF");
    		LCD_displayStringRowColumn(1, 0,"Temp=");

    		LCD_displayStringRowColumn(1, 8,"LDR=");
    		LCD_displayStringRowColumn(1, 15,"%");

    		while(!(flame))
    		{
			temp = LM35_getTemperature();
			light = LDR_getLightIntensity();

			LCD_moveCursor(1,5);
			if(temp >= 100){
				LCD_moveCursor(1,5);
				LCD_intgerToString(temp);
			}
			else
			{
				LCD_intgerToString(temp);
				/*
				 * In case the digital value is two or one digits print space in the next digit place
				 */
				LCD_displayCharacter(' ');
			}

			LCD_moveCursor(1,12);
			if(light >= 100){
				LCD_intgerToString(light);
			}
			else
			{
				LCD_intgerToString(light);
				/*
				 *  In case the digital value is two or one digits print space in the next digit place
				 */
				LCD_displayCharacter(' ');
			}


			if(temp < 25)
			{
				/*
				 * If temperature if lower than 25, display Fan OFF state on LCD and stop the Motor
				 */
				LCD_displayStringRowColumn(0, 4,"FAN is OFF");
				DcMotor_Rotate(STOP, 0);
			}
			else if(temp >= 25 && temp < 30)
			{
				/*
				 * If temperature if lower than 30 and higher than 25, display Fan ON state on LCD and activate the Motor on 25% speed
				 */
				LCD_displayStringRowColumn(0, 4,"FAN is ON");
				/*
				 *  In case the string is two or one characters print space it's place
				 */
				LCD_displayCharacter(' ');
				DcMotor_Rotate(CW, 64);
			}
			else if(temp >= 30 && temp < 35)
			{
				/*
				 * If temperature if lower than 35 and higher than 30, display Fan ON state on LCD and activate the Motor on 50% speed
				 */
				LCD_displayStringRowColumn(0, 4,"FAN is ON");
				/*
				 *  In case the string is two or one characters print space in it's place
				 */
				LCD_displayCharacter(' ');
				DcMotor_Rotate(CW, 128);
			}
			else if(temp >= 35 && temp < 40)
			{
				/*
				 * If temperature if lower than 40 and higher than 35, display Fan ON state on LCD and activate the Motor on 75% speed
				 */
				LCD_displayStringRowColumn(0, 4,"FAN is ON");
				/*
				 *  In case the string is two or one characters print space in it's place
				 */
				LCD_displayCharacter(' ');
				DcMotor_Rotate(CW, 192);
			}
			else
			{
				/*
				 * If temperature if higher than 40, display Fan ON state on LCD and activate the Motor on 100% speed
				 */
				LCD_displayStringRowColumn(0, 4,"FAN is ON");
				/*
				 *  In case the string is two or one characters print space in it's place
				 */
				LCD_displayCharacter(' ');
				DcMotor_Rotate(CW, 255);
			}


			if(light >= 75){
				/*
				 * if light intensity is higher than 75 then activate no LEDs
				 */
				LED_off(LED_RED_PIN_ID);
				LED_off(LED_GREEN_PIN_ID);
				LED_off(LED_BLUE_PIN_ID);
			}
			else if(light < 75 && light >= 50){
				/*
				 * if light intensity is lower than 75 and higher than 50 then activate red LED only
				 */
				LED_on(LED_RED_PIN_ID);
				LED_off(LED_GREEN_PIN_ID);
				LED_off(LED_BLUE_PIN_ID);
			}
			else if(light < 50 && light >= 15){
				/*
				 * if light intensity is lower than 50 and higher than 15 then activate red and green LED
				 */
				LED_on(LED_RED_PIN_ID);
				LED_on(LED_GREEN_PIN_ID);
				LED_off(LED_BLUE_PIN_ID);
			}
			else{
				/*
				 * Activate all LEDs if light intensity lower than 15
				 */
				LED_on(LED_RED_PIN_ID);
				LED_on(LED_GREEN_PIN_ID);
				LED_on(LED_BLUE_PIN_ID);
			}


			/*
			 * To prevent the LCD from printing the same string each time
			 */
    			flame = FlameSensor_getValue(); /* update value */
    		}
    	}

    	else
    	{
    		/*
    		 * Clear any string on the screen
    		 */
    		LCD_clearScreen();
    		LCD_displayString("Critical Alert!");

    		/*
    		 * Activate buzzer to indicate flame
    		 */
    		BUZZER_on();

			/*
			 * To prevent the LCD from printing the same string each time
			 */
    		while(flame)
    		{
    			flame = FlameSensor_getValue(); /* update value */
    		}
    	}
    }
}
