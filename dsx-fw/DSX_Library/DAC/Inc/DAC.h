/*
 * DAC.h
 *
 *  Created on: May 28, 2021
 *      Author: Manraj Sangha
 */

#ifndef DAC_INC_DAC_H_
#define DAC_INC_DAC_H_

#include <stdint.h>
#include "stm32g4xx_hal.h"

//DAC1 handle
extern DAC_HandleTypeDef hdac1;

//Function to initialize DAC Channel
void DAC_init(uint32_t CHANNEL);

//Function to write to DAC Channel
void DAC_write(uint32_t val, uint32_t CHANNEL);

#endif /* DAC_INC_DAC_H_ */
