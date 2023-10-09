/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "software_timer.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */
void clearAll(){
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
}

void display7SEG(int num){
	switch(num){
		case 1:
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_0, SET);
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_1, RESET);
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_2, RESET);
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_3, SET);
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_4, SET);
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_5, SET);
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_6, SET);
			break;
		case 2:
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_0, RESET);
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_1, RESET);
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_2, SET);
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_3, RESET);
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_4, RESET);
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_5, SET);
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_6, RESET);
			break;
		case 3:
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_0, RESET);
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_1, RESET);
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_2, RESET);
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_3, RESET);
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_4, SET);
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_5, SET);
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_6, RESET);
			break;
		case 4:
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_0,SET);
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_1, RESET);
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_2, RESET);
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_3, SET);
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_4, SET);
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_5, RESET);
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_6, RESET);
			break;
		case 5:
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_0, RESET);
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_1, SET);
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_2, RESET);
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_3, RESET);
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_4, SET);
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_5, RESET);
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_6, RESET);
			break;
		case 6:
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_0, RESET);
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_1, SET);
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_2, RESET);
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_3, RESET);
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_4, RESET);
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_5, RESET);
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_6, RESET);
			break;
		case 7:
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_0, RESET);
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_1,RESET);
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_2, RESET);
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_3, SET);
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_4, SET);
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_5, SET);
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_6, SET);
			break;
		case 8:
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_0, RESET);
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_1, RESET);
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_2, RESET);
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_3, RESET);
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_4, RESET);
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_5, RESET);
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_6, RESET);
			break;
		case 9:
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_0, RESET);
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_1, RESET);
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_2,RESET);
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_3, RESET);
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_4, SET);
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_5, RESET);
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_6, RESET);
			break;
		case 0:
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_0, RESET);
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_1, RESET);
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_2, RESET);
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_3, RESET);
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_4, RESET);
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_5, RESET);
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_6, SET);
			break;
	}
}



const int MAX_LED = 4;
int index_led = 0;
int led_buffer [4] = {3, 7, 0, 4};
void update7SEG ( int index ){
	clearAll();
	display7SEG(led_buffer[index]);
	switch ( index ){
	case 0:
		// Display the first 7 SEG with led_buffer [0]
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
		break ;
	case 1:
		//Display the second 7 SEG with led_buffer [1]
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
		break ;
	case 2:
		// Display the third 7 SEG with led_buffer [2]
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
		break ;
	case 3:
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
		// Display the forth 7 SEG with led_buffer [3]
		break ;
	default :
		break ;
	}
}
int hour = 15, minute = 8, second = 50;
void updateClockBuffer(){
	led_buffer[0] = hour/10;
	led_buffer[1] = hour%10;
	led_buffer[2] = minute/10;
	led_buffer[3] = minute%10;
}


