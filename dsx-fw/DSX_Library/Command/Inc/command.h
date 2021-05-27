/*
 * command.h
 *
 *  Created on: May 26, 2021
 *      Author: jpaca
 */

#ifndef COMMAND_H
#define COMMAND_H


#define CMD_READY_TO_EXECUTE 		1
#define CMD_NOT_READY_TO_EXECUTE	0

// Macros to compare with the ID in the dsx data structure
#define CMD_DIGITAL_WRITE			10
#define CMD_DIGITAL_READ       		11
#define CMD_GET_PIN_MODE       		12
#define CMD_ANALOG_READ				13
#define CMD_PWM_WRITE				14
#define CMD_SET_PWM_FREQ			15
#define CMD_SERVO_WRITE				16
#define CMD_ENCODER_READ			17
#define CMD_GET_SERIAL_INFO			18
#define CMD_GET_SYS_STATUS			19
#define CMD_DAC_WRITE				20
#define CMD_SET_PWM_LEVEL			21
#define	CMD_SPI_WRITE				22
#define CMD_I2C_WRITE				23
#define CMD_WAVEFORM_WRITE			24


// Digital Write Command

// Digital Read Command

// Get Pin Mode Command

// Analog Read Command

// PWM Write Command

// Set PWM Frequency Command

// Servo Write Command

// Read Encoder Speed and Direction Command

// Get Serial Info Command

// Get System Status Command

// DAC Write Command

// Set PWM Level Command

// Write SPI Command

// Write I2C Command

// Generate Waveform Command


#endif /* COMMAND_H */
