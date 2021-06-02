#include "PWM.h"
#include "main.h"

void MX_TIM16_Init(uint8_t dutyCycle, uint32_t freq);
void MX_TIM17_Init(uint8_t dutyCycle, uint32_t freq);

/* Function for PA6 that checks for the correct duty cycle and frequency values
 * then sets them in the MX_TIM16_Init function in the main
 */
void init_PWM_1 (uint8_t dutyCycle, uint32_t pwm_freq)
{
	if (dutyCycle > dutyCycle_Max){
		dutyCycle = dutyCycle_Max;
	}
	else if (dutyCycle < dutyCycle_Min){
		dutyCycle = dutyCycle_Min;
	}
	if (pwm_freq > PWM_Max){
		pwm_freq = PWM_Max;
	}
	else if (pwm_freq < PWM_Min){
		pwm_freq = PWM_Min;
	}
	MX_TIM16_Init(dutyCycle, pwm_freq);

}

/* Function for PA7 that checks for the correct duty cycle and frequency values
 * then sets them in the MX_TIM17_Init function in the main
 */
void init_PWM_2 (uint8_t dutyCycle, uint32_t pwm_freq)
{
	if (dutyCycle > dutyCycle_Max){
		dutyCycle = dutyCycle_Max;
	}
	else if (dutyCycle < dutyCycle_Min){
		dutyCycle = dutyCycle_Min;
	}
	if (pwm_freq > PWM_Max){
		pwm_freq = PWM_Max;
	}
	else if (pwm_freq < PWM_Min){
		pwm_freq = PWM_Min;
	}
	MX_TIM17_Init(dutyCycle, pwm_freq);

}

// Function that can generate a PWM using either TIM16 or TIM17
void gen_PWM (TIM_HandleTypeDef *htimNum, uint32_t Channel)
{
	HAL_TIM_PWM_Start(htimNum, Channel);
}
