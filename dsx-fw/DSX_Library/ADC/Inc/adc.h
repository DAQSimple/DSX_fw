/*
 * adc.h
 *
 *  Created on: May 26, 2021
 *      Author: 16047
 */

#ifndef DSX_ADC_H
#define DSX_ADC_H

#include "main.h"

#define NUM_ADC_CHANNELS 6U

// Import adc handle from main.c for use in adc.c
extern ADC_HandleTypeDef hadc1;

// ADC buffer
extern uint32_t volatile adc_buf[NUM_ADC_CHANNELS];

// Function to start infinite ADC conversion loop
void Start_ADC(void);
//void Start_ADC(void);

// Function to read a single ADC channel
uint16_t read_ADC_channel(uint8_t channel);

// Callbacks
void HAL_ADC_ConvHalfCpltCallback(ADC_HandleTypeDef *hadc);
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc);


#endif /* DSX_ADC_H */
