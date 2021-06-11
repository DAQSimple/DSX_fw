/*
 * Encoder.h
 *
 *  Created on: Jun 5, 2021
 *      Author: Manraj Sangha
 */

#ifndef ENCODER_H_
#define ENCODER_H_

#include <stdint.h>
#include "main.h"

volatile static uint32_t freq = 0;
volatile static uint32_t rpm = 0;

#define SAMPLING_FREQ (4U)

extern TIM_HandleTypeDef htim4;

void Encoder_Set_CPR(uint16_t CPR_set);

void Encoder_Clear_Count(void);

uint16_t Encoder_Get_CPR(void);

int32_t Encoder_Read_Count(void);

int32_t Encoder_Read_Freq(void);

int32_t Encoder_Read_RPM(void);


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);

#endif

