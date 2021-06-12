/*
 * tim_interrupt.c
 *
 *  Created on: Jun 12, 2021
 *      Author: jpaca
 */

#include "timer_interrupt.h"


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	static uint8_t mux_channel_AB = 0;	// For cycling through the Multiplex Control Array for MUX pair A and B
	static uint8_t mux_channel_C  = 0;	// For cycling through the Multiplex Control Array for MUX C

	// MultiplexAB_100Hz_Control and temp/current read ISR
	// Uses Timer2, PSC=170-1, Period=10000-1. Result is an update freq=100Hz.
	if(htim->Instance == TIM2) 		// if the interrupt source is timer 2
	{
		HAL_GPIO_WritePin(MUXA_S0_GPIO_Port, MUXA_S0_Pin, MUXAB_CH_Select_S0(mux_channel_AB));	// Goes to Multiplexer Control pin S0
		HAL_GPIO_WritePin(MUXA_S1_GPIO_Port, MUXA_S1_Pin, MUXAB_CH_Select_S1(mux_channel_AB));	// Goes to Multiplexer Control pin S1
		HAL_GPIO_WritePin(MUXA_S2_GPIO_Port, MUXA_S2_Pin, MUXAB_CH_Select_S2(mux_channel_AB));	// Goes to Multiplexer Control pin S2
		HAL_GPIO_WritePin(MUXA_S3_GPIO_Port, MUXA_S3_Pin, MUXAB_CH_Select_S3(mux_channel_AB));	// Goes to Multiplexer Control pin S3

		HAL_GPIO_WritePin(MUXB_S0_GPIO_Port, MUXB_S0_Pin, MUXB_CH_Select_S0(mux_channel_AB));	// Goes to Multiplexer Control pin S0

		// Go to the next channel, wrap at the end channel
		mux_channel_AB = (mux_channel_AB == MUX_CHANNEL_END) ? MUX_CHANNEL_0 : mux_channel_AB+1;

		// Check temperature and current
		if(temp_current_buf[0] > MAX_TEMP_ALLOWED)     state = STATE_FAULT_OVER_TEMP;
		if(temp_current_buf[1] > MAX_POSITIVE_CURRENT) state = STATE_FAULT_OVER_CURR;
//		if(temp_current_buf[1] < MAX_NEGATIVE_CURRENT) state = STATE_FAULT_OVER_CURR;	// UNCOMMENT THIS IN THE FIRMWARE VERSION FOR THE COMPLETED SHIELD
	}

	// MultiplexC_400Hz_Control ISR
	// Uses Timer5, PSC=170-1, Period=2500-1. Result is an update freq=400Hz.
	if(htim->Instance == TIM5)
	{
		HAL_GPIO_WritePin(MUXC_S0_GPIO_Port, MUXC_S0_Pin, MUXC_CH_Select_S0(mux_channel_C));	// Goes to Multiplexer Control pin S0
		mux_channel_C ^= 0x1;
	}

	// 4 Hz for calculating encoder freq and rpm
	if(htim->Instance == TIM7){
		//need to divide frequency by 2 since encoder read always counts both rising and falling edges
		Encoder_freq = (SAMPLING_FREQ_TIM7 * abs(Encoder_Read_Count())) / 2;
		Encoder_rpm = (Encoder_freq * 60)/ Encoder_Get_CPR();
		Encoder_Clear_Count();
	}
}
