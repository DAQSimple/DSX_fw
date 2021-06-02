/*
 * command.c
 *
 *  Created on: May 26, 2021
 *      Author: jpaca
 */

#include "command.h"

extern bool serial_available;

// Digital Write Command
void cmd_digital_write(volatile DSX_data_t *dsx_data){
	channel_t channel = convert_loc_to_channel(dsx_data->loc);
	HAL_GPIO_WritePin(channel.port, channel.pin, dsx_data->val);
}

// Digital Read Command
void cmd_digital_read(volatile DSX_data_t *dsx_data){
	channel_t channel = convert_loc_to_channel(dsx_data->loc);
	dsx_data->val = HAL_GPIO_ReadPin(channel.port, channel.pin);
	Serial_Transmit(dsx_data);
}

// Get Pin Mode Command
void cmd_get_pin_mode(volatile DSX_data_t *dsx_data){};

// Analog Read Command
void cmd_analog_read(volatile DSX_data_t *dsx_data){
	if(dsx_data->loc==20)
		dsx_data->val = read_ADC_channel(0);
	else if(dsx_data->loc==14)
		dsx_data->val = read_ADC_channel(1);
	else if(dsx_data->loc==15)
		dsx_data->val = read_ADC_channel(2);
	else if(dsx_data->loc==16)
		dsx_data->val = read_ADC_channel(3);
	Serial_Transmit(dsx_data);
}

// PWM Write Command
void cmd_pwm_write(volatile DSX_data_t *dsx_data){};

// Set PWM Frequency Command
void cmd_set_pwm_freq(volatile DSX_data_t *dsx_data){};

// Servo Write Command
void cmd_servo_write(volatile DSX_data_t *dsx_data){};

// Read Encoder Speed and Direction Command
void cmd_encoder_read(volatile DSX_data_t *dsx_data){};

// Get Serial Info Command
void cmd_get_serial_info(volatile DSX_data_t *dsx_data){};

// Get System Status Command
void cmd_get_system_status(volatile DSX_data_t *dsx_data){};

// DAC Write Command
void cmd_dac_write(volatile DSX_data_t *dsx_data){
	if(dsx_data->loc==17)
		DAC_write(dsx_data->val, DAC1_CHANNEL_1);
	else if(dsx_data->loc==18)
		DAC_write(dsx_data->val, DAC1_CHANNEL_2);
}

// Set PWM Level Command
void cmd_set_pwm_level(volatile DSX_data_t *dsx_data){};

// Write SPI Command
void cmd_spi_write(volatile DSX_data_t *dsx_data){};

// Write I2C Command
void cmd_i2c_write(volatile DSX_data_t *dsx_data){};

// Generate Waveform Command
void cmd_generate_waveform(volatile DSX_data_t *dsx_data){};

// *** Main Execute Command ***
void execute_command(volatile DSX_data_t *dsx_data)
{
	// Validate dsx_data
	if(!is_valid(dsx_data)) return;

	// Execute command based on ID
	if(dsx_data->ID == CMD_DIGITAL_WRITE){
		cmd_digital_write(dsx_data);
	}
	else if(dsx_data->ID == CMD_DIGITAL_READ){
		cmd_digital_read(dsx_data);
	}
	else if(dsx_data->ID == CMD_GET_PIN_MODE){
		cmd_get_pin_mode(dsx_data);
	}
	else if(dsx_data->ID == CMD_ANALOG_READ){
		cmd_analog_read(dsx_data);
	}
	else if(dsx_data->ID == CMD_PWM_WRITE){
		cmd_pwm_write(dsx_data);
	}
	else if(dsx_data->ID == CMD_SET_PWM_FREQ){
		cmd_set_pwm_freq(dsx_data);
	}
	else if(dsx_data->ID == CMD_SERVO_WRITE){
		cmd_servo_write(dsx_data);
	}
	else if(dsx_data->ID == CMD_ENCODER_READ){
		cmd_encoder_read(dsx_data);
	}
	else if(dsx_data->ID == CMD_GET_SERIAL_INFO){
		cmd_get_serial_info(dsx_data);
	}
	else if(dsx_data->ID == CMD_GET_SYS_STATUS){
		cmd_get_system_status(dsx_data);
	}
	else if(dsx_data->ID == CMD_DAC_WRITE){
		cmd_dac_write(dsx_data);
	}
	else if(dsx_data->ID == CMD_SET_PWM_LEVEL){
		cmd_set_pwm_level(dsx_data);
	}
	else if(dsx_data->ID == CMD_SPI_WRITE){
		cmd_spi_write(dsx_data);
	}
	else if(dsx_data->ID == CMD_I2C_WRITE){
		cmd_i2c_write(dsx_data);
	}
	else if(dsx_data->ID == CMD_WAVEFORM_WRITE){
		cmd_generate_waveform(dsx_data);
	}

	// reset dsx data
	dsx_data->ID 	= 0;
	dsx_data->loc 	= 0;
	dsx_data->sign 	= 0;
	dsx_data->val 	= 0;
	dsx_data->ret 	= 0;

	serial_available = false;
}



