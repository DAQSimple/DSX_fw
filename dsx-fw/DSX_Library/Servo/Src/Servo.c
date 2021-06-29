/*
 * Servo.c
 *
 *  Created on: Jun 17, 2021
 *      Author: Harjapp
 */

#include "Servo.h"

// Timer handles
extern TIM_HandleTypeDef htim16;
extern TIM_HandleTypeDef htim17;

void writeServo (TIM_HandleTypeDef htim, uint8_t degreesRotation){
	htim.Instance->ARR=SERVO_PERIOD;

	// Equation for setting the pre-scaler value based off the Servo frequency.
	htim.Instance->PSC = (CLOCK_SPEED/((htim.Instance->ARR + 1)*SERVO_FREQ)) - 1;

	// Calculate the duty cycle from the input degrees to rotate Servo
	uint8_t dutyCycle = MIN_DUTYCYCL + degreesRotation/1.8;
	htim.Instance->CCR1 = dutyCycle;
	HAL_TIM_PWM_Start(&htim, TIM_CHANNEL_1);
}
