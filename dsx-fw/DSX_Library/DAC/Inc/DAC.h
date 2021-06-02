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

//Function to initialize DAC1 Channel1 and 2
void DAC_init(void);

//Function to write to DAC Channel
void DAC_write(uint32_t val, uint32_t CHANNEL);

#endif /* DAC_INC_DAC_H_ */
