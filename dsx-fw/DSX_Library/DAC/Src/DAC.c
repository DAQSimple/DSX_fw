/*
 * DAC.c
 *
 *  Created on: May 28, 2021
 *      Author: jpaca
 */

#include "DAC.h"

//extern DAC_HandleTypeDef hdac1;


void DAC_init(DAC_HandleTypeDef* hdac, uint32_t CHANNEL){
	HAL_DAC_Start(hdac, CHANNEL);
}

void DAC_write(DAC_HandleTypeDef* hdac, uint32_t val, uint32_t CHANNEL){
	HAL_DAC_SetValue(hdac, CHANNEL, DAC_ALIGN_12B_R, val);
}
/*
void DAC_write(uint32_t val, uint32_t CHANNEL){
	HAL_DAC_SetValue(&hdac1, CHANNEL, DAC_ALIGN_12B_R, val);
}
*/
