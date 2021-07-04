/*
 * SPI.c
 *
 *  Created on: Jul. 2, 2021
 *      Author: Manraj Sangha
 */

#include "SPI.h"

static uint8_t SPI_Rx = 0;
static uint8_t SPI_Tx = 0;

void SPI_Set_Mode(uint8_t mode){
	switch(mode){
		case 0:
			hspi3.Init.CLKPolarity = SPI_POLARITY_LOW;
			hspi3.Init.CLKPhase = SPI_PHASE_1EDGE;
			break;
		case 1:
			hspi3.Init.CLKPolarity = SPI_POLARITY_LOW;
			hspi3.Init.CLKPhase = SPI_PHASE_2EDGE;
			break;
		case 2:
			hspi3.Init.CLKPolarity = SPI_POLARITY_HIGH;
			hspi3.Init.CLKPhase = SPI_PHASE_1EDGE;
			break;
		case 3:
			hspi3.Init.CLKPolarity = SPI_POLARITY_HIGH;
			hspi3.Init.CLKPhase = SPI_PHASE_2EDGE;
			break;
		default:
			hspi3.Init.CLKPolarity = SPI_POLARITY_LOW;
			hspi3.Init.CLKPhase = SPI_PHASE_1EDGE;
			break;
	}
}

void SPI_Init(void){
	SPI_Set_Mode(SPI_MODE_0);
	HAL_SPI_Init(&hspi3);
}

void SPI_Write(uint8_t address){
	SPI_Tx = address;
	SPI_TransmitRecieve();
}

uint8_t SPI_Read(void){
	SPI_TransmitRecieve();
	return SPI_Rx;
}

void SPI_TransmitRecieve(void){
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);
	HAL_SPI_TransmitReceive(&hspi3, &SPI_Tx, &SPI_Rx, 1, 100);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);
}
