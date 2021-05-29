/*
 * DAC.c
 *
 *  Created on: May 28, 2021
 *      Author: jpaca
 */

#include "DAC.h"

extern DAC_HandleTypeDef hdac1;

void DAC_write(uint32_t val, uint32_t CHANNEL){
	HAL_DAC_SetValue(&hdac1, CHANNEL, DAC_ALIGN_12B_R, val);
}
