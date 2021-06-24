/*
 * safety.c
 *
 *  Created on: Jun 3, 2021
 *      Author: jpaca
 */

#include "safety.h"

// flag to know if limit switch interrupts are wanted
bool limit_switch1_interrupt = ENABLED;	//limit switch1 interrupt enabled by default
bool limit_switch2_interrupt = ENABLED;	//limit switch2 interrupt enabled by default

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
	if(limit_switch1_interrupt == ENABLED && limit_switch2_interrupt == ENABLED)
	{
		if(    HAL_GPIO_ReadPin(LIMIT_SW1_GPIO_Port, LIMIT_SW1_Pin )	// Fault if a limit switch is pressed at startup
			|| HAL_GPIO_ReadPin(LIMIT_SW2_GPIO_Port, LIMIT_SW2_Pin ))
		{
			state = STATE_FAULT_LIMIT_SW;
			return;
		}
	}

	HAL_TIM_Base_Start_IT(&htim2);	// Start timer 2, 100 Hz
	HAL_TIM_Base_Start_IT(&htim5);	// Start timer 5, 400 Hz
	HAL_ADC_Start_DMA(&hadc5, temp_current_buf, sizeof(temp_current_buf));	// 2 channel, reads temp channel followed by system current
	HAL_GPIO_WritePin(MUX_En_GPIO_Port, MUX_En_Pin, ENABLE_MUX);  // Enable MUX
	state = STATE_NORMAL;			// Assume initial state is NORMAL, so no faults
	write_debug_leds(DEBUG_LED_NORMAL_OP);	// Write to the 3 debug leds, normal operation
	HAL_GPIO_WritePin(FAULT_LED_GPIO_Port, FAULT_LED_Pin, 0);	// Front panel fault LED off
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

	case STATE_FAULT_LIMIT_SW:
		write_debug_leds(DEBUG_LED_LIMIT_SW); break;
	}
}

// Function to write to the 3 debug LEDs
void write_debug_leds(uint8_t led1_state, uint8_t led2_state, uint8_t led3_state)
{
	HAL_GPIO_WritePin(DEBUG_LD1_GPIO_Port, DEBUG_LD1_Pin, led1_state);
	HAL_GPIO_WritePin(DEBUG_LD2_GPIO_Port, DEBUG_LD2_Pin, led2_state);
	HAL_GPIO_WritePin(DEBUG_LD3_GPIO_Port, DEBUG_LD3_Pin, led3_state);
}


// Getters for MUX channel select S0 for MUX pair AB
uint8_t MUXAB_CH_Select_S0(uint8_t mux_channel)
{
	return Multiplex_Control_Arr_16CH_4Sel[mux_channel][0];
}

// Getters for MUX channel select S1 for MUX pair AB
uint8_t MUXAB_CH_Select_S1(uint8_t mux_channel)
{
	return Multiplex_Control_Arr_16CH_4Sel[mux_channel][1];
}

// Getters for MUX channel select S2 for MUX pair AB
uint8_t MUXAB_CH_Select_S2(uint8_t mux_channel)
{
	return Multiplex_Control_Arr_16CH_4Sel[mux_channel][2];
}

// Getters for MUX channel select S3 for MUX pair AB
uint8_t MUXAB_CH_Select_S3(uint8_t mux_channel)
{
	return Multiplex_Control_Arr_16CH_4Sel[mux_channel][3];
}

// Getters for MUX channel select S0 for MUX pair B
uint8_t MUXB_CH_Select_S0(uint8_t mux_channel)
{
	return Multiplex_Control_Arr_2CH_1Sel[mux_channel % 2];
}

// Getters for MUX channel select S0 for MUX C
uint8_t MUXC_CH_Select_S0(uint8_t mux_channel)
{
	return Multiplex_Control_Arr_2CH_1Sel[mux_channel];
}

// Getters for Temperature and Current readings
uint32_t get_temp_reading(void)
{
	return temp_current_buf[0];
}

uint32_t get_current_reading(void)
{
	return temp_current_buf[1];
}

// Function to disable limit switch interrupts for use in commands library
void disable_limit_sw_interrupt_pin(uint8_t DI_pin)
{
	if(DI_pin == DI7){
		limit_switch1_interrupt = DISABLED;
	}
	else if(DI_pin == DI8){
		limit_switch2_interrupt = DISABLED;
	}
}

// Function to enable limit switch interrupts for use in commands library
void enable_limit_sw_interrupt_pin(uint8_t DI_pin)
{
	if(DI_pin == DI7){
		limit_switch1_interrupt = ENABLED;
	}
	else if(DI_pin == DI8){
		limit_switch2_interrupt = ENABLED;
	}
}

// Fault event handlers
void DSX_Fault_Handler(uint8_t state)
{
	switch(state)
	{
	case STATE_FAULT_OVER_CURR:
		HAL_GPIO_WritePin(MUX_En_GPIO_Port, MUX_En_Pin, DISABLE_MUX);  // DISABLE MUX
		/* Play Buzzer */
		break;

	case STATE_FAULT_OVER_TEMP:
		/* Play Buzzer */
		break;

	case STATE_FAULT_REV_POL:
		/* Play Buzzer */
		break;

	case STATE_FAULT_USB:
		/* Play Buzzer */
		break;

	case STATE_FAULT_UART:
		/* Play Buzzer */
		break;

	case STATE_FAULT_LIMIT_SW:
		/* Play Buzzer */
		updateDutyCycle(htim16, 0);	// Disable PWM
		updateDutyCycle(htim17, 0); // Disable PWM
		break;
	}
}

// External interrupt for limit switch. Fired at rising edge.
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(GPIO_Pin);

  if(limit_switch1_interrupt == ENABLED || limit_switch2_interrupt == ENABLED){
	  state = STATE_FAULT_LIMIT_SW;
  }
}
