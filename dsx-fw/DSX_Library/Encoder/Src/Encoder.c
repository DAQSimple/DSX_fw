/*
 * Encoder.c
 *
 *  Created on: Jun 5, 2021
 *      Author: Manraj Sangha
 */

#include "Encoder.h"

volatile uint16_t Encoder_CPR = 0;		//Encoder counts per revolution

void Encoder_Set_CPR(uint16_t CPR_set){
	if(CPR_set == 0) CPR_set = ENCODER_DEFAULT_CPR;		//To avoid division by 0 set CPR to default
	Encoder_CPR = CPR_set;
}

void Encoder_Start(void){
	HAL_TIM_Base_Start_IT(&htim7);
	HAL_TIM_Encoder_Start(&htim4, TIM_CHANNEL_ALL);
}

void Encoder_Clear_Count(void){
	__HAL_TIM_SET_COUNTER(&htim4, 0);
}

uint16_t Encoder_Get_CPR(void){
	return Encoder_CPR;
}

uint8_t Encoder_Get_DIR(void){
	//Direction is stored in the CR1 register of TIM4
	return (TIM4->CR1 & TIM_CR1_DIR_Msk) >> TIM_CR1_DIR_Pos;
}


int16_t Encoder_Read_Count(){
	return __HAL_TIM_GET_COUNTER(&htim4);
}

//NOTE: Max reliable frequency is 64Hz
int32_t Encoder_Read_Freq(void){
	return Encoder_freq;		//returns value in Hz
}

int32_t Encoder_Read_RPM(void){
	return Encoder_rpm;
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if(htim->Instance == TIM7){
		//need to divide frequency by 2 since encoder read always counts both rising and falling edges
		Encoder_freq = (SAMPLING_FREQ_TIM7 * abs(Encoder_Read_Count())) / 2;
		Encoder_rpm = (Encoder_freq * 60)/ Encoder_Get_CPR();
		Encoder_Clear_Count();
	}
}
