/*
 * Encoder.c
 *
 *  Created on: Jun 5, 2021
 *      Author: Manraj Sangha
 */
#include "Encoder.h"

// ++ ADDED BY JAY PACAMARRA
volatile static uint32_t freq = 0;
volatile static uint32_t rpm = 0;
static int CPR = 48;
// ++ ADDED BY JAY PACAMARRA

void Encoder_Set_CPR(uint16_t CPR){
	  TIM4->ARR = CPR;		//Change the TIM4_ARR register to specified CPR
	  	  	  	  	  	  	 // wrong - jay :)
	  	  	  	  	  	  	  // you should create getter + setter for changing CPR
}

uint16_t Encoder_read(){
	return __HAL_TIM_GET_COUNTER(&htim4);
}

// ++ ADDED BY JAY PACAMARRA
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == TIM2)
	{
		freq = (Encoder_read() / 0.25) / 2;		// encoder read always counts both rising and falling edges
		rpm = (freq * 60)/ CPR;
		__HAL_TIM_SET_COUNTER(&htim4, 0);
	}
}
// ++ ADDED BY JAY PACAMARRA
