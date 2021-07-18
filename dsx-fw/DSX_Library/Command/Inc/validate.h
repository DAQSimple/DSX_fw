/*
 * validate.h
 *
 *  Created on: May 26, 2021
 *      Author: jpaca
 */

#ifndef VALIDATE_H
#define VALIDATE_H

#include "main.h"
#include "dsx_data_structure.h"
#include "command.h"
#include <stdbool.h>
#include "board_defines.h"
#include "i2c.h"

// Validate Digital Write Command
bool validate_digital_write(volatile DSX_data_t *dsx_data);

// Validate Digital Read Command
bool validate_digital_read(volatile DSX_data_t *dsx_data);

// Validate Get Pin Mode Command
bool validate_get_pin_mode(volatile DSX_data_t *dsx_data);

// Validate Analog Read Command
bool validate_analog_read(volatile DSX_data_t *dsx_data);

// Validate PWM Write Command
bool validate_pwm_write(volatile DSX_data_t *dsx_data);

// Validate Set PWM Frequency Command
bool validate_set_PWM_freq(volatile DSX_data_t *dsx_data);

// Validate Servo Write Command
bool validate_servo_write(volatile DSX_data_t *dsx_data);

// Validate Read Encoder Count Command
bool validate_set_encoder_cpr(volatile DSX_data_t *dsx_data);

// Validate Read Encoder Speed and Direction Command
bool validate_read_encoder(volatile DSX_data_t *dsx_data);

// Validate Get Serial Info Command
bool validate_get_serial_info(volatile DSX_data_t *dsx_data);

// Validate Get System Status Command
bool validate_get_sys_status(volatile DSX_data_t *dsx_data);

// Validate DAC Write Command
bool validate_dac_write(volatile DSX_data_t *dsx_data);

// Validate Set PWM Level Command
bool validate_limit_switch(volatile DSX_data_t *dsx_data);

// Validate Write SPI Command
bool validate_spi_write(volatile DSX_data_t *dsx_data);

// Validate Write I2C Command
bool validate_i2c_write(volatile DSX_data_t *dsx_data);

// Validate Read I2C Command
bool validate_i2c_read(volatile DSX_data_t *dsx_data);

// Validate Generate Waveform Command
bool validate_generate_waveform_(volatile DSX_data_t *dsx_data);

// Validate SPI Set Mode Command
bool validate_spi_set_mode(volatile DSX_data_t *dsx_data);

// Validate SPI Set Prescaler Command
bool validate_spi_set_prescaler(volatile DSX_data_t *dsx_data);

// Validate Write SPI Command
bool validate_spi_write(volatile DSX_data_t *dsx_data);

// *** Main Validate Command ***
bool is_valid(volatile DSX_data_t *dsx_data);


#endif /* VALIDATE_H */
