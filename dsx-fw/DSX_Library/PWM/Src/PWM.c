#include "PWM.h"

// Timer handles
extern TIM_HandleTypeDef htim16;
extern TIM_HandleTypeDef htim17;


// Function for updating the PWM duty cycle and starting the PWM
void updateDutyCycle (TIM_HandleTypeDef htim, uint8_t dutyCycle)
{
	// Sets the duty cycle cycle from 0 to Period
	htim.Instance->CCR1 = dutyCycle;
	HAL_TIM_PWM_Start(&htim, TIM_CHANNEL_1);
}

// Function for that updates the PWM frequency
void updatePWMFrequency (TIM_HandleTypeDef htim, uint32_t pwm_freq)
{
	/* Set the period to 100-1. This is important because switching between
	 * Servo and PWM functionality, the period value changes
	 */
	htim.Instance->ARR = DUTYCYCLE_MAX;

	/* Equation for setting the pre-scaler value based off the input frequency.
	 * The frequency can be a combination of the following factors: 2^5, 5^5, 17
	 */
	htim.Instance->PSC = (CLOCK_SPEED/((htim.Instance->ARR + 1)*pwm_freq)) - 1;
}

// Function that can initializes a PWM using either TIM16 or TIM17
void initPWM(void)
{
	HAL_TIM_PWM_Init(&htim16);
	HAL_TIM_PWM_Init(&htim17);
}
