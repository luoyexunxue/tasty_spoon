/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : main.c
  - Author        : zeweni
  - Update date   : 2020.01.11
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

 * You should have received a copy of the Apache-2.0 License.8051 ELL 
 * low-layer libraries. If not, see <http://www.apache.org/licenses/>.
**/
/*-----------------------------------------------------------------------
|                               INCLUDES                                |
-----------------------------------------------------------------------*/
#include "main.h"
#include "../../mcu_sdk/bluetooth.h"

/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/
u16 frequency_set = 1;
u16 taste_set = 0;
u16 voltage_get = 0;

#define OUTPUT1 P34
#define OUTPUT2 P35

uint8_t adc_flag = 0;
uint8_t taste_flag = 0;
/*-----------------------------------------------------------------------
|                               FUNCTION                                |
-----------------------------------------------------------------------*/

/**
  * @name    main
  * @brief   main program
  * @param   None
  * @return  None
***/
int main(void)
{
	char buffer[20];
	OUTPUT1 = 0;
	OUTPUT2 = 0;
	STC8x_System_Init();
	bt_protocol_init();
	UART1_Isr_Send_String("Spoon is ready.\r\n");
	for(;;)
	{
		bt_uart_service();
		if (adc_flag > 0)
		{
			adc_flag = 0;
			voltage_get = ADC_Get_Sample(ADC_Channel_P32_8G1K08_T,ADC_Acc_10Bits);
			voltage_get = voltage_get * 32 / 5;
			mcu_dp_value_update(DPID_VOLTAGE,voltage_get);
			sprintf(buffer, "Voltage %d mV\r\n", voltage_get);
			UART1_Isr_Send_String(buffer);
		}
		if (taste_flag != taste_set)
		{
			taste_flag = taste_set;
			if (taste_flag == 0) UART1_Isr_Send_String("Taste none\r\n");
			else if (taste_flag == 1) UART1_Isr_Send_String("Taste salty\r\n");
			else if (taste_flag == 2) UART1_Isr_Send_String("Taste sour\r\n");
			else if (taste_flag == 3) UART1_Isr_Send_String("Taste bitter\r\n");
		}
	}
}

void timer_interval_500us()
{
	static u16 count = 0;
	static u16 elapse = 0;
	if (frequency_set == 0)
	{
		if (taste_set == 1) { OUTPUT1 = 1; OUTPUT2 = 1; }
		else if (taste_set == 2) { OUTPUT1 = 1; OUTPUT2 = 0; }
		else if (taste_set == 3) { OUTPUT1 = 0; OUTPUT2 = 1; }
		else { OUTPUT1 = 0; OUTPUT2 = 0; }
	}
	else if (count++ > 1000 / frequency_set)
	{
		count = 0;
		if (taste_set == 1) { OUTPUT1 = ~OUTPUT1; OUTPUT2 = OUTPUT1; }
		else if (taste_set == 2) { OUTPUT1 = ~OUTPUT1; OUTPUT2 = 0; }
		else if (taste_set == 3) { OUTPUT1 = 0; OUTPUT2 = ~OUTPUT2; }
		else { OUTPUT1 = 0; OUTPUT2 = 0; }
	}
	if (elapse++ > 6000)
	{
		elapse = 0;
		adc_flag = 1;
	}
}

/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/



