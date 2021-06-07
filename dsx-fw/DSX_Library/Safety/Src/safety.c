/*
 * safety.c
 *
 *  Created on: Jun 3, 2021
 *      Author: jpaca
 */

#include "safety.h"

extern TIM_HandleTypeDef htim4;

// global state variable to store fault states or normal state
uint8_t state;

// Array of arrays for controlling dual multiplexers
uint8_t Multiplex_Control_Arr[8][3] = {
		{0,  0,  0},	/* Select multiplexer channel 0 */
		{0,  0,  1},	/* Select multiplexer channel 1 */
		{0,  1,  0},	/* Select multiplexer channel 2 */
		{0,  1,  1},	/* Select multiplexer channel 3 */
		{1,  0,  0},	/* Select multiplexer channel 4 */
		{1,  0,  1},	/* Select multiplexer channel 5 */
		{1,  1,  0},	/* Select multiplexer channel 6 */
		{1,  1,  1}		/* Select multiplexer channel 7 */
};

// Function to init current sense timer and state
void safety_init(void)
{
	HAL_TIM_Base_Start_IT(&htim4);	// Start timer 4
	state = STATE_NORMAL;			// Assume initial state is NORMAL, so no faults
}

// Function to update the 3 debug LEDs
void update_debug_leds(uint8_t state)
{
	switch(state)
	{
	case STATE_FAULT_OVER_CURR:
		write_debug_leds(DEBUG_LED_OVER_CURR); break;

	case STATE_FAULT_OVER_TEMP:
		write_debug_leds(DEBUG_LED_OVER_TEMP); break;

	case STATE_FAULT_REV_POL:
		write_debug_leds(DEBUG_LED_REV_POL); break;

	case STATE_FAULT_USB:
		write_debug_leds(DEBUG_LED_USB); break;

	case STATE_FAULT_UART:
		write_debug_leds(DEBUG_LED_UART); break;

	case STATE_FAULT_WATCHDOG:
		write_debug_leds(DEBUG_LED_WATCHDOG); break;
	}
}

// Function to write to the 3 debug LEDs
void write_debug_leds(uint8_t led1_state, uint8_t led2_state, uint8_t led3_state)
{

}

// Multiplex_100Hz_Control ISR
// Uses Timer4, PSC=10000-1, Period=170-1. Result is an update freq=100Hz.
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	static uint8_t i = 0;		// For cycling through the Multiplex Control Array
	if(htim->Instance == TIM4) 	// if the source is timer 4
	{
		HAL_GPIO_WritePin(MUX1_GPIO_Port, MUX1_Pin, Multiplex_Control_Arr[i][0]);	// Goes to Multiplexer Control pin A
		HAL_GPIO_WritePin(MUX2_GPIO_Port, MUX2_Pin, Multiplex_Control_Arr[i][1]);	// Goes to Multiplexer Control pin B
		HAL_GPIO_WritePin(MUX3_GPIO_Port, MUX3_Pin, Multiplex_Control_Arr[i][2]);	// Goes to Multiplexer Control pin C
		if(i==7) i=0;
		else 	 i++;
	}
}

// Over Current ISR

// Over Temperature ISR
