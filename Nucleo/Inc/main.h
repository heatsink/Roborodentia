/**
  ******************************************************************************
  * File Name          : main.h
  * Description        : This file contains the common defines of the application
  ******************************************************************************
  *
  * COPYRIGHT(c) 2017 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H
  /* Includes ------------------------------------------------------------------*/

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/

#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC
#define INPUT_LINETEST1_Pin GPIO_PIN_3
#define INPUT_LINETEST1_GPIO_Port GPIOC
#define LSENS2_Pin GPIO_PIN_2
#define LSENS2_GPIO_Port GPIOA
#define LSENS1_Pin GPIO_PIN_3
#define LSENS1_GPIO_Port GPIOA
#define LD2_Pin GPIO_PIN_5
#define LD2_GPIO_Port GPIOA
#define LSENS7_Pin GPIO_PIN_10
#define LSENS7_GPIO_Port GPIOB
#define DIR_1_LEFT_Pin GPIO_PIN_8
#define DIR_1_LEFT_GPIO_Port GPIOC
#define DIR_2_RIGHT_Pin GPIO_PIN_9
#define DIR_2_RIGHT_GPIO_Port GPIOC
#define LSENS8_Pin GPIO_PIN_8
#define LSENS8_GPIO_Port GPIOA
#define LSENS3_Pin GPIO_PIN_10
#define LSENS3_GPIO_Port GPIOA
#define LSENS4_Pin GPIO_PIN_3
#define LSENS4_GPIO_Port GPIOB
#define LSENS6_Pin GPIO_PIN_4
#define LSENS6_GPIO_Port GPIOB
#define LSENS5_Pin GPIO_PIN_5
#define LSENS5_GPIO_Port GPIOB
#define TIM_LEFT_1_CH1_Pin GPIO_PIN_6
#define TIM_LEFT_1_CH1_GPIO_Port GPIOB
#define TIM_RIGHT_1_CH2_Pin GPIO_PIN_7
#define TIM_RIGHT_1_CH2_GPIO_Port GPIOB
#define TIM_RIGHT_2_CH3_Pin GPIO_PIN_8
#define TIM_RIGHT_2_CH3_GPIO_Port GPIOB
#define TIM_LEFT_2_Ch4_Pin GPIO_PIN_9
#define TIM_LEFT_2_Ch4_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

/**
  * @}
  */ 

/**
  * @}
*/ 

#endif /* __MAIN_H */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
