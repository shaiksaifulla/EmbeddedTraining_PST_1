/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include "i2c.h"
#include "i2s.h"
#include "spi.h"
#include "usb_host.h"
#include "gpio.h"

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
/* USER CODE BEGIN PV */
volatile uint8_t buttonPressed = 0; // Flag to indicate button press
uint8_t ledState = 0; // State variable to track which LED should be lit
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void MX_USB_HOST_Process(void);

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */

void configure_LED_Pins(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = LD4_Pin|LD3_Pin|LD5_Pin|LD6_Pin|Audio_RST_Pin;  // Specify the LED and audio reset pins
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;  // Set mode to push-pull output
    GPIO_InitStruct.Pull = GPIO_NOPULL;  // Disable pull-up and pull-down resistors
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;  // Set low output speed
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);  // Initialize the GPIO pins
}

void configure_Button_Pin(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = GPIO_PIN_0;  // Blue button is typically connected to PA0
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;  // Set mode to input
    GPIO_InitStruct.Pull = GPIO_NOPULL;  // Disable pull-up and pull-down resistors
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);  // Initialize the GPIO pin
}

void turn_off_all_LEDs(void)
{
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET); // Turn off LD4 (Green)
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET); // Turn off LD3 (Orange)
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET); // Turn off LD5 (Red)
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET); // Turn off LD6 (Blue)
}

void light_next_LED(void)
{
    turn_off_all_LEDs(); // Turn off all LEDs

    switch (ledState)
    {
    case 0:
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET); // Turn on LD4 (Green)
        break;
    case 1:
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET); // Turn on LD3 (Orange)
        break;
    case 2:
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET); // Turn on LD5 (Red)
        break;
    case 3:
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET); // Turn on LD6 (Blue)
        break;
    default:
        break;
    }
    ledState = (ledState + 1) % 4; // Update the state to the next LED
}

int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();  // Initialize the HAL Library

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();  // Configure the system clock

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();  // Initialize GPIO
  MX_I2C1_Init();  // Initialize I2C1
  MX_I2S3_Init();  // Initialize I2S3
  MX_SPI1_Init();  // Initialize SPI1
  MX_USB_HOST_Init();  // Initialize USB host
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  configure_LED_Pins();  // Configure LED pins
  configure_Button_Pin();  // Configure button pin

  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
	  MX_USB_HOST_Process();  // Process USB host

	      /* USER CODE BEGIN 3 */
	      static GPIO_PinState prevButtonState = GPIO_PIN_RESET;  // Previous button state
	      GPIO_PinState currButtonState = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);  // Current button state

	      if (currButtonState == GPIO_PIN_SET && prevButtonState == GPIO_PIN_RESET)  // Check for rising edge
	      {
	          light_next_LED(); // Light the next LED in the sequence

	          HAL_Delay(50); // Debounce delay
	      }

	      prevButtonState = currButtonState;  // Update previous state
	    }  /* USER CODE END 3 */
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
  __HAL_RCC_PWR_CLK_ENABLE();  // Enable the PWR clock
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);  // Configure voltage scaling

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;  // Specify HSE oscillator
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;  // Turn on the HSE
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;  // Enable the PLL
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;  // Specify the PLL source as HSE
  RCC_OscInitStruct.PLL.PLLM = 8;  // PLLM factor
  RCC_OscInitStruct.PLL.PLLN = 336;  // PLLN factor
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;  // PLLP factor
  RCC_OscInitStruct.PLL.PLLQ = 7;  // PLLQ factor
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)  // Configure the RCC Oscillators
  {
    Error_Handler();  // Handle error
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;  // Configure clock types
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;  // Specify SYSCLK source as PLL
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;  // AHB clock divider
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;  // APB1 clock divider
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;  // APB2 clock divider

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)  // Configure the clocks
  {
    Error_Handler();  // Handle error
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();  // Disable all interrupts
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}


