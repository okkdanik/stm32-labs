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
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

    GPIOD->MODER = 0x55000000;
    GPIOD->OTYPER = 0;
    GPIOD->OSPEEDR = 0;

    GPIOA->MODER &= ~GPIO_MODER_MODE0;
    GPIOA->PUPDR |= GPIO_PUPDR_PUPD0_1;

    while (1) {
        if (GPIOA->IDR & GPIO_IDR_ID0) {
            for (uint32_t led = 0x1000; led <= 0x8000; led <<= 1) {
                GPIOD->ODR = led;
                for (i = 0; i < 250000; i++) {}
                GPIOD->ODR = 0x0000;
            }
        }
    }
}


