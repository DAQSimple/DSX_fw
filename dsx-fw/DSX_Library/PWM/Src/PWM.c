#include "PWM.h"
#include "main.h"


// Timer handles
extern TIM_HandleTypeDef htim16;
extern TIM_HandleTypeDef htim17;


// Function for updating the PWM duty cycle
void updateDutyCycle (TIM_HandleTypeDef htim, uint8_t dutyCycle)
{
	// Remove after writing checks in the execution of commands
	if (dutyCycle > dutyCycle_Max){
		dutyCycle = dutyCycle_Max;
	}
	else if (dutyCycle < dutyCycle_Min){
		dutyCycle = dutyCycle_Min;
	}

	// Sets the duty cycle cycle from 0 to Period
	htim.Instance->CCR1 = dutyCycle;
}

// Function for that updates the PWM frequency
void updatePWMFrequency (TIM_HandleTypeDef htim, uint32_t pwm_freq)
{
	// Remove after writing checks in the execution of commands
	if (pwm_freq > PWM_Max){
		pwm_freq = PWM_Max;
	}
	else if (pwm_freq < PWM_Min){
		pwm_freq = PWM_Min;
	}

	/* Equation for setting the pre-scaler value based off the input frequency.
	 * The frequency can be a combination of the following factors: 2^5, 5^5, 17
	 */
	htim.Instance->PSC = (CLOCK_SPEED/((htim16.Init.Period + 1)*pwm_freq)) - 1;
}

// Function that can generate a PWM using either TIM16 or TIM17
void initPWM(void)
{
	HAL_TIM_PWM_Start(&htim16, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim17, TIM_CHANNEL_1);
}
