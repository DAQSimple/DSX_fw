
#ifndef _PWM_H_
#define _PWM_H_

/* Macros that store the min and max values for the
 * frequency and duty cycle
 */
#define PWM_Max 1700000
#define PWM_Min 34
#define dutyCycle_Max 100
#define dutyCycle_Min 0

#include "main.h"

// Timer handles
extern TIM_HandleTypeDef htim16;
extern TIM_HandleTypeDef htim17;

// Functions to set the duty cycle and frequency for the two channels
void updateDutyCycle (uint8_t dutyCycle);
void updatePWMFrequency (uint32_t pwm_freq);

/* Function to generate a PWM signal a timer with its corresponding
 * timer handle and channel number
 */
void gen_PWM (TIM_HandleTypeDef* htimNum, uint32_t Channel);

#endif
