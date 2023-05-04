/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"


/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include <stdio.h>
#include <string.h>
#include "semphr.h"
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
UART_HandleTypeDef huart2;

/* Definitions for defaultTask */

/* USER CODE BEGIN PV */
QueueHandle_t xCharPointerQueue, xCharPointerQueue2;
QueueHandle_t xUint32tQueue;

SemaphoreHandle_t xBinarySemaphore;

QueueSetHandle_t xQueueSet;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void vAMoreRealisticReceiverTask(void *pvParameters)
{
	QueueSetMemberHandle_t xHandle;
	char *pcReceivedString;
	uint32_t ulReceivedValue;
	const TickType_t xDelay100ms = pdMS_TO_TICKS(20);

	for(;;)
	{
		xHandle = xQueueSelectFromSet(xQueueSet, xDelay100ms);

		if(xHandle == NULL)
		{
			const char *errMsg = "Cant get item from Queue set\r\n";
			HAL_UART_Transmit(&huart2, (uint8_t*)errMsg, strlen(errMsg), HAL_MAX_DELAY);
		}
		else if(xHandle == (QueueSetMemberHandle_t) xCharPointerQueue)
		{
			xQueueReceive(xCharPointerQueue, &pcReceivedString, 0);
			HAL_UART_Transmit(&huart2, (uint8_t *)pcReceivedString, strlen(pcReceivedString), HAL_MAX_DELAY);
		}
		else if(xHandle == (QueueSetMemberHandle_t) xUint32tQueue)
		{
			xQueueReceive(xUint32tQueue, &ulReceivedValue, 0);
			char buffer[50];
			sprintf(buffer, "Received from xUint32tQueue : %ld\r\n", ulReceivedValue);
			HAL_UART_Transmit(&huart2, (uint8_t *)buffer, strlen(buffer), HAL_MAX_DELAY);
		}
		else if(xHandle == (QueueSetMemberHandle_t) xCharPointerQueue2)
		{
			xQueueReceive(xCharPointerQueue2, &pcReceivedString, 0);
			HAL_UART_Transmit(&huart2, (uint8_t *)pcReceivedString, strlen(pcReceivedString), HAL_MAX_DELAY);
		}
		else if(xHandle == (QueueSetMemberHandle_t) xBinarySemaphore)
		{
			xSemaphoreTake(xBinarySemaphore, 0);
			char *smphrMsg = "Semaphore has taken!\r\n";
			HAL_UART_Transmit(&huart2, (uint8_t *)smphrMsg, strlen(smphrMsg), HAL_MAX_DELAY);
		}
	}
}
void vSenderTask1(void *pvParameters)
{
	const TickType_t xDelay100ms = pdMS_TO_TICKS(200);
	const char *msg = "Message from vSenderTask1\r\n";

	for(;;)
	{
		vTaskDelay(xDelay100ms);

		xQueueSend(xCharPointerQueue, &msg, 0);
	}
}
void vSenderTask2(void *pvParameters)
{
	const TickType_t xDelay300ms = pdMS_TO_TICKS(200);
	uint32_t count = 0;

	for(;;)
	{
		vTaskDelay(xDelay300ms);
		xQueueSend(xUint32tQueue, &count, 0);
		count++;
	}
}
void vSenderTask3(void *pvParameters)
{
	const TickType_t xDelay100ms = pdMS_TO_TICKS(200);

	for(;;)
	{
		vTaskDelay(xDelay100ms);
		xSemaphoreGive(xBinarySemaphore);
	}
}
void vSenderTask4(void *pvParameters)
{
	const TickType_t xDelay100ms = pdMS_TO_TICKS(200);
	const char *msg2 = "Message from vSenderTask4\r\n";

	for(;;)
	{
		vTaskDelay(xDelay100ms);
		xQueueSend(xCharPointerQueue2, &msg2, 0);
	}
}
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

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */
  xCharPointerQueue = xQueueCreate(1, sizeof(char *));
  xUint32tQueue = xQueueCreate(1, sizeof(uint32_t));
  xCharPointerQueue2 = xQueueCreate(1, sizeof(char *));
  xBinarySemaphore = xSemaphoreCreateBinary();

  xQueueSet = xQueueCreateSet(1 * 4);
  xQueueAddToSet(xCharPointerQueue, xQueueSet);
  xQueueAddToSet(xUint32tQueue, xQueueSet);
  xQueueAddToSet(xCharPointerQueue2, xQueueSet);
  xQueueAddToSet(xBinarySemaphore, xQueueSet);

  xTaskCreate(vSenderTask1, "Sender1", configMINIMAL_STACK_SIZE, NULL, 2, NULL);
  xTaskCreate(vSenderTask2, "Sender2", configMINIMAL_STACK_SIZE, NULL, 2, NULL);
  xTaskCreate(vSenderTask3, "Sender3", configMINIMAL_STACK_SIZE, NULL, 2, NULL);
  xTaskCreate(vSenderTask4, "Sender4", configMINIMAL_STACK_SIZE, NULL, 2, NULL);
  xTaskCreate(vAMoreRealisticReceiverTask, "Receiver", configMINIMAL_STACK_SIZE, NULL, 1, NULL);

  vTaskStartScheduler();
  /* USER CODE END 2 */

  /* Init scheduler */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of defaultTask */

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

  /* Start scheduler */

  /* We should never get here as control is now taken by the scheduler */
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
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

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);

  /*Configure GPIO pins : PD12 PD13 PD14 PD15 */
  GPIO_InitStruct.Pin = GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM14 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM14) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

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
