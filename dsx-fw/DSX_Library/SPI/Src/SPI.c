/*
 * SPI.c
 *
 *  Created on: Jul. 2, 2021
 *      Author: Manraj Sangha
 */

#include "SPI.h"

static uint8_t SPI_Rx_Buffer = 0;		//Buffer to hold received data
static uint8_t SPI_Tx_Buffer = 0;		//Buffer to hold data to be transmitted

void SPI_Set_Mode(uint8_t mode){
	switch(mode){
		case SPI_MODE_0:
			hspi3.Init.CLKPolarity = SPI_POLARITY_LOW;
			hspi3.Init.CLKPhase = SPI_PHASE_1EDGE;
			break;
		case SPI_MODE_1:
			hspi3.Init.CLKPolarity = SPI_POLARITY_LOW;
			hspi3.Init.CLKPhase = SPI_PHASE_2EDGE;
			break;
		case SPI_MODE_2:
			hspi3.Init.CLKPolarity = SPI_POLARITY_HIGH;
			hspi3.Init.CLKPhase = SPI_PHASE_1EDGE;
			break;
		case SPI_MODE_3:
			hspi3.Init.CLKPolarity = SPI_POLARITY_HIGH;
			hspi3.Init.CLKPhase = SPI_PHASE_2EDGE;
			break;
		default:
			hspi3.Init.CLKPolarity = SPI_POLARITY_LOW;
			hspi3.Init.CLKPhase = SPI_PHASE_1EDGE;
			break;
	}
}

void SPI_Set_Prescaler(uint16_t prescaler){
	switch(prescaler){
		case 4:
			hspi3.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_4;
			break;
		case 8:
			hspi3.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_8;
			break;
		case 16:
			hspi3.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_16;
			break;
		case 32:
			hspi3.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_32;
			break;
		case 64:
			hspi3.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_64;
			break;
		case 128:
			hspi3.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_128;
			break;
		case 256:
			hspi3.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_256;
			break;
		default:
			hspi3.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_128;
			break;
	}
}

void SPI_Init(void){
	//Default setting for SPI are in mode 0 and prescaler set to 128
	SPI_Set_Mode(SPI_MODE_0);
	SPI_Set_Prescaler(128);
	HAL_SPI_Init(&hspi3);
}

void SPI_Write(uint8_t data){
	SPI_Tx_Buffer = data;			//Set SPI_Tx_Buffer to data to be transmitting
	SPI_TransmitReceive();			//Start transmission
}

uint8_t SPI_Read(void){
	SPI_TransmitReceive();			//Start receiving data
	return SPI_Rx_Buffer;			//Return data in SPI_Rx_Buffer
}

void SPI_TransmitReceive(void){
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);						//Pull CS pin down to start SPI communication
	HAL_SPI_TransmitReceive(&hspi3, &SPI_Tx_Buffer, &SPI_Rx_Buffer, 1, 100);	//Transmit and receive data
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);						//Pull CS pin up to stop communication
}
