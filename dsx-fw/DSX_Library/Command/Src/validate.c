/*
 * validate.c
 *
 *  Created on: May 26, 2021
 *      Author: jpaca
 */

#include "validate.h"


// Validate Digital Write Command
bool validate_digital_write(volatile DSX_data_t *dsx_data){
	bool check_data = true;
	if(dsx_data->loc != 9 && dsx_data->loc != 10) check_data = false;
	if(dsx_data->sign != 1) check_data = false;
	if(dsx_data->val != 0 && dsx_data->val != 1) check_data = false;
	return check_data;
}

// Validate Digital Read Command
bool validate_digital_read(volatile DSX_data_t *dsx_data){
	bool check_data = true;
	if(dsx_data->loc < 1 && dsx_data->loc > 8) check_data = false;
	return check_data;
}

// Validate Get Pin Mode Command
bool validate_get_pin_mode(volatile DSX_data_t *dsx_data){};

// Validate Analog Read Command
bool validate_analog_read(volatile DSX_data_t *dsx_data){
	bool check_data = true;
	//if(dsx_data->loc < 13 && dsx_data->loc > 16) check_data = false;
	return check_data;
}

// Validate PWM Write Command
bool validate_pwm_write(volatile DSX_data_t *dsx_data){};

// Validate Set PWM Frequency Command
bool validate_set_PWM_freq(volatile DSX_data_t *dsx_data){};

// Validate Servo Write Command
bool validate_servo_write(volatile DSX_data_t *dsx_data){};

// Validate Read Encoder Speed and Direction Command
bool validate_read_encoder(volatile DSX_data_t *dsx_data){};

// Validate Get Serial Info Command
bool validate_get_serial_info(volatile DSX_data_t *dsx_data){};

// Validate Get System Status Command
bool validate_get_sys_status(volatile DSX_data_t *dsx_data){};

// Validate DAC Write Command
bool validate_dac_write(volatile DSX_data_t *dsx_data){
	bool check_data = true;
	if(dsx_data->loc != 17 && dsx_data->loc != 18) check_data = false;
	if(dsx_data->sign != 1) check_data = false;
	if(dsx_data->val < 0 && dsx_data->val > 4095) check_data = false;
	return check_data;
}

// Validate Set PWM Level Command
bool validate_set_pwm_level(volatile DSX_data_t *dsx_data){};

// Validate Write SPI Command
bool validate_spi_write(volatile DSX_data_t *dsx_data){};

// Validate Write I2C Command
bool validate_i2c_write(volatile DSX_data_t *dsx_data){};

// Validate Generate Waveform Command
bool validate_generate_waveform_(volatile DSX_data_t *dsx_data){};

// *** Main Validate Command ***
bool is_valid(volatile DSX_data_t *dsx_data)
{
	bool dsx_data_valid = false; // assume dsx data invalid at the start

	if(dsx_data->ID == CMD_DIGITAL_WRITE){
		dsx_data_valid = validate_digital_write(dsx_data);
	}
	else if(dsx_data->ID == CMD_DIGITAL_READ){
		dsx_data_valid = validate_digital_read(dsx_data);
	}
	else if(dsx_data->ID == CMD_GET_PIN_MODE){
		dsx_data_valid = validate_get_pin_mode(dsx_data);
	}
	else if(dsx_data->ID == CMD_ANALOG_READ){
		dsx_data_valid = validate_analog_read(dsx_data);
	}
	else if(dsx_data->ID == CMD_PWM_WRITE){
		dsx_data_valid = validate_pwm_write(dsx_data);
	}
	else if(dsx_data->ID == CMD_SET_PWM_FREQ){
		dsx_data_valid = validate_set_PWM_freq(dsx_data);
	}
	else if(dsx_data->ID == CMD_SERVO_WRITE){
		dsx_data_valid = validate_servo_write(dsx_data);
	}
	else if(dsx_data->ID == CMD_ENCODER_READ){
		dsx_data_valid = validate_read_encoder(dsx_data);
	}
	else if(dsx_data->ID == CMD_GET_SERIAL_INFO){
		dsx_data_valid = validate_get_serial_info(dsx_data);
	}
	else if(dsx_data->ID == CMD_GET_SYS_STATUS){
		dsx_data_valid = validate_get_sys_status(dsx_data);
	}
	else if(dsx_data->ID == CMD_DAC_WRITE){
		dsx_data_valid = validate_dac_write(dsx_data);
	}
	else if(dsx_data->ID == CMD_SET_PWM_LEVEL){
		dsx_data_valid = validate_set_pwm_level(dsx_data);
	}
	else if(dsx_data->ID == CMD_SPI_WRITE){
		dsx_data_valid = validate_spi_write(dsx_data);
	}
	else if(dsx_data->ID == CMD_I2C_WRITE){
		dsx_data_valid = validate_i2c_write(dsx_data);
	}
	else if(dsx_data->ID == CMD_WAVEFORM_WRITE){
		dsx_data_valid = validate_generate_waveform_(dsx_data);
	}

	return dsx_data_valid;
}
