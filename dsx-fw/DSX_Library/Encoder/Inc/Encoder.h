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

extern TIM_HandleTypeDef htim1;

void Encoder_Init(uint16_t CPR);

#endif /* ENCODER_H_ */
