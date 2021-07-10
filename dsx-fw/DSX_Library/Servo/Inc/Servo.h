/*
 * Servo.h
 *
 *  Created on: Jun 17, 2021
 *      Author: Harjapp
 */

#ifndef SERVO_H
#define SERVO_H

#define SERVO_FREQ		50			// Servo motors are operated at 20ms intervals or 50 Hz.
#define SERVO_PERIOD	999			// Period is 1000-1
#define MAX_DEGREES		180			// Rotate the servo from 0-180 degrees
#define MIN_DEGREES		0

// Numbers can be changed slightly to match the specs of a motor
#define MAX_DUTYCYCL	124			// 125-1. Max duty cycle is MAX_DUTYCYCL/SERVO_PERIOD = 12.5% = +90 degrees
#define MIN_DUTYCYCL	24			// 25-1. Min duty cycle is MAX_DUTYCYCL/SERVO_PERIOD = 2.5% = -90 degrees

#include "main.h"
#include "PWM.h"

// Function used to control a Servo using either PWM pin
void writeServo (TIM_HandleTypeDef htim, uint8_t dutyCycle);

#endif
