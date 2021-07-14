/*
 * command.h
 *
 *  Created on: May 26, 2021
 *      Author: jpaca
 */

#ifndef COMMAND_H
#define COMMAND_H

#include "main.h"
#include "channel.h"
#include "adc.h"
#include "DAC.h"
#include "dsx_data_structure.h"
#include "validate.h"
#include "serial.h"
#include "PWM.h"
#include "board_defines.h"
#include "Encoder.h"
#include "Servo.h"


// Do we need these?
#define CMD_READY_TO_EXECUTE 		1
#define CMD_NOT_READY_TO_EXECUTE	0

// Macros to compare with the ID in the DSX data structure
#define CMD_DIGITAL_WRITE			10
#define CMD_DIGITAL_READ       		11
#define CMD_GET_PIN_MODE       		12
#define CMD_ANALOG_READ				13
#define CMD_PWM_WRITE				14
#define CMD_SET_PWM_FREQ			15
#define CMD_SERVO_WRITE				16
#define CMD_ENCODER_READ_RPM		17
#define CMD_GET_SERIAL_INFO			18
#define CMD_GET_SYS_STATUS			19
#define CMD_DAC_WRITE				20
#define CMD_LIMIT_SWITCH			21
#define	CMD_SPI_WRITE				22
#define CMD_I2C_WRITE				23
#define CMD_WAVEFORM_WRITE			24
#define CMD_ENCODER_READ_COUNT		29

#define CMD_I2C_READ				30

// Return commands to SIMULINK
#define RETURN_DIGITAL_READ			1
#define RETURN_PIN_MODE				2
#define RETURN_ANALOG_READ			3
#define RETURN_ENCODER_VELO			4
#define RETURN_SERIAL_INFO			5
//#define CMD_COMPLETE_PING			9
//#define CMD_EXECUTED				8888

// Sign bits
#define POSITIVE 					1
#define NEGATIVE					0


// Digital Write Command
void cmd_digital_write(volatile DSX_data_t *dsx_data);

// Digital Read Command
void cmd_digital_read(volatile DSX_data_t *dsx_data);

// Get Pin Mode Command
void cmd_get_pin_mode(volatile DSX_data_t *dsx_data);

// Analog Read Command
void cmd_analog_read(volatile DSX_data_t *dsx_data);

// PWM Write Command
void cmd_pwm_write(volatile DSX_data_t *dsx_data);

// Set PWM Frequency Command
void cmd_set_pwm_freq(volatile DSX_data_t *dsx_data);

// Servo Write Command
void cmd_servo_write(volatile DSX_data_t *dsx_data);

// Read Encoder Speed and Direction Command
void cmd_encoder_read_rpm(volatile DSX_data_t *dsx_data);

// Read Encoder Count
void cmd_encoder_read_count(volatile DSX_data_t *dsx_data);

// Get Serial Info Command
void cmd_get_serial_info(volatile DSX_data_t *dsx_data);

// Get System Status Command
void cmd_get_system_status(volatile DSX_data_t *dsx_data);

// DAC Write Command
void cmd_dac_write(volatile DSX_data_t *dsx_data);

// Set PWM Level Command
void cmd_limit_switch(volatile DSX_data_t *dsx_data);

// Write SPI Command
void cmd_spi_write(volatile DSX_data_t *dsx_data);

// Write I2C Command
void cmd_i2c_write(volatile DSX_data_t *dsx_data);

// Read I2C Command
void cmd_i2c_read(volatile DSX_data_t *dsx_data);

// Generate Waveform Command
void cmd_generate_waveform(volatile DSX_data_t *dsx_data);

// *** Main Execute Command ***
void execute_command(volatile DSX_data_t *dsx_data);


#endif /* COMMAND_H */
