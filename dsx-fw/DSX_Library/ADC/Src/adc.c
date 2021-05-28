/*
 * adc.c
 *
 *  Created on: May 26, 2021
 *      Author: Tim Saxon
 */

#include "adc.h"

//extern uint32_t adc_buf[NUM_ADC_CHANNELS];

// Define buffer to store ADC readings
// 32-bit integer is required for proper readings

uint32_t volatile adc_buf[NUM_ADC_CHANNELS];

// Make ADC start continuously reading values and storing in adc_buf
//void Start_ADC(uint32_t *buf){

void Start_ADC(void){
	HAL_ADC_Start_DMA(&hadc1, (uint32_t *)adc_buf, NUM_ADC_CHANNELS);
}

//Callback to occur when ADC has read 2 of 4 channels
void HAL_ADC_ConvHalfCpltCallback(ADC_HandleTypeDef *hadc){

	UNUSED(hadc); // nothing for now

}

//Callback to occur when ADC has read all 4 channels
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc){

	UNUSED(hadc); // nothing for now

}


 //Pull a single channel reading from the ADC buffer
uint16_t read_ADC_channel(uint8_t channel){

	return(adc_buf[channel]); // return specified ADC channel reading

}


// Can just use adc_buf for this
//// Pull all four channel readings from the ADC buffer
//uint16_t read_ADC_all(void){
//
//	return(adc_buf); // return specified ADC channel reading
//
//}
