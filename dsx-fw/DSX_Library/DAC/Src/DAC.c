/*
 * DAC.c
 *
 *  Created on: May 28, 2021
 *      Author: Manraj Sangha
 */

#include "DAC.h"

//Function to initialize DAC1 Channel1 and 2
void DAC_init(void){
	HAL_DAC_Start(&hdac1, DAC1_CHANNEL_1);
	HAL_DAC_Start(&hdac1, DAC1_CHANNEL_2);
}

//Function to write to DAC Channel
//Input value must be 12-bit right aligned
void DAC_write(uint32_t val, uint32_t CHANNEL){
	HAL_DAC_SetValue(&hdac1, CHANNEL, DAC_ALIGN_12B_R, val);
}
