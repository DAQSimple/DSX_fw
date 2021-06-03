#include "PWM.h"
#include "main.h"


// Function for that updates the PWM duty cycle
void updateDutyCycle (uint8_t dutyCycle)
{
	if (dutyCycle > dutyCycle_Max){
		dutyCycle = dutyCycle_Max;
	}
	else if (dutyCycle < dutyCycle_Min){
		dutyCycle = dutyCycle_Min;
	}

	// Sets the duty cycle cycle from 0 to Period
	htim16.Instance->CCR1 = dutyCycle;
	htim17.Instance->CCR1 = dutyCycle;

}

// Function for that updates the PWM frequency
void updatePWMFrequency (uint32_t pwm_freq)
{
	// Clock speed for STM32G474RE is 170 MHz
	int clockSpeed = 170000000;

	if (pwm_freq > PWM_Max){
		pwm_freq = PWM_Max;
	}
	else if (pwm_freq < PWM_Min){
		pwm_freq = PWM_Min;
	}

	/* Equation for setting the pre-scaler value based off the input frequency.
	 * The frequency can be a combination of the following factors: 2^5, 5^5, 17
	 */
	htim16.Instance->PSC = (clockSpeed/(htim16.Init.Period + 1)*pwm_freq) - 1;
	htim17.Instance->PSC = (clockSpeed/(htim17.Init.Period + 1)*pwm_freq) - 1;

}

// Function that can generate a PWM using either TIM16 or TIM17
void initPWM(void)
{
	HAL_TIM_PWM_Start(&htim16, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim17, TIM_CHANNEL_1);
}
