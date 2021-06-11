/*
 * Author of driver: Harjaap
 * Date: 6/2/2021
 * DAQSimple
 *
 */


#ifndef _PWM_H_
#define _PWM_H_

/* Macros that store the min and max values for the
 * frequency and duty cycle
 */
#define PWM_Max 		1700000U         // Max available after dividing the clock clock by the period
#define PWM_Min 		26U              // Min as prescaler can be up to 65535. PWM_Min = PWM_Max/65384
#define dutyCycle_Max 	100U
#define dutyCycle_Min 	0
#define CLOCK_SPEED		170000000UL

#include "main.h"

// Functions to set the duty cycle and frequency for the two channels
void updateDutyCycle (TIM_HandleTypeDef htim, uint8_t dutyCycle);
void updatePWMFrequency (TIM_HandleTypeDef htim, uint32_t pwm_freq);

// Function to start the timers for the PWM signals
void initPWM(void);

#endif
