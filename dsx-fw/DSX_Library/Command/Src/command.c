/*
 * command.c
 *
 *  Created on: May 26, 2021
 *      Author: jpaca
 */

#include "command.h"

extern bool serial_available;

// Timer handles
extern TIM_HandleTypeDef htim16;
extern TIM_HandleTypeDef htim17;

// Digital Write Command
void cmd_digital_write(volatile DSX_data_t *dsx_data){
	channel_t channel = convert_loc_to_channel(dsx_data->loc);
	HAL_GPIO_WritePin(channel.port, channel.pin, dsx_data->val);
//	dsx_data->val = CMD_EXECUTED;
	//Serial_Transmit(dsx_data);
}

// Digital Read Command
void cmd_digital_read(volatile DSX_data_t *dsx_data){
	channel_t channel = convert_loc_to_channel(dsx_data->loc);
	dsx_data->val = HAL_GPIO_ReadPin(channel.port, channel.pin);
	dsx_data->ret = RETURN_DIGITAL_READ;
	Serial_Transmit(dsx_data);
}

// Get Pin Mode Command
void cmd_get_pin_mode(volatile DSX_data_t *dsx_data){};

// Analog Read Command
void cmd_analog_read(volatile DSX_data_t *dsx_data){
	if(dsx_data->loc==AI1)
		dsx_data->val = read_ADC_channel(0);
	else if(dsx_data->loc==AI2)
		dsx_data->val = read_ADC_channel(1);
	else if(dsx_data->loc==AI3)
		dsx_data->val = read_ADC_channel(2);
	else if(dsx_data->loc==AI4)
		dsx_data->val = read_ADC_channel(3);
	dsx_data->ret = RETURN_ANALOG_READ;
	Serial_Transmit(dsx_data);
}

// PWM Write Command
void cmd_pwm_write(volatile DSX_data_t *dsx_data){
	if(dsx_data->loc==PWM1)
		updateDutyCycle(htim16,dsx_data->val);
	else if (dsx_data->loc==PWM2)
		updateDutyCycle(htim17,dsx_data->val);
//	dsx_data->val = CMD_EXECUTED;
	//Serial_Transmit(dsx_data);
}

// Set PWM Frequency Command
void cmd_set_pwm_freq(volatile DSX_data_t *dsx_data){
	if(dsx_data->loc==PWM1){
		if (dsx_data->sign == 0) updatePWMFrequency(htim16,dsx_data->val);
		else if (dsx_data->sign == 1) updatePWMFrequency(htim16,(dsx_data->val)*10 + dsx_data->ret);
	}
	else if (dsx_data->loc==PWM2){
		if (dsx_data->sign == 0) updatePWMFrequency(htim17,dsx_data->val);
		else if (dsx_data->sign == 1) updatePWMFrequency(htim17,(dsx_data->val)*10 + dsx_data->ret);
	}
//	dsx_data->val = CMD_EXECUTED;
//	dsx_data->ret = CMD_COMPLETE_PING;
	//Serial_Transmit(dsx_data);
}

// Servo Write Command
void cmd_servo_write(volatile DSX_data_t *dsx_data){
	if(dsx_data->loc==PWM1)
		writeServo(htim16,dsx_data->val);
	else if (dsx_data->loc==PWM2)
		writeServo(htim17,dsx_data->val);
//	dsx_data->val = CMD_EXECUTED;
	//Serial_Transmit(dsx_data);
}

// Set Encoder CPR
void cmd_encoder_set_cpr(volatile DSX_data_t *dsx_data){
	Encoder_Set_CPR(dsx_data->val);
	//Serial_Transmit(dsx_data);
}

// Read Encoder Speed and Direction Command
void cmd_encoder_read_rpm(volatile DSX_data_t *dsx_data){
	Enable_Encoder_INT();
	dsx_data->sign = Encoder_Get_DIR();
	dsx_data->val = Encoder_Read_RPM();
	dsx_data->ret = RETURN_ENCODER_VELO;
	Serial_Transmit(dsx_data);
}

// Read Encoder Count
void cmd_encoder_read_count(volatile DSX_data_t *dsx_data){
	Disable_Encoder_INT();
	dsx_data->val = Encoder_Read_Count();
	Serial_Transmit(dsx_data);
}

// Get Serial Info Command
void cmd_get_serial_info(volatile DSX_data_t *dsx_data){};

// Get System Status Command
void cmd_get_system_status(volatile DSX_data_t *dsx_data){};

// DAC Write Command
void cmd_dac_write(volatile DSX_data_t *dsx_data){
	if(dsx_data->loc==AO1)
		DAC_write(dsx_data->val, DAC1_CHANNEL_1);
	else if(dsx_data->loc==AO2)
		DAC_write(dsx_data->val, DAC1_CHANNEL_2);
//	dsx_data->val = CMD_EXECUTED;
	//Serial_Transmit(dsx_data);
}

// Enable or Disable Limit Switch Interrupts on LS1 and LS2 Command
void cmd_limit_switch(volatile DSX_data_t *dsx_data)
{
	if(dsx_data->sign == 1){
		disable_limit_sw_interrupt_pin(dsx_data->loc);
	}else if(dsx_data->sign == 0){
		enable_limit_sw_interrupt_pin(dsx_data->loc);
	}
	//Serial_Transmit(dsx_data);
}

// Write SPI Command
void cmd_spi_write(volatile DSX_data_t *dsx_data){};

// Write I2C Command
void cmd_i2c_write(volatile DSX_data_t *dsx_data)
{
	I2C_Write(dsx_data->loc, dsx_data->val);
	//Serial_Transmit(dsx_data);
}

// Read I2C Command
void cmd_i2c_read(volatile DSX_data_t *dsx_data)
{
	dsx_data->val = I2C_Read(dsx_data->loc);
	Serial_Transmit(dsx_data);
}

// Generate Waveform Command
void cmd_generate_waveform(volatile DSX_data_t *dsx_data){};

// *** Main Execute Command ***
void execute_command(volatile DSX_data_t *dsx_data)
{
	// Validate dsx_data
	if(!is_valid(dsx_data)){
		dsx_data->ID 	= 0;
		dsx_data->loc 	= 0;
		dsx_data->sign 	= 0;
		dsx_data->val 	= 0;
		dsx_data->ret 	= 0;
		serial_available = false;
		return;
	}

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
	else if(dsx_data->ID == CMD_ENCODER_SET_CPR){
		cmd_encoder_set_cpr(dsx_data);
	}
	else if(dsx_data->ID == CMD_ENCODER_READ_COUNT){
		cmd_encoder_read_count(dsx_data);
	}
	else if(dsx_data->ID == CMD_ENCODER_READ_RPM){
		cmd_encoder_read_rpm(dsx_data);
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
	else if(dsx_data->ID == CMD_LIMIT_SWITCH){
		cmd_limit_switch(dsx_data);
	}
	else if(dsx_data->ID == CMD_SPI_WRITE){
		cmd_spi_write(dsx_data);
	}
	else if(dsx_data->ID == CMD_I2C_WRITE){
		cmd_i2c_write(dsx_data);
	}
	else if(dsx_data->ID == CMD_I2C_READ){
		cmd_i2c_read(dsx_data);
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
