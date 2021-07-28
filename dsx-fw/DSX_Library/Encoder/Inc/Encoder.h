/*
 * Encoder.h
 *
 *  Created on: Jun 5, 2021
 *      Author: Manraj Sangha
 */

#ifndef ENCODER_H_
#define ENCODER_H_

#include <stdint.h>
#include <stdlib.h>
#include "main.h"
#include "stdlib.h"		// for the abs() function

#define SAMPLING_FREQ_TIM7  	(4U)				//Sampling rate of timer 7 in Hz
#define ENCODER_DEFAULT_CPR 	(100U)				//Default encoder counts per revolution
#define ENCODER_INT_ENABLED 	(1)
#define ENCODER_INT_DISABLED 	(0)

volatile static uint32_t Encoder_freq = 0;		//Encoder frequency
volatile static uint32_t Encoder_rpm = 0;		//Encoder RPM

//Timer handle for timers 4 and 7
extern TIM_HandleTypeDef htim4;
extern TIM_HandleTypeDef htim7;

//Sets the Counts per revolution (CPR) of the encoder
//NOTE: Max counts is 65535
void Encoder_Set_CPR(uint16_t CPR_set);

//Function to start encoder timer and sampling timer
//NOTE: CPR should be set before calling
void Encoder_Start(void);

void Disable_Encoder_INT(void);

void Enable_Encoder_INT(void);

//Function to clear the current encoder count
void Encoder_Clear_Count(void);

//Function returns the CPR used to calculate RPM
uint16_t Encoder_Get_CPR(void);

//Function return the direction of encoder
//NOTE:
// 0 is counting up
// 1 is counting down
uint8_t Encoder_Get_DIR(void);

// Returns the encoder sign
// 0 = negative encoder count
// 1 = positive encoder count
uint8_t Encoder_Get_Sign(void);

//Function returns the current encoder count
int16_t Encoder_Read_Count(void);

//Function returns the current frequency
int32_t Encoder_Read_Freq(void);

//Function returns the current RPM
int32_t Encoder_Read_RPM(void);

//Function to set Encoder Frequency in timer interrupt library
void Encoder_Set_Freq(uint32_t freq);

//Function to set Encoder RPM in timer interrupt library
void Encoder_Set_RPM(uint32_t rpm);

#endif
