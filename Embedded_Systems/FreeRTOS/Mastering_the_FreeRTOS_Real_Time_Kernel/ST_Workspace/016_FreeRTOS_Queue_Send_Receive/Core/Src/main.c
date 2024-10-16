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
#include "queue.h"
#include "task.h"
#include <string.h>
#include <stdio.h>
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
/* Declare a variable of type QueueHandle_t. This is used to store the handle
to the queue that is accessed by all three tasks. */
QueueHandle_t xQueue;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);


/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
static void vSenderTask(void *pvParameters)
{
	int32_t lValueToSend;
	BaseType_t xStatus;
	const char *failMessage = "Could not send to the queue\r\n";
	/* Two instances of this task are created so the value that is sent to the
	 queue is passed in via the task parameter - this way each instance can use
	 a different value. The queue was created to hold values of type int32_t,
	 so cast the parameter to the required type. */
	lValueToSend = (int32_t) pvParameters;

	/* As per most tasks, this task is implemented within an infinite loop. */
	for(;;)
	{
		/* Send the value to the queue.
		 The first parameter is the queue to which data is being sent. The
		 queue was created before the scheduler was started, so before this task
		 started to execute.
		 The second parameter is the address of the data to be sent, in this case
		 the address of lValueToSend.
		 The third parameter is the Block time – the time the task should be kept
		 in the Blocked state to wait for space to become available on the queue
		 should the queue already be full. In this case a block time is not
		 specified because the queue should never contain more than one item, and
		 therefore never be full. */
		xStatus = xQueueSendToBack(xQueue, &lValueToSend, 0);

		if(xStatus != pdPASS)
		{
			/* The send operation could not complete because the queue was full -
			 this must be an error as the queue should never contain more than
			 one item! */
			HAL_UART_Transmit(&huart2, (uint8_t *)failMessage, strlen(failMessage), HAL_MAX_DELAY);
		}
	}
}
static void vReceiverTask(void *pvParameters)
{
	/* Declare the variable that will hold the values received from the queue. */
	int32_t lReceivedValue;
	BaseType_t xStatus;
	const TickType_t xTicksToWait = pdMS_TO_TICKS(100);
	const char *emptyMessage = "Queue should have been empty!\r\n";
	const char *errorMessage = "Could not receive from the queue\r\n";
	/* This task is also defined within an infinite loop. */
	for(;;)
	{
		/* This call should always find the queue empty because this task will
		 immediately remove any data that is written to the queue. */
		if(uxQueueMessagesWaiting(xQueue) != 0)
		{
			HAL_UART_Transmit(&huart2, (uint8_t *)emptyMessage, strlen(emptyMessage), HAL_MAX_DELAY);
		}
		/* Receive data from the queue.
		 The first parameter is the queue from which data is to be received. The
		 queue is created before the scheduler is started, and therefore before this
		 task runs for the first time.
		 The second parameter is the buffer into which the received data will be
		 placed. In this case the buffer is simply the address of a variable that
		 has the required size to hold the received data.
		 The last parameter is the block time – the maximum amount of time that the
		 task will remain in the Blocked state to wait for data to be available
		 should the queue already be empty. */
		xStatus = xQueueReceive(xQueue, &lReceivedValue, xTicksToWait);
		if(xStatus == pdPASS)
		{
			/* Data was successfully received from the queue, print out the received
			 value. */
			char buffer[50];
			sprintf(buffer, "Received value : %ld\r\n", lReceivedValue);
			HAL_UART_Transmit(&huart2,(uint8_t *)buffer, strlen(buffer), HAL_MAX_DELAY);
		}
		else
		{
			/* Data was not received from the queue even after waiting for 100ms.
			 This must be an error as the sending tasks are free running and will be
			 continuously writing to the queue. */
			HAL_UART_Transmit(&huart2, (uint8_t *)errorMessage, strlen(errorMessage), HAL_MAX_DELAY);
		}
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
  /* The queue is created to hold a maximum of 5 values, each of which is
   large enough to hold a variable of type int32_t. */
  xQueue = xQueueCreate(5, sizeof(int32_t));

  if(xQueue != NULL)
  {
	  /* Create two instances of the task that will send to the queue. The task
	   parameter is used to pass the value that the task will write to the queue,
	   so one task will continuously write 100 to the queue while the other task
	   will continuously write 200 to the queue. Both tasks are created at
	   priority 1. */
	  xTaskCreate(vSenderTask,"Sender 1", 1000, (void *) 100, 1, NULL);
	  xTaskCreate(vSenderTask,"Sender 2", 1000, (void *) 200, 1, NULL);

	  /* Create the task that will read from the queue. The task is created with
	   priority 2, so above the priority of the sender tasks. */
	  xTaskCreate(vReceiverTask, "Receiver", 1000, NULL, 2, NULL);
	  /* Start the scheduler so the created tasks start executing. */
	   vTaskStartScheduler();
  }
  else
  {
	  /* The queue could not be created. */
	  char const *errorMessage = "Queue Couldn't created. Scheduler didn't started!\r\n";
	  HAL_UART_Transmit(&huart2, (uint8_t *)errorMessage, strlen(errorMessage), HAL_MAX_DELAY);
  }
  /* If all is well then main() will never reach here as the scheduler will
   now be running the tasks. If main() does reach here then it is likely that
   there was insufficient FreeRTOS heap memory available for the idle task to be
   created. Chapter 2 provides more information on heap memory management. */

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
