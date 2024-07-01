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
    GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;  // Set mode to interrupt on rising edge
    GPIO_InitStruct.Pull = GPIO_NOPULL;  // Disable pull-up and pull-down resistors
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);  // Initialize the GPIO pin

    // Enable and set EXTI line 0 Interrupt to the lowest priority
    HAL_NVIC_SetPriority(EXTI0_IRQn, 2, 0);  // Set interrupt priority
    HAL_NVIC_EnableIRQ(EXTI0_IRQn);  // Enable the interrupt in the NVIC
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
  configure_Button_Pin();  // Configure button pin for interrupt

  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
    MX_USB_HOST_Process();  // Process USB host

    /* USER CODE BEGIN 3 */
    if (buttonPressed)  // Check if the button has been pressed
    {
        buttonPressed = 0; // Reset the flag

        HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12);  // Toggle LD4
        HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_13);  // Toggle LD3
        HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_14);  // Toggle LD5
        HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_15);  // Toggle LD6

        HAL_Delay(500); // Wait for 500 ms
    }
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

/**
  * @brief This function handles EXTI line0 interrupt.
  */
void EXTI0_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI0_IRQn 0 */

  /* USER CODE END EXTI0_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_0);  // Handle the EXTI line 0 interrupt
  /* USER CODE BEGIN EXTI0_IRQn 1 */

  buttonPressed = 1; // Set the flag to indicate button press

  /* USER CODE END EXTI0_IRQn 1 */
}

/**
  * @brief  EXTI line detection callback.
  * @param  GPIO_Pin: Specifies the pins connected EXTI line
  * @retval None
  */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  if (GPIO_Pin == GPIO_PIN_0)  // Check if the interrupt was caused by the button pin
  {
    // Handle the button press in the main loop
  }
}