uint16_t row[8]={ROW0_Pin,ROW1_Pin,ROW2_Pin,ROW3_Pin,ROW4_Pin,ROW5_Pin,ROW6_Pin,ROW7_Pin};
uint16_t col[8]={ENM0_Pin,ENM1_Pin,ENM2_Pin,ENM3_Pin,ENM4_Pin,ENM5_Pin,ENM6_Pin,ENM7_Pin};
void clearLEDMatrix(){
	  for (int i=0; i<8; i++){
		  HAL_GPIO_WritePin(GPIOB,row[i],SET);
		  HAL_GPIO_WritePin(GPIOA,col[i],SET);
	  }
}
const int MAX_LED_MATRIX = 8;
uint8_t matrix_buffer[8] = {0x18,0x24,0x42,0x42,0x7e,0x42,0x42,0x42};
void updateLEDMatrix(int index){
	clearLEDMatrix();
	switch(index){
		case 0:
			HAL_GPIO_WritePin(GPIOB,row[0], RESET);
			HAL_GPIO_WritePin(GPIOA,col[0], !(matrix_buffer[0] & 0x01));
			HAL_GPIO_WritePin(GPIOA,col[1], !(matrix_buffer[0] & 0x02));
			HAL_GPIO_WritePin(GPIOA,col[2], !(matrix_buffer[0] & 0x04));
			HAL_GPIO_WritePin(GPIOA,col[3], !(matrix_buffer[0] & 0x08));
			HAL_GPIO_WritePin(GPIOA,col[4], !(matrix_buffer[0] & 0x10));
			HAL_GPIO_WritePin(GPIOA,col[5], !(matrix_buffer[0] & 0x20));
			HAL_GPIO_WritePin(GPIOA,col[6], !(matrix_buffer[0] & 0x40));
			HAL_GPIO_WritePin(GPIOA,col[7], !(matrix_buffer[0] & 0x80));
			break;
		case 1:
			HAL_GPIO_WritePin(GPIOB,row[1], RESET);
			HAL_GPIO_WritePin(GPIOA,col[0], !(matrix_buffer[1] & 0x01));
			HAL_GPIO_WritePin(GPIOA,col[1], !(matrix_buffer[1] & 0x02));
			HAL_GPIO_WritePin(GPIOA,col[2], !(matrix_buffer[1] & 0x04));
			HAL_GPIO_WritePin(GPIOA,col[3], !(matrix_buffer[1] & 0x08));
			HAL_GPIO_WritePin(GPIOA,col[4], !(matrix_buffer[1] & 0x10));
			HAL_GPIO_WritePin(GPIOA,col[5], !(matrix_buffer[1] & 0x20));
			HAL_GPIO_WritePin(GPIOA,col[6], !(matrix_buffer[1] & 0x40));
			HAL_GPIO_WritePin(GPIOA,col[7], !(matrix_buffer[1] & 0x80));
			break;
		case 2:
			HAL_GPIO_WritePin(GPIOB,row[2], RESET);
			HAL_GPIO_WritePin(GPIOA,col[0], !(matrix_buffer[2] & 0x01));
			HAL_GPIO_WritePin(GPIOA,col[1], !(matrix_buffer[2] & 0x02));
			HAL_GPIO_WritePin(GPIOA,col[2], !(matrix_buffer[2] & 0x04));
			HAL_GPIO_WritePin(GPIOA,col[3], !(matrix_buffer[2] & 0x08));
			HAL_GPIO_WritePin(GPIOA,col[4], !(matrix_buffer[2] & 0x10));
			HAL_GPIO_WritePin(GPIOA,col[5], !(matrix_buffer[2] & 0x20));
			HAL_GPIO_WritePin(GPIOA,col[6], !(matrix_buffer[2] & 0x40));
			HAL_GPIO_WritePin(GPIOA,col[7], !(matrix_buffer[2] & 0x80));
			break;
		case 3:
			HAL_GPIO_WritePin(GPIOB,row[3], RESET);
			HAL_GPIO_WritePin(GPIOA,col[0], !(matrix_buffer[3] & 0x01));
			HAL_GPIO_WritePin(GPIOA,col[1], !(matrix_buffer[3] & 0x02));
			HAL_GPIO_WritePin(GPIOA,col[2], !(matrix_buffer[3] & 0x04));
			HAL_GPIO_WritePin(GPIOA,col[3], !(matrix_buffer[3] & 0x08));
			HAL_GPIO_WritePin(GPIOA,col[4], !(matrix_buffer[3] & 0x10));
			HAL_GPIO_WritePin(GPIOA,col[5], !(matrix_buffer[3] & 0x20));
			HAL_GPIO_WritePin(GPIOA,col[6], !(matrix_buffer[3] & 0x40));
			HAL_GPIO_WritePin(GPIOA,col[7], !(matrix_buffer[3] & 0x80));
			break;
		case 4:
			HAL_GPIO_WritePin(GPIOB,row[4], RESET);
			HAL_GPIO_WritePin(GPIOA,col[0], !(matrix_buffer[4] & 0x01));
			HAL_GPIO_WritePin(GPIOA,col[1], !(matrix_buffer[4] & 0x02));
			HAL_GPIO_WritePin(GPIOA,col[2], !(matrix_buffer[4] & 0x04));
			HAL_GPIO_WritePin(GPIOA,col[3], !(matrix_buffer[4] & 0x08));
			HAL_GPIO_WritePin(GPIOA,col[4], !(matrix_buffer[4] & 0x10));
			HAL_GPIO_WritePin(GPIOA,col[5], !(matrix_buffer[4] & 0x20));
			HAL_GPIO_WritePin(GPIOA,col[6], !(matrix_buffer[4] & 0x40));
			HAL_GPIO_WritePin(GPIOA,col[7], !(matrix_buffer[4] & 0x80));
			break;
		case 5:
			HAL_GPIO_WritePin(GPIOB,row[5], RESET);
			HAL_GPIO_WritePin(GPIOA,col[0], !(matrix_buffer[5] & 0x01));
			HAL_GPIO_WritePin(GPIOA,col[1], !(matrix_buffer[5] & 0x02));
			HAL_GPIO_WritePin(GPIOA,col[2], !(matrix_buffer[5] & 0x04));
			HAL_GPIO_WritePin(GPIOA,col[3], !(matrix_buffer[5] & 0x08));
			HAL_GPIO_WritePin(GPIOA,col[4], !(matrix_buffer[5] & 0x10));
			HAL_GPIO_WritePin(GPIOA,col[5], !(matrix_buffer[5] & 0x20));
			HAL_GPIO_WritePin(GPIOA,col[6], !(matrix_buffer[5] & 0x40));
			HAL_GPIO_WritePin(GPIOA,col[7], !(matrix_buffer[5] & 0x80));
			break;
		case 6:
			HAL_GPIO_WritePin(GPIOB,row[6], RESET);
			HAL_GPIO_WritePin(GPIOA,col[0], !(matrix_buffer[6] & 0x01));
			HAL_GPIO_WritePin(GPIOA,col[1], !(matrix_buffer[6] & 0x02));
			HAL_GPIO_WritePin(GPIOA,col[2], !(matrix_buffer[6] & 0x04));
			HAL_GPIO_WritePin(GPIOA,col[3], !(matrix_buffer[6] & 0x08));
			HAL_GPIO_WritePin(GPIOA,col[4], !(matrix_buffer[6] & 0x10));
			HAL_GPIO_WritePin(GPIOA,col[5], !(matrix_buffer[6] & 0x20));
			HAL_GPIO_WritePin(GPIOA,col[6], !(matrix_buffer[6] & 0x40));
			HAL_GPIO_WritePin(GPIOA,col[7], !(matrix_buffer[6] & 0x80));
			break;
		case 7:
			HAL_GPIO_WritePin(GPIOB,row[7], RESET);
			HAL_GPIO_WritePin(GPIOA,col[0], !(matrix_buffer[7] & 0x01));
			HAL_GPIO_WritePin(GPIOA,col[1], !(matrix_buffer[7] & 0x02));
			HAL_GPIO_WritePin(GPIOA,col[2], !(matrix_buffer[7] & 0x04));
			HAL_GPIO_WritePin(GPIOA,col[3], !(matrix_buffer[7] & 0x08));
			HAL_GPIO_WritePin(GPIOA,col[4], !(matrix_buffer[7] & 0x10));
			HAL_GPIO_WritePin(GPIOA,col[5], !(matrix_buffer[7] & 0x20));
			HAL_GPIO_WritePin(GPIOA,col[6], !(matrix_buffer[7] & 0x40));
			HAL_GPIO_WritePin(GPIOA,col[7], !(matrix_buffer[7] & 0x80));
			break;
		default:
			break;
	}
}

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */


  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

    /* USER CODE END Init */
  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT(&htim2);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  setTimer1(25);
  setTimer2(100);
  setTimer3(1);
  //int status = 1;
  //int i=0;
  int index_led_matrix = 0;
  while (1)
  {
    /* USER CODE END WHILE */
	  if(timer1_flag == 1){
		  setTimer1(25);
		  HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
		  update7SEG(index_led++);
		  if(index_led > MAX_LED) index_led = 0;
	  }
	  if(timer2_flag==1){
		  setTimer2(100);
		  HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
		  second++;
		  if(second>=60){
			  second=0;
			  minute++;
		  }
		  if(minute>=60){
			  minute=0;
			  hour++;
		  }
		  if(hour>=24) hour=0;
		  updateClockBuffer();
	  }
	  if(timer3_flag == 1){
	  		  updateLEDMatrix(index_led_matrix++);
	  		  if(index_led_matrix > 7) index_led_matrix = 0;
	  		  setTimer3(10);
	  }

    /* USER CODE BEGIN 3 */

  }

      /* USER CODE BEGIN 3 */

  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 7999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 9;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, DOT_Pin|LED_RED_Pin|EN0_Pin|EN1_Pin
                          |EN2_Pin|EN3_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6, GPIO_PIN_RESET);

  /*Configure GPIO pins : DOT_Pin LED_RED_Pin EN0_Pin EN1_Pin
                           EN2_Pin EN3_Pin */
  GPIO_InitStruct.Pin = DOT_Pin|LED_RED_Pin|EN0_Pin|EN1_Pin
                          |EN2_Pin|EN3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB0 PB1 PB2 PB3
                           PB4 PB5 PB6 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	timerRun();
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
