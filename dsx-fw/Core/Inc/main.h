/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define CS_Pin_Pin GPIO_PIN_13
#define CS_Pin_GPIO_Port GPIOC
#define USER_LD1_Pin GPIO_PIN_2
#define USER_LD1_GPIO_Port GPIOC
#define FAULT_LED_Pin GPIO_PIN_3
#define FAULT_LED_GPIO_Port GPIOC
#define LPUART1_TX_Pin GPIO_PIN_2
#define LPUART1_TX_GPIO_Port GPIOA
#define LPUART1_RX_Pin GPIO_PIN_3
#define LPUART1_RX_GPIO_Port GPIOA
#define PWM1_Pin GPIO_PIN_6
#define PWM1_GPIO_Port GPIOA
#define PWM2_Pin GPIO_PIN_7
#define PWM2_GPIO_Port GPIOA
#define DI2_Pin GPIO_PIN_4
#define DI2_GPIO_Port GPIOC
#define DI1_Pin GPIO_PIN_5
#define DI1_GPIO_Port GPIOC
#define MUXA_S0_Pin GPIO_PIN_1
#define MUXA_S0_GPIO_Port GPIOB
#define MUXA_S1_Pin GPIO_PIN_2
#define MUXA_S1_GPIO_Port GPIOB
#define LIMIT_SW2_Pin GPIO_PIN_10
#define LIMIT_SW2_GPIO_Port GPIOB
#define LIMIT_SW2_EXTI_IRQn EXTI15_10_IRQn
#define ADC_CURRENT_Pin GPIO_PIN_11
#define ADC_CURRENT_GPIO_Port GPIOB
#define MUXA_S2_Pin GPIO_PIN_12
#define MUXA_S2_GPIO_Port GPIOB
#define DEBUG_LD1_Pin GPIO_PIN_13
#define DEBUG_LD1_GPIO_Port GPIOB
#define DEBUG_LD2_Pin GPIO_PIN_14
#define DEBUG_LD2_GPIO_Port GPIOB
#define DEBUG_LD3_Pin GPIO_PIN_15
#define DEBUG_LD3_GPIO_Port GPIOB
#define MUXA_S3_Pin GPIO_PIN_6
#define MUXA_S3_GPIO_Port GPIOC
#define DO2_Pin GPIO_PIN_7
#define DO2_GPIO_Port GPIOC
#define MUXB_S0_Pin GPIO_PIN_8
#define MUXB_S0_GPIO_Port GPIOC
#define MUXC_S0_Pin GPIO_PIN_9
#define MUXC_S0_GPIO_Port GPIOC
#define LIMIT_SW1_Pin GPIO_PIN_8
#define LIMIT_SW1_GPIO_Port GPIOA
#define LIMIT_SW1_EXTI_IRQn EXTI9_5_IRQn
#define DI3_Pin GPIO_PIN_10
#define DI3_GPIO_Port GPIOA
#define ENC_A_Pin GPIO_PIN_11
#define ENC_A_GPIO_Port GPIOA
#define ENC_B_Pin GPIO_PIN_12
#define ENC_B_GPIO_Port GPIOA
#define T_SWDIO_Pin GPIO_PIN_13
#define T_SWDIO_GPIO_Port GPIOA
#define T_SWCLK_Pin GPIO_PIN_14
#define T_SWCLK_GPIO_Port GPIOA
#define MUX_En_Pin GPIO_PIN_15
#define MUX_En_GPIO_Port GPIOA
#define DI4_Pin GPIO_PIN_3
#define DI4_GPIO_Port GPIOB
#define DI6_Pin GPIO_PIN_4
#define DI6_GPIO_Port GPIOB
#define DI5_Pin GPIO_PIN_5
#define DI5_GPIO_Port GPIOB
#define DO1_Pin GPIO_PIN_6
#define DO1_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
