/*
 * Encoder.c
 *
 *  Created on: Jun 5, 2021
 *      Author: Manraj Sangha
 */


#include "Encoder.h"

volatile uint16_t CPR = 0;

void Encoder_Set_CPR(uint16_t CPR_set){
	  TIM4->ARR = CPR_set;		//Change the TIM4_ARR register to specified CPR
	  CPR = CPR_set;
}

void Encoder_Clear_Count(void){
	__HAL_TIM_SET_COUNTER(&htim4, 0);
}

uint16_t Encoder_Get_CPR(void){
	return CPR;
}

int32_t Encoder_Read_Count(){
	return __HAL_TIM_GET_COUNTER(&htim4);
}

int32_t Encoder_Read_Freq(void){
	return freq;
}

int32_t Encoder_Read_RPM(void){
	return rpm;
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == TIM3)
	{
		freq = (SAMPLING_FREQ * Encoder_Read_Count()) / 2;	// encoder read always counts both rising and falling edges
		rpm = (freq * 60)/ Encoder_Get_CPR();
		Encoder_Clear_Count();
	}
}
