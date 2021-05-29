/*
 * DAC.h
 *
 *  Created on: May 28, 2021
 *      Author: Manraj Sangha
 */

#ifndef DAC_INC_DAC_H_
#define DAC_INC_DAC_H_

#include "stm32g4xx_hal.h"
#include <stdint.h>


void DAC_init(DAC_HandleTypeDef* hdac, uint32_t CHANNEL);

void DAC_write(DAC_HandleTypeDef* hdac, uint32_t val, uint32_t CHANNEL);


#endif /* DAC_INC_DAC_H_ */
