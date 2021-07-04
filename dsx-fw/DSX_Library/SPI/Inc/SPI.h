/*
 * SPI.h
 *
 *  Created on: Jul. 2, 2021
 *      Author: Manraj Sangha
 */

#ifndef SPI_H_
#define SPI_H_

#include<stdint.h>
#include "main.h"

#define SPI_MODE_0 0
#define SPI_MODE_1 1
#define SPI_MODE_2 2
#define SPI_MODE_3 3

extern SPI_HandleTypeDef hspi3;

void SPI_Set_Mode(uint8_t mode);

void SPI_Init(void);

void SPI_Write(uint8_t address);

uint8_t SPI_Read(void);

void SPI_TransmitRecieve(void);

#endif /* SPI_H_ */
