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

// Function to convert current reading to a mA value
uint32_t to_current_mA(uint32_t current_adc_reading)
{
	return abs(0.029*current_adc_reading - 59.26);
}

// Function to calculate total output current
uint16_t Get_Total_Output_Current(volatile uint8_t mux_channel_A, volatile uint8_t mux_channel_B)
{
	static uint16_t total_current = 0;
	volatile static uint16_t ch_output_current[6];	//DSX has 6 output pins
	if(mux_channel_A == MUXA_CHANNEL_8)  ch_output_current[0] = to_current_mA(get_current_reading());
	if(mux_channel_A == MUXA_CHANNEL_9)  ch_output_current[1] = to_current_mA(get_current_reading());
	if(mux_channel_A == MUXA_CHANNEL_10) ch_output_current[2] = to_current_mA(get_current_reading());
	if(mux_channel_A == MUXA_CHANNEL_11) ch_output_current[3] = to_current_mA(get_current_reading());
	if(mux_channel_B == MUXB_CHANNEL_0)  ch_output_current[4] = to_current_mA(get_current_reading());
	if(mux_channel_B == MUXB_CHANNEL_1)  ch_output_current[5] = to_current_mA(get_current_reading());

	if(mux_channel_A == MUXA_CHANNEL_11)	// Calculate total current once mux A gets to channel 11
	{
		for(int i=0; i<6; i++)
		{
			total_current += ch_output_current[i];
		}
	}

	return total_current;
}

// Fault event handlers
DSX_data_t DSX_Fault_Handler(uint8_t state)
{
	// SOS message
	DSX_data_t SOS;

	switch(state)
	{
	case STATE_FAULT_OVER_CURR:
		HAL_GPIO_WritePin(MUX_En_GPIO_Port, MUX_En_Pin, DISABLE_MUX);  // DISABLE MUX
		SOS.ID=22;
		SOS.loc=0;
		SOS.ret=0;
		SOS.sign=0;
		SOS.val=420; // val based on lookup table fault code
		break;

	case STATE_FAULT_OVER_TEMP:
		SOS.ID=22;
		SOS.loc=0;
		SOS.ret=0;
		SOS.sign=0;
		SOS.val=421;
		break;

	case STATE_FAULT_REV_POL:
		SOS.ID=22;
		SOS.loc=0;
		SOS.ret=0;
		SOS.sign=0;
		SOS.val=422;
		break;

	case STATE_FAULT_USB:
		SOS.ID=22;
		SOS.loc=0;
		SOS.ret=0;
		SOS.sign=0;
		SOS.val=423;
		break;

	case STATE_FAULT_UART:
		SOS.ID=22;
		SOS.val=424;
		break;

	case STATE_FAULT_LIMIT_SW:
		updateDutyCycle(htim16, 0);	// Disable PWM
		updateDutyCycle(htim17, 0); // Disable PWM
		SOS.ID=22;
		SOS.loc=0;
		SOS.ret=0;
		SOS.sign=0;
		SOS.val=425;
		break;
	}

	return SOS;
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
