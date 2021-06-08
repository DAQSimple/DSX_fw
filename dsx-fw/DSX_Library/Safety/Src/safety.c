/*
 * safety.c
 *
 *  Created on: Jun 3, 2021
 *      Author: jpaca
 */

#include "safety.h"

// global state variable to store fault states or normal state
uint8_t state;

// Array of arrays for controlling dual multiplexers
uint8_t Multiplex_Control_Arr_2CH_1Sel[2] = {
		0,	/* Select multiplexer channel 0 */
		1,	/* Select multiplexer channel 1 */
};

uint8_t Multiplex_Control_Arr_4CH_2Sel[4][2] = {
		{0,  0},	/* Select multiplexer channel 0 */
		{0,  1},	/* Select multiplexer channel 1 */
		{1,  0},	/* Select multiplexer channel 2 */
		{1,  1},	/* Select multiplexer channel 3 */
};

uint8_t Multiplex_Control_Arr_8CH_3Sel[8][3] = {
		{0,  0,  0},	/* Select multiplexer channel 0 */
		{0,  0,  1},	/* Select multiplexer channel 1 */
		{0,  1,  0},	/* Select multiplexer channel 2 */
		{0,  1,  1},	/* Select multiplexer channel 3 */
		{1,  0,  0},	/* Select multiplexer channel 4 */
		{1,  0,  1},	/* Select multiplexer channel 5 */
		{1,  1,  0},	/* Select multiplexer channel 6 */
		{1,  1,  1}		/* Select multiplexer channel 7 */
};

uint8_t Multiplex_Control_Arr_16CH_4Sel[16][4] = {
		{0,  0,  0,  0},	/* Select multiplexer channel 0  */
		{0,  0,  0,  1},	/* Select multiplexer channel 1  */
		{0,  0,  1,  0},	/* Select multiplexer channel 2  */
		{0,  0,  1,  1},	/* Select multiplexer channel 3  */
		{0,  1,  0,  0},	/* Select multiplexer channel 4  */
		{0,  1,  0,  1},	/* Select multiplexer channel 5  */
		{0,  1,  1,  0},	/* Select multiplexer channel 6  */
		{0,  1,  1,  1},	/* Select multiplexer channel 7  */
		{1,  0,  0,  0},	/* Select multiplexer channel 8  */
		{1,  0,  0,  1},	/* Select multiplexer channel 9  */
		{1,  0,  1,  0},	/* Select multiplexer channel 10 */
		{1,  0,  1,  1},	/* Select multiplexer channel 11 */
		{1,  1,  0,  0},	/* Select multiplexer channel 12 */
		{1,  1,  0,  1},	/* Select multiplexer channel 13 */
		{1,  1,  1,  0},	/* Select multiplexer channel 14 */
		{1,  1,  1,  1},	/* Select multiplexer channel 15 */
};

// Function to init current sense timer and state
void safety_init(void)
{
	HAL_TIM_Base_Start_IT(&htim4);	// Start timer 4
	state = STATE_NORMAL;			// Assume initial state is NORMAL, so no faults
	update_debug_leds(DEBUG_LED_NORMAL_OP);
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


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	static uint8_t mux_channel_AB = 0;	// For cycling through the Multiplex Control Array for MUX pair A and B
	static uint8_t mux_channel_C  = 0;	// For cycling through the Multiplex Control Array for MUX C

	// MultiplexAB_100Hz_Control ISR
	// Uses Timer4, PSC=10000-1, Period=170-1. Result is an update freq=100Hz.
	if(htim->Instance == TIM4) 		// if the interrupt source is timer 4
	{
//		HAL_GPIO_WritePin(MUXA_S0_GPIO_Port, MUXA_S0_Pin, Multiplex_Control_Arr_16CH_4Sel[mux_channel][0]);	// Goes to Multiplexer Control pin S0
//		HAL_GPIO_WritePin(MUXA_S1_GPIO_Port, MUXA_S1_Pin, Multiplex_Control_Arr_16CH_4Sel[mux_channel][1]);	// Goes to Multiplexer Control pin S1
//		HAL_GPIO_WritePin(MUXA_S2_GPIO_Port, MUXA_S2_Pin, Multiplex_Control_Arr_16CH_4Sel[mux_channel][2]);	// Goes to Multiplexer Control pin S2
//		HAL_GPIO_WritePin(MUXA_S3_GPIO_Port, MUXA_S3_Pin, Multiplex_Control_Arr_16CH_4Sel[mux_channel][3]);	// Goes to Multiplexer Control pin S3

//		HAL_GPIO_WritePin(MUXB_S0_GPIO_Port, MUXB_S0_Pin, Multiplex_Control_Arr_2CH_1Sel[mux_channel % 2]);	// Goes to Multiplexer Control pin S0

		// Go to the next channel, wrap at the end channel
		mux_channel_AB = (mux_channel_AB == MUX_CHANNEL_END) ? MUX_CHANNEL_0 : mux_channel_AB+1;
	}

	// MultiplexC_400Hz_Control ISR
	// Check interrupt source
	//	HAL_GPIO_WritePin(MUXC_S0_GPIO_Port, MUXC_S0_Pin, Multiplex_Control_Arr_2CH_1Sel[mux_channel_C]);	// Goes to Multiplexer Control pin S0
	//	mux_channel_C ^= 0x1;

}

// Fault event handlers
void DSX_Fault_Handler(uint8_t state)
{
	switch(state)
	{
	case STATE_FAULT_OVER_CURR:
		/* Disable all multiplexer outputs */
		/* Play Buzzer Over Current Pattern */
		break;

	case STATE_FAULT_OVER_TEMP:
		/* Play Buzzer Over Current Pattern */
		break;

	case STATE_FAULT_REV_POL:
		/* Play Buzzer Over Current Pattern */
		break;

	case STATE_FAULT_USB:
		/* Play Buzzer Over Current Pattern */
		break;

	case STATE_FAULT_UART:
		/* Play Buzzer Over Current Pattern */
		break;

	case STATE_FAULT_WATCHDOG:
		/* Play Buzzer Over Current Pattern */
		break;
	}
}

// Over Current ISR : set state = STATE_FAULT_OVER_CURR
// Need to have an ADC pin configured for reading the current sense circuit

// Over Temperature ISR : set state = STATE_FAULT_OVER_TEMP
// Need to config the board temp sensor and set interrupt event at some threshhold
