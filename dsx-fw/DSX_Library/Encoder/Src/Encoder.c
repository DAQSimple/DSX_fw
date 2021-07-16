/*
 * Encoder.c
 *
 *  Created on: Jun 5, 2021
 *      Author: Manraj Sangha
 */

#include "Encoder.h"

volatile uint16_t Encoder_CPR = 0;			//Encoder counts per revolution
volatile uint8_t  Encoder_INT_Status = 0; 	//Status of timer interrupt 7
volatile int16_t  Encoder_Count = 0;

void Encoder_Set_CPR(uint16_t CPR_set){
	if(CPR_set == 0) CPR_set = ENCODER_DEFAULT_CPR;		//To avoid division by 0 set CPR to default
	Encoder_CPR = CPR_set*2;
}

void Encoder_Start(void){
	Encoder_Set_CPR(100); 								// default CPR
	HAL_TIM_Base_Start_IT(&htim7);
	HAL_TIM_Encoder_Start(&htim4, TIM_CHANNEL_ALL);
	Encoder_INT_Status = ENCODER_INT_ENABLED;			//Set status to enabled
}

void Disable_Encoder_INT(void){
	if(Encoder_INT_Status == ENCODER_INT_DISABLED) return;
	HAL_TIM_Base_Stop_IT(&htim7);
	Encoder_INT_Status = ENCODER_INT_DISABLED;			//Set status to enabled
}

void Enable_Encoder_INT(void){
	if(Encoder_INT_Status == ENCODER_INT_ENABLED) return;
	HAL_TIM_Base_Start_IT(&htim7);
	Encoder_INT_Status = ENCODER_INT_ENABLED;			//Set status to enabled
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
	Encoder_Count = __HAL_TIM_GET_COUNTER(&htim4);
	if(Encoder_Count > Encoder_CPR && Encoder_INT_Status == ENCODER_INT_DISABLED){
		Encoder_Clear_Count();
	}
	else if(Encoder_Count < 0 && Encoder_INT_Status == ENCODER_INT_DISABLED){
		__HAL_TIM_SET_COUNTER(&htim4, Encoder_CPR);
	}
	Encoder_Count = __HAL_TIM_GET_COUNTER(&htim4);
	return Encoder_Count / 2;
}

//NOTE: Max reliable frequency is 64Hz
int32_t Encoder_Read_Freq(void){
	return Encoder_freq;		//returns value in Hz
}

int32_t Encoder_Read_RPM(void){
	return Encoder_rpm;
}

//Function to set Encoder Frequency in timer interrupt library
void Encoder_Set_Freq(uint32_t freq){
	Encoder_freq = freq;
}

//Function to set Encoder RPM in timer interrupt library
void Encoder_Set_RPM(uint32_t rpm){
	Encoder_rpm = rpm;
}
