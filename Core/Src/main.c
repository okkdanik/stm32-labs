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
#include "stm32f4xx.h"

int main(void) {
    uint32_t i;

    RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;

    GPIOD->MODER = 0x55000000;
    GPIOD->OTYPER = 0;
    GPIOD->OSPEEDR = 0;

    while (1) {
        for (uint32_t led = 0x1000; led <= 0x8000; led <<= 1) {
            GPIOD->ODR = led;
            for (i = 0; i < 500000; i++) {}
            GPIOD->ODR = 0x0000;
        }
    }
}


