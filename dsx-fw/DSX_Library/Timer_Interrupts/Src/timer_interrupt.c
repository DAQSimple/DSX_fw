/*
 * tim_interrupt.c
 *
 *  Created on: Jun 12, 2021
 *      Author: jpaca
 */

#include "timer_interrupt.h"
#include "safety.h"
#include "Encoder.h"


// Array of arrays for controlling dual multiplexers
uint8_t Multiplex_Control_Arr_2CH_1Sel[2] = {
		0,	/* Select multiplexer channel 0 */
		1,	/* Select multiplexer channel 1 */
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


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	// MultiplexAB_100Hz_Control and temp/current read ISR
	// Uses Timer2, PSC=170-1, Period=10000-1. Result is an update freq=100Hz.
	if(htim->Instance == TIM2) 		// if the interrupt source is timer 2
	{
		volatile static uint8_t mux_channel_A = 0;	// For cycling through the Multiplex Control Array for MUX pair A
		volatile static uint8_t mux_channel_B = 0;	// For cycling through the Multiplex Control Array for MUX pair B

		HAL_GPIO_WritePin(MUXA_S0_GPIO_Port, MUXA_S0_Pin, Multiplex_Control_Arr_16CH_4Sel[mux_channel_A][0]);	// Goes to Multiplexer Pair A Control pin S0
		HAL_GPIO_WritePin(MUXA_S1_GPIO_Port, MUXA_S1_Pin, Multiplex_Control_Arr_16CH_4Sel[mux_channel_A][1]);	// Goes to Multiplexer Pair A Control pin S1
		HAL_GPIO_WritePin(MUXA_S2_GPIO_Port, MUXA_S2_Pin, Multiplex_Control_Arr_16CH_4Sel[mux_channel_A][2]);	// Goes to Multiplexer Pair A Control pin S2
		HAL_GPIO_WritePin(MUXA_S3_GPIO_Port, MUXA_S3_Pin, Multiplex_Control_Arr_16CH_4Sel[mux_channel_A][3]);	// Goes to Multiplexer Pair A Control pin S3

		mux_channel_B = mux_channel_A % 2;
		HAL_GPIO_WritePin(MUXB_S0_GPIO_Port, MUXB_S0_Pin, Multiplex_Control_Arr_2CH_1Sel[mux_channel_B]);	// Goes to Multiplexer Pair B Control pin S0

		// Go to the next channel, wrap at the end channel
		mux_channel_A = (mux_channel_A == MUXA_CHANNEL_END) ? MUXA_CHANNEL_0 : mux_channel_A+1;

		// Check temperature and current threshholds
		if(get_temp_reading() > MAX_TEMP_ALLOWED)        state = STATE_FAULT_OVER_TEMP;
//		if(get_current_reading() > MAX_POSITIVE_CURRENT) state = STATE_FAULT_OVER_CURR;
//		if(get_current_reading() < MAX_NEGATIVE_CURRENT) state = STATE_FAULT_OVER_CURR;	// UNCOMMENT THIS IN THE FIRMWARE VERSION FOR THE COMPLETED SHIELD

		// Check 100 mA output current threshhold
//		if(Get_Total_Output_Current(mux_channel_A,mux_channel_B) > MAX_OUTPUT_CURRENT) state = STATE_FAULT_OVER_CURR;
	}

	// MultiplexC_400Hz_Control ISR
	// Uses Timer5, PSC=170-1, Period=2500-1. Result is an update freq=400Hz.
	if(htim->Instance == TIM5)
	{
		volatile static uint8_t mux_channel_C  = 0;	// For cycling through the Multiplex Control Array for MUX C
		HAL_GPIO_WritePin(MUXC_S0_GPIO_Port, MUXC_S0_Pin, Multiplex_Control_Arr_2CH_1Sel[mux_channel_C]);	// Goes to Multiplexer Control pin S0
		mux_channel_C ^= 0x1;
	}

	// 4 Hz for calculating encoder freq and rpm
	if(htim->Instance == TIM7){
		volatile static uint32_t Encoder_freq;
		volatile static uint32_t Encoder_rpm;

		//need to divide frequency by 2 since encoder read always counts both rising and falling edges
		Encoder_freq = SAMPLING_FREQ_TIM7 * abs(Encoder_Read_Count());
		Encoder_Set_Freq(Encoder_freq);
		Encoder_rpm = (Encoder_freq * 60)/ Encoder_Get_CPR();
		Encoder_Set_RPM(Encoder_rpm);
		Encoder_Clear_Count();
	}
}
