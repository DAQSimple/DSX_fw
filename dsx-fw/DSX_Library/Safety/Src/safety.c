/*
 * safety.c
 *
 *  Created on: Jun 3, 2021
 *      Author: jpaca
 */

#include "safety.h"

// global state variable to store fault states or normal state
// Assume normal state initially
uint8_t state = STATE_NORMAL;

// Function to update the 3 debug LEDs
void update_debug_leds(uint8_t state)
{
	switch(state)
	{
		case STATE_FAULT_OVER_CURR:
			write_debug_leds(DEBUG_LED_OVER_CURR);
			break;
		case STATE_FAULT_OVER_TEMP:
			write_debug_leds(DEBUG_LED_OVER_TEMP);
			break;
		case STATE_FAULT_REV_POL:
			write_debug_leds(DEBUG_LED_REV_POL);
			break;
		case STATE_FAULT_USB:
			write_debug_leds(DEBUG_LED_USB);
			break;
		case STATE_FAULT_UART:
			write_debug_leds(DEBUG_LED_UART);
			break;
		case STATE_FAULT_WATCHDOG:
			write_debug_leds(DEBUG_LED_WATCHDOG);
			break;
	}
}

// Function to write to the 3 debug LEDs
void write_debug_leds(uint8_t led1, uint8_t led2, uint8_t led3)
{

}

// Fault event handlers
void Fault_OC_Handler(void)
{

}

void Fault_USB_Handler(void)
{

}

void Fault_OVER_TEMP_Handler(void)
{

}

void Fault_REV_POL_Handler(void)
{

}

// Current sense interrupt service routine

// Temperature sense interrupt service routine
