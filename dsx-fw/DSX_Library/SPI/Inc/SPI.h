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

// Macros for different SPI modes
/*
 	 Mode	CPOL	CPHA
 	  0		 0		 0
 	  1		 0		 1
 	  2		 1		 0
 	  3		 1 		 1
*/
#define SPI_MODE_0 0
#define SPI_MODE_1 1
#define SPI_MODE_2 2
#define SPI_MODE_3 3

//SPI handler
extern SPI_HandleTypeDef hspi3;

//Function to set SPI mode
void SPI_Set_Mode(uint8_t mode);

//Function to set frequency of SPI
//Clock freq = 170 Mhz
//SPI freq = (170Mhz)/prescaler
void SPI_Set_Prescaler(uint16_t prescaler);

//Initializes SPI
void SPI_Init(void);

//Function to change SPI_Tx_Buffer value
void SPI_Write(uint8_t data);

//Function return SPI_Rx_Buffer value
uint8_t SPI_Read(void);

//Function to transmit and receive SPI_Tx_Buffer and SPI_Rx_Buffer values
void SPI_TransmitReceive(void);

#endif /* SPI_H_ */
