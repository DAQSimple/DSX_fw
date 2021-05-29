/*
 * DAC.c
 *
 *  Created on: May 28, 2021
 *      Author: Manraj Sangha
 */

#include "DAC.h"

void DAC_init(DAC_HandleTypeDef* hdac, uint32_t CHANNEL){
	HAL_DAC_Start(hdac, CHANNEL);
}

void DAC_write(DAC_HandleTypeDef* hdac, uint32_t val, uint32_t CHANNEL){
	HAL_DAC_SetValue(hdac, CHANNEL, DAC_ALIGN_12B_R, val);
}
