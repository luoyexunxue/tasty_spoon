/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : init.c
  - Author        : zeweni
  - Update date   : 2021.07.25
  -	Copyright(C)  : 2020-2021 zeweni. All rights reserved.
-----------------------------------------------------------------------*/
/*------------------------------------------------------------------------
|                            COPYRIGHT NOTICE                            |
------------------------------------------------------------------------*/
/*
 * Copyright (C) 2021, zeweni (17870070675@163.com)

 * This file is part of 8051 ELL low-layer libraries.

 * 8051 ELL low-layer libraries is free software: you can redistribute 
 * it and/or modify it under the terms of the Apache-2.0 License.

 * 8051 ELL low-layer libraries is distributed in the hope that it will 
 * be useful,but WITHOUT ANY WARRANTY; without even the implied warranty 
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the 
 * Apache-2.0 License License for more details.

 * You should have received a copy of the Apache-2.0 License.Ant Real Time
 * Operating System. If not, see <http://www.apache.org/licenses/>.
**/
/*-----------------------------------------------------------------------
|                               INCLUDES                                |
-----------------------------------------------------------------------*/
#include "main.h"
/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/

/*--------------------------------------------------------
| @Description: MCU peripheral initialization function   |
--------------------------------------------------------*/

static void STC8x_GPIO_Config(void);
static void STC8x_UART_Config(void);
static void STC8x_ADC_Config(void);
static void STC8x_TIMER_Config(void);

/*-----------------------------------------------------------------------
|                               FUNCTION                                |
-----------------------------------------------------------------------*/

/**
  * @name    STC8x_System_Init
  * @brief   MCU initialization function
  * @param   None
  * @return  None
***/
void STC8x_System_Init(void)
{
	DELAY_Init();
	
	STC8x_GPIO_Config();
	STC8x_UART_Config();
	STC8x_ADC_Config();
	STC8x_TIMER_Config();
	
	NVIC_GLOBAL_ENABLE();
}

/**
  * @name    STC8x_GPIO_Config
  * @brief   MCU GPIO initialization function
  * @param   None
  * @return  None
***/
static void STC8x_GPIO_Config(void)
{
	/* IN+ IN- */
	GPIO_MODE_OUT_PP(GPIO_P3,Pin_4);
	GPIO_MODE_OUT_PP(GPIO_P3,Pin_5);
}

/**
  * @name    STC8x_UART_Config
  * @brief   MCU UART initialization function
  * @param   None
  * @return  None
***/
static void STC8x_UART_Config(void)
{
	UART_InitType UART_InitStruct = {0};
	
	/* UART1 115200 */
	GPIO_MODE_OUT_PP(GPIO_P3,Pin_1);
	GPIO_MODE_IN_FLOATING(GPIO_P3,Pin_0);
	UART_InitStruct.Mode = UART_8bit_BRTx;
	UART_InitStruct.BRTGen = UART_BRT_TIM1;
	UART_InitStruct.BRTMode = UART_BRT_1T;
	UART_InitStruct.BaudRate = 112300;
	UART_InitStruct.RxEnable = ENABLE;
	UART1_Init(&UART_InitStruct);
	NVIC_UART1_Init(NVIC_PR3,ENABLE);
	
	/* UART2 9600 */
	GPIO_MODE_OUT_OD(GPIO_P1,Pin_1);
	GPIO_MODE_IN_FLOATING(GPIO_P1,Pin_0);
	UART_InitStruct.Mode = UART_8bit_BRTx;
	UART_InitStruct.BRTGen = UART_BRT_TIM2;
	UART_InitStruct.BRTMode = UART_BRT_1T;
	UART_InitStruct.BaudRate = 9600;
	UART_InitStruct.RxEnable = ENABLE;
	UART2_Init(&UART_InitStruct);
	NVIC_UART2_Init(NVIC_PR2,ENABLE);
}

/**
  * @name    STC8x_ADC_Config
  * @brief   MCU ADC initialization function
  * @param   None
  * @return  None
***/
static void STC8x_ADC_Config(void)
{
	ADC_InitType ADC_InitStruct = {0};

	GPIO_MODE_IN_FLOATING(GPIO_P3,Pin_2);
	ADC_InitStruct.Power = ENABLE;
	ADC_InitStruct.Channel = ADC_Channel_P32_8G1K08_T;
	ADC_InitStruct.Speed = 0x0F;
	ADC_InitStruct.Align = ADC_Right;
	ADC_InitStruct.Run = ENABLE;
	ADC_Init(&ADC_InitStruct);
}

/**
  * @name    STC8x_TIMER_Config
  * @brief   MCU TIMER initialization function
  * @param   None
  * @return  None
***/
void STC8x_TIMER_Config(void)
{
	TIMER_InitType  TIMER_InitStruct = {0};

	TIMER_InitStruct.Type = TIMER_Type_Timer;
	TIMER_InitStruct.Mode = TIMER_16BitAutoReload;
	TIMER_InitStruct.TCycle = TIMER_TCY_1T;
	TIMER_InitStruct.ClkOut = DISABLE;
	TIMER_InitStruct.Time = 500;
	TIMER_InitStruct.Run = ENABLE;
	TIMER0_Init(&TIMER_InitStruct);
	NVIC_TIMER0_Init(NVIC_PR1,ENABLE);
}

/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/
