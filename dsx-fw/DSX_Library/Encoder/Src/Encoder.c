/*
 * Encoder.c
 *
 *  Created on: Jun 5, 2021
 *      Author: Manraj Sangha
 */
#include "Encoder.h"

void Encoder_Set_CPR(uint16_t CPR){
	  TIM4->ARR = CPR;		//Change the TIM4_ARR register to specified CPR
}

uint16_t Encoder_read(){
	return __HAL_TIM_GET_COUNTER(&htim4);
}
