/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8Ax_PWM.c
  - Author        : zeweni
  - Update date   : 2020.05.06
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
#include "STC8x_PWM.h"
/*-----------------------------------------------------------------------
|                             DECLARATION                               |
-----------------------------------------------------------------------*/
/*--------------------------------------------------------
| @Description: PWM priority define function             |
--------------------------------------------------------*/


/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/
/* None */
/*-----------------------------------------------------------------------
|                               FUNCTION                                |
-----------------------------------------------------------------------*/

	#if (PER_LIB_MCU_MUODEL == STC8Ax)

			/**
			 * @brief     PWM计数器初始化,必须在所有PWM初始化函数的后面调用。
			 * @details   PWM counter init function,It must be initialized last.
			 * @param[in] clkSrc PWM时钟源。PWM clock source.
			 * @param[in] period PWM周期值（计数器重装载值）。PWM period value (counter reload value)
			 * @param[in] run 运行控制位。Run control bit.
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE PWM_CNT_Init(PWMCLKSrc_Type clkSrc,uint16_t period,BOOL run)
			{
			  if(period <= 0x7FFF)
			  {
				EAXFR_ENABLE();
				PWMCKS = clkSrc;
				PWMC = period;
				PWMCR = (PWMCR & 0x7F) | (run << 7);
				EAXFR_DISABLE();
				return FSC_SUCCESS;
			  }
			  else return FSC_FAIL;
			}

			/**
			 * @brief       PWM0通道初始化函数，它必须在PWM计数器初始化函数之前调用。
			 * @details     PWM0 road init function,it is best to initialize before the counter.
			 * @param[in]   level    PWM开始电平。PWM start level.
			 * @param[in]   fValue   第一个电平翻转点。The value of the first reversal point.
			 * @param[in]   sValue   第二个电平翻转点。The value of the second reversal point.
			 * @param[in]   run     运行控制位。Run control bit.
			 * @return      FSC_SUCCESS 返回成功。Return to success.
			 * @return      FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE PWM0_Init(PWMStartLevel_Type level,uint16_t fValue,uint16_t sValue,BOOL run)
			{
			  if(fValue <= 0x7FFF && sValue <= 0x7FFF)
			  {
				EAXFR_ENABLE();
				PWMxT1(PWM0T1_ADDRESS) = fValue;
				PWMxT2(PWM0T2_ADDRESS) = sValue;
				PWMxCR(PWM0CR_ADDRESS) = (PWMxCR(PWM0CR_ADDRESS) & 0xBF) | (level << 6);
				PWMxCR(PWM0CR_ADDRESS) = (PWMxCR(PWM0CR_ADDRESS) & 0x7F) | (run << 7);
				EAXFR_DISABLE();
				return FSC_SUCCESS;
			  }
			  else return FSC_FAIL;
			}

			/**
			 * @brief       PWM1通道初始化函数，它必须在PWM计数器初始化函数之前调用。
			 * @details     PWM1 road init function,it is best to initialize before the counter.
			 * @param[in]   level    PWM开始电平。PWM start level.
			 * @param[in]   fValue   第一个电平翻转点。The value of the first reversal point.
			 * @param[in]   sValue   第二个电平翻转点。The value of the second reversal point.
			 * @param[in]   run     运行控制位。Run control bit.
			 * @return      FSC_SUCCESS 返回成功。Return to success.
			 * @return      FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE PWM1_Init(PWMStartLevel_Type level,uint16_t fValue,uint16_t sValue,BOOL run)
			{
			  if(fValue <= 0x7FFF && sValue <= 0x7FFF)
			  {
				EAXFR_ENABLE();
				PWMxT1(PWM1T1_ADDRESS) = fValue;
				PWMxT2(PWM1T2_ADDRESS) = sValue;
				PWMxCR(PWM1CR_ADDRESS) = (PWMxCR(PWM1CR_ADDRESS) & 0xBF) | (level << 6);
				PWMxCR(PWM1CR_ADDRESS) = (PWMxCR(PWM1CR_ADDRESS) & 0x7F) | (run << 7);
				EAXFR_DISABLE();
				return FSC_SUCCESS;
			  }
			  else return FSC_FAIL;
			}

			/**
			 * @brief       PWM2通道初始化函数，它必须在PWM计数器初始化函数之前调用。
			 * @details     PWM2 road init function,it is best to initialize before the counter.
			 * @param[in]   level    PWM开始电平。PWM start level.
			 * @param[in]   fValue   第一个电平翻转点。The value of the first reversal point.
			 * @param[in]   sValue   第二个电平翻转点。The value of the second reversal point.
			 * @param[in]   run     运行控制位。Run control bit.
			 * @return      FSC_SUCCESS 返回成功。Return to success.
			 * @return      FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE PWM2_Init(PWMStartLevel_Type level,uint16_t fValue,uint16_t sValue,BOOL run)
			{
			  if(fValue <= 0x7FFF && sValue <= 0x7FFF)
			  {
				EAXFR_ENABLE();
				PWMxT1(PWM2T1_ADDRESS) = fValue;
				PWMxT2(PWM2T2_ADDRESS) = sValue;
				PWMxCR(PWM2CR_ADDRESS) = (PWMxCR(PWM2CR_ADDRESS) & 0xBF) | (level << 6);
				PWMxCR(PWM2CR_ADDRESS) = (PWMxCR(PWM2CR_ADDRESS) & 0x7F) | (run << 7);
				EAXFR_DISABLE();
				return FSC_SUCCESS;
			  }
			  else return FSC_FAIL;
			}

			/**
			 * @brief       PWM3通道初始化函数，它必须在PWM计数器初始化函数之前调用。
			 * @details     PWM3 road init function,it is best to initialize before the counter.
			 * @param[in]   level    PWM开始电平。PWM start level.
			 * @param[in]   fValue   第一个电平翻转点。The value of the first reversal point.
			 * @param[in]   sValue   第二个电平翻转点。The value of the second reversal point.
			 * @param[in]   run     运行控制位。Run control bit.
			 * @return      FSC_SUCCESS 返回成功。Return to success.
			 * @return      FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE PWM3_Init(PWMStartLevel_Type level,uint16_t fValue,uint16_t sValue,BOOL run)
			{
			  if(fValue <= 0x7FFF && sValue <= 0x7FFF)
			  {
				EAXFR_ENABLE();
				PWMxT1(PWM3T1_ADDRESS) = fValue;
				PWMxT2(PWM3T2_ADDRESS) = sValue;
				PWMxCR(PWM3CR_ADDRESS) = (PWMxCR(PWM3CR_ADDRESS) & 0xBF) | (level << 6);
				PWMxCR(PWM3CR_ADDRESS) = (PWMxCR(PWM3CR_ADDRESS) & 0x7F) | (run << 7);
				EAXFR_DISABLE();
				return FSC_SUCCESS;
			  }
			  else return FSC_FAIL;
			}

			/**
			 * @brief       PWM4通道初始化函数，它必须在PWM计数器初始化函数之前调用。
			 * @details     PWM4 road init function,it is best to initialize before the counter.
			 * @param[in]   level    PWM开始电平。PWM start level.
			 * @param[in]   fValue   第一个电平翻转点。The value of the first reversal point.
			 * @param[in]   sValue   第二个电平翻转点。The value of the second reversal point.
			 * @param[in]   run     运行控制位。Run control bit.
			 * @return      FSC_SUCCESS 返回成功。Return to success.
			 * @return      FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE PWM4_Init(PWMStartLevel_Type level,uint16_t fValue,uint16_t sValue,BOOL run)
			{
			  if(fValue <= 0x7FFF && sValue <= 0x7FFF)
			  {
				EAXFR_ENABLE();
				PWMxT1(PWM4T1_ADDRESS) = fValue;
				PWMxT2(PWM4T2_ADDRESS) = sValue;
				PWMxCR(PWM4CR_ADDRESS) = (PWMxCR(PWM4CR_ADDRESS) & 0xBF) | (level << 6);
				PWMxCR(PWM4CR_ADDRESS) = (PWMxCR(PWM4CR_ADDRESS) & 0x7F) | (run << 7);
				EAXFR_DISABLE();
				return FSC_SUCCESS;
			  }
			  else return FSC_FAIL;
			}

			/**
			 * @brief       PWM5通道初始化函数，它必须在PWM计数器初始化函数之前调用。
			 * @details     PWM5 road init function,it is best to initialize before the counter.
			 * @param[in]   level    PWM开始电平。PWM start level.
			 * @param[in]   fValue   第一个电平翻转点。The value of the first reversal point.
			 * @param[in]   sValue   第二个电平翻转点。The value of the second reversal point.
			 * @param[in]   run     运行控制位。Run control bit.
			 * @return      FSC_SUCCESS 返回成功。Return to success.
			 * @return      FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE PWM5_Init(PWMStartLevel_Type level,uint16_t fValue,uint16_t sValue,BOOL run)
			{
			  if(fValue <= 0x7FFF && sValue <= 0x7FFF)
			  {
				EAXFR_ENABLE();
				PWMxT1(PWM5T1_ADDRESS) = fValue;
				PWMxT2(PWM5T2_ADDRESS) = sValue;
				PWMxCR(PWM5CR_ADDRESS) = (PWMxCR(PWM5CR_ADDRESS) & 0xBF) | (level << 6);
				PWMxCR(PWM5CR_ADDRESS) = (PWMxCR(PWM5CR_ADDRESS) & 0x7F) | (run << 7);
				EAXFR_DISABLE();
				return FSC_SUCCESS;
			  }
			  else return FSC_FAIL;
			}

			/**
			 * @brief       PWM6通道初始化函数，它必须在PWM计数器初始化函数之前调用。
			 * @details     PWM6 road init function,it is best to initialize before the counter.
			 * @param[in]   level    PWM开始电平。PWM start level.
			 * @param[in]   fValue   第一个电平翻转点。The value of the first reversal point.
			 * @param[in]   sValue   第二个电平翻转点。The value of the second reversal point.
			 * @param[in]   run     运行控制位。Run control bit.
			 * @return      FSC_SUCCESS 返回成功。Return to success.
			 * @return      FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE PWM6_Init(PWMStartLevel_Type level,uint16_t fValue,uint16_t sValue,BOOL run)
			{
			  if(fValue <= 0x7FFF && sValue <= 0x7FFF)
			  {
				EAXFR_ENABLE();
				PWMxT1(PWM6T1_ADDRESS) = fValue;
				PWMxT2(PWM6T2_ADDRESS) = sValue;
				PWMxCR(PWM6CR_ADDRESS) = (PWMxCR(PWM6CR_ADDRESS) & 0xBF) | (level << 6);
				PWMxCR(PWM6CR_ADDRESS) = (PWMxCR(PWM6CR_ADDRESS) & 0x7F) | (run << 7);
				EAXFR_DISABLE();
				return FSC_SUCCESS;
			  }
			  else return FSC_FAIL;
			}

			/**
			 * @brief       PWM7通道初始化函数，它必须在PWM计数器初始化函数之前调用。
			 * @details     PWM7 road init function,it is best to initialize before the counter.
			 * @param[in]   level    PWM开始电平。PWM start level.
			 * @param[in]   fValue   第一个电平翻转点。The value of the first reversal point.
			 * @param[in]   sValue   第二个电平翻转点。The value of the second reversal point.
			 * @param[in]   run     运行控制位。Run control bit.
			 * @return      FSC_SUCCESS 返回成功。Return to success.
			 * @return      FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE PWM7_Init(PWMStartLevel_Type level,uint16_t fValue,uint16_t sValue,BOOL run)
			{
			  if(fValue <= 0x7FFF && sValue <= 0x7FFF)
			  {
				EAXFR_ENABLE();
				PWMxT1(PWM7T1_ADDRESS) = fValue;
				PWMxT2(PWM7T2_ADDRESS) = sValue;
				PWMxCR(PWM7CR_ADDRESS) = (PWMxCR(PWM7CR_ADDRESS) & 0xBF) | (level << 6);
				PWMxCR(PWM7CR_ADDRESS) = (PWMxCR(PWM7CR_ADDRESS) & 0x7F) | (run << 7);
				EAXFR_DISABLE();
				return FSC_SUCCESS;
			  }
			  else return FSC_FAIL;
			}

			/**
			 * @brief       PWM异常检测初始化函数。
			 * @details     PWM abnormal detection init function.
			 * @param[in]   sigSrc  异常检测信号源。Anomaly detection signal source.
			 * @param[in]   mode    异常检测模式选择。Anomaly detection mode selection.
			 * @param[in]   run     运行控制位。Run control bit.
			 * @return      FSC_SUCCESS 返回成功。Return to success.
			 * @return      FSC_FAIL    返回失败。Return to fail.
			**/			
			FSCSTATE PWM_ABD_Init( PWMABDSignal_Type sigSrc,PWMABDMode_Type mode,BOOL run)
			{
			  EAXFR_ENABLE();
			  PWMFDCR = (PWMFDCR & 0xF9) | (sigSrc);
			  PWMFDCR = (PWMFDCR & 0x3F) | (mode);
			  PWMFDCR = (PWMFDCR & 0xF7) | (run);
			  EAXFR_DISABLE();
			  return FSC_SUCCESS;
			}


			/**
			 * @brief       PWM触发ADC函数。
			 * @details     PWM trigger associated ADC init function.
			 * @param[in]   tValue  触发ADC的计数值。The value of trigger associated ADC.
			 * @param[in]   run     运行控制位。Run control bit.
			 * @return      FSC_SUCCESS 返回成功。Return to success.
			 * @return      FSC_FAIL    返回失败。Return to fail.
			**/			
			FSCSTATE PWM_ETADC_Init(uint16_t tValue,BOOL run)
			{
			  if(tValue <= 0x7FFF)
			  {
				EAXFR_ENABLE();
				TADCP = tValue;
				PWMCFG = (PWMCFG & 0xBF) | (run << 6);
				EAXFR_DISABLE();  
				return FSC_SUCCESS;
			  }
			  else return FSC_FAIL;  
			}

			/**
			 * @brief     PWM计数器中断初始化函数。
			 * @details   PWM Counter NVIC function.   
			 * @param[in] pri 中断优先级。interrupt priority.
			 * @param[in] run 使能控制位。enable control. 
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE NVIC_PWM_CNT_Init(NVICPri_Type pri,BOOL run)
			{
				NVIC_PWM_CNT_PRI(pri);
				PWMCR = (PWMCR & 0xBF) | (run << 6);
				return FSC_SUCCESS;
			}


			/**
			 * @brief     PWM异常检测中断初始化函数。
			 * @details   PWM abnormal detection NVIC function.   
			 * @param[in] pri 中断优先级。interrupt priority.
			 * @param[in] run 使能控制位。enable control. 
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE NVIC_PWM_ABD_Init(NVICPri_Type pri,BOOL run)
			{
				EAXFR_ENABLE();
				NVIC_PWM_ABD_PRI(pri);
				PWMFDCR = (PWMFDCR & 0xF7) | (run << 3);
				EAXFR_DISABLE();
				return FSC_SUCCESS;
			}


			/**
			 * @brief     PWM0中断初始化函数，设置触发中断的电平翻转点。
			 * @details   PWM0 interrupt initialization function, 
			 *            set the level flip point that triggers the interrupt.
			 * @param[in] flipPoint 电平翻转点 Level flip point.
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			 * @note      PWM0~7,与PWM计数器共用一个中断服务入口，如果设置的电平触发点为无，那么将关闭这个中断。
			 *            PWM0~7 share an interrupt service entry with the PWM counter. 
			 *            If the set level trigger point is none, then this interrupt will be closed.
			**/
			FSCSTATE NVIC_PWM0_Init(PWMFlip_Type flipPoint)
			{
				EAXFR_ENABLE();
				PWMxCR(PWM0CR_ADDRESS) = (PWMxCR(PWM0CR_ADDRESS) & 0xF8) | (flipPoint);
				EAXFR_DISABLE();
				return FSC_SUCCESS;
			}

			
			/**
			 * @brief     PWM1中断初始化函数，设置触发中断的电平翻转点。
			 * @details   PWM1 interrupt initialization function, 
			 *            set the level flip point that triggers the interrupt.
			 * @param[in] flipPoint 电平翻转点 Level flip point.
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			 * @note      PWM0~7,与PWM计数器共用一个中断服务入口，如果设置的电平触发点为无，那么将关闭这个中断。
			 *            PWM0~7 share an interrupt service entry with the PWM counter. 
			 *            If the set level trigger point is none, then this interrupt will be closed.
			**/
			FSCSTATE NVIC_PWM1_Init(PWMFlip_Type flipPoint)
			{
				EAXFR_ENABLE();
				PWMxCR(PWM1CR_ADDRESS) = (PWMxCR(PWM1CR_ADDRESS) & 0xF8) | (flipPoint);
				EAXFR_DISABLE();
				return FSC_SUCCESS;
			}

			
			/**
			 * @brief     PWM2中断初始化函数，设置触发中断的电平翻转点。
			 * @details   PWM2 interrupt initialization function, 
			 *            set the level flip point that triggers the interrupt.
			 * @param[in] flipPoint 电平翻转点 Level flip point.
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			 * @note      PWM0~7,与PWM计数器共用一个中断服务入口，如果设置的电平触发点为无，那么将关闭这个中断。
			 *            PWM0~7 share an interrupt service entry with the PWM counter. 
			 *            If the set level trigger point is none, then this interrupt will be closed.
			**/
			FSCSTATE NVIC_PWM2_Init(PWMFlip_Type flipPoint)
			{
				EAXFR_ENABLE();
				PWMxCR(PWM2CR_ADDRESS) = (PWMxCR(PWM2CR_ADDRESS) & 0xF8) | (flipPoint);
				EAXFR_DISABLE();
				return FSC_SUCCESS;
			}

			
			/**
			 * @brief     PWM3中断初始化函数，设置触发中断的电平翻转点。
			 * @details   PWM3 interrupt initialization function, 
			 *            set the level flip point that triggers the interrupt.
			 * @param[in] flipPoint 电平翻转点 Level flip point.
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			 * @note      PWM0~7,与PWM计数器共用一个中断服务入口，如果设置的电平触发点为无，那么将关闭这个中断。
			 *            PWM0~7 share an interrupt service entry with the PWM counter. 
			 *            If the set level trigger point is none, then this interrupt will be closed.
			**/
			FSCSTATE NVIC_PWM3_Init(PWMFlip_Type flipPoint)
			{
				EAXFR_ENABLE();
				PWMxCR(PWM3CR_ADDRESS) = (PWMxCR(PWM3CR_ADDRESS) & 0xF8) | (flipPoint);
				EAXFR_DISABLE();
				return FSC_SUCCESS;
			}

			
			/**
			 * @brief     PWM4中断初始化函数，设置触发中断的电平翻转点。
			 * @details   PWM4 interrupt initialization function, 
			 *            set the level flip point that triggers the interrupt.
			 * @param[in] flipPoint 电平翻转点 Level flip point.
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			 * @note      PWM0~7,与PWM计数器共用一个中断服务入口，如果设置的电平触发点为无，那么将关闭这个中断。
			 *            PWM0~7 share an interrupt service entry with the PWM counter. 
			 *            If the set level trigger point is none, then this interrupt will be closed.
			**/
			FSCSTATE NVIC_PWM4_Init(PWMFlip_Type flipPoint)
			{
				EAXFR_ENABLE();
				PWMxCR(PWM4CR_ADDRESS) = (PWMxCR(PWM4CR_ADDRESS) & 0xF8) | (flipPoint);
				EAXFR_DISABLE();
				return FSC_SUCCESS;
			}

			
			/**
			 * @brief     PWM5中断初始化函数，设置触发中断的电平翻转点。
			 * @details   PWM5 interrupt initialization function, 
			 *            set the level flip point that triggers the interrupt.
			 * @param[in] flipPoint 电平翻转点 Level flip point.
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			 * @note      PWM0~7,与PWM计数器共用一个中断服务入口，如果设置的电平触发点为无，那么将关闭这个中断。
			 *            PWM0~7 share an interrupt service entry with the PWM counter. 
			 *            If the set level trigger point is none, then this interrupt will be closed.
			**/
			FSCSTATE NVIC_PWM5_Init(PWMFlip_Type flipPoint)
			{
				EAXFR_ENABLE();
				PWMxCR(PWM5CR_ADDRESS) = (PWMxCR(PWM5CR_ADDRESS) & 0xF8) | (flipPoint);
				EAXFR_DISABLE();
				return FSC_SUCCESS;
			}

			
			/**
			 * @brief     PWM6中断初始化函数，设置触发中断的电平翻转点。
			 * @details   PWM6 interrupt initialization function, 
			 *            set the level flip point that triggers the interrupt.
			 * @param[in] flipPoint 电平翻转点 Level flip point.
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			 * @note      PWM0~7,与PWM计数器共用一个中断服务入口，如果设置的电平触发点为无，那么将关闭这个中断。
			 *            PWM0~7 share an interrupt service entry with the PWM counter. 
			 *            If the set level trigger point is none, then this interrupt will be closed.
			**/
			FSCSTATE NVIC_PWM6_Init(PWMFlip_Type flipPoint)
			{
				EAXFR_ENABLE();
				PWMxCR(PWM6CR_ADDRESS) = (PWMxCR(PWM6CR_ADDRESS) & 0xF8) | (flipPoint);
				EAXFR_DISABLE();
				return FSC_SUCCESS;
			}

			
			/**
			 * @brief     PWM7中断初始化函数，设置触发中断的电平翻转点。
			 * @details   PWM7 interrupt initialization function, 
			 *            set the level flip point that triggers the interrupt.
			 * @param[in] flipPoint 电平翻转点 Level flip point.
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			 * @note      PWM0~7,与PWM计数器共用一个中断服务入口，如果设置的电平触发点为无，那么将关闭这个中断。
			 *            PWM0~7 share an interrupt service entry with the PWM counter. 
			 *            If the set level trigger point is none, then this interrupt will be closed.
			**/
			FSCSTATE NVIC_PWM7_Init(PWMFlip_Type flipPoint)
			{
				EAXFR_ENABLE();
				PWMxCR(PWM7CR_ADDRESS) = (PWMxCR(PWM7CR_ADDRESS) & 0xF8) | (flipPoint);
				EAXFR_DISABLE();
				return FSC_SUCCESS;
			}

			
			/**
			 * @brief     PWM0切换复用IO函数。
			 * @details   PWM0 switch out port control function.  
			 * @param[in] port 复用IO枚举体。IO switch enumerator.
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE GPIO_PWM0_SWPort(GPIOSWPort_Type port)
			{
				if(port <= SW_Port3)
				{
					EAXFR_ENABLE();
					PWMxCR(PWM0CR_ADDRESS) = (PWMxCR(PWM0CR_ADDRESS) & 0xC7) | (port << 3);
					EAXFR_DISABLE();
					return FSC_SUCCESS;
				}
				else return FSC_FAIL;
			}

			
			
			/**
			 * @brief     PWM1切换复用IO函数。
			 * @details   PWM1 switch out port control function.  
			 * @param[in] port 复用IO枚举体。IO switch enumerator.
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE GPIO_PWM1_SWPort(GPIOSWPort_Type port)
			{
				if(port <= SW_Port3)
				{
					EAXFR_ENABLE();
					PWMxCR(PWM1CR_ADDRESS) = (PWMxCR(PWM1CR_ADDRESS) & 0xC7) | (port << 3);
					EAXFR_DISABLE();
					return FSC_SUCCESS;
				}
				else return FSC_FAIL;
			}

			
			/**
			 * @brief     PWM2切换复用IO函数。
			 * @details   PWM2 switch out port control function.  
			 * @param[in] port 复用IO枚举体。IO switch enumerator.
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE GPIO_PWM2_SWPort(GPIOSWPort_Type port)
			{
				if(port <= SW_Port3)
				{
					EAXFR_ENABLE();
					PWMxCR(PWM2CR_ADDRESS) = (PWMxCR(PWM2CR_ADDRESS) & 0xC7) | (port << 3);
					EAXFR_DISABLE();
					return FSC_SUCCESS;
				}
				else return FSC_FAIL;
			}

			
			/**
			 * @brief     PWM3切换复用IO函数。
			 * @details   PWM3 switch out port control function.  
			 * @param[in] port 复用IO枚举体。IO switch enumerator.
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE GPIO_PWM3_SWPort(GPIOSWPort_Type port)
			{
				if(port <= SW_Port3)
				{
					EAXFR_ENABLE();
					PWMxCR(PWM3CR_ADDRESS) = (PWMxCR(PWM3CR_ADDRESS) & 0xC7) | (port << 3);
					EAXFR_DISABLE();
					return FSC_SUCCESS;
				}
				else return FSC_FAIL;
			}

			
			/**
			 * @brief     PWM4切换复用IO函数。
			 * @details   PWM4 switch out port control function.  
			 * @param[in] port 复用IO枚举体。IO switch enumerator.
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE GPIO_PWM4_SWPort(GPIOSWPort_Type port)
			{
				if(port <= SW_Port3)
				{
					EAXFR_ENABLE();
					PWMxCR(PWM4CR_ADDRESS) = (PWMxCR(PWM4CR_ADDRESS) & 0xC7) | (port << 3);
					EAXFR_DISABLE();
					return FSC_SUCCESS;
				}
				else return FSC_FAIL;
			}

			
			/**
			 * @brief     PWM5切换复用IO函数。
			 * @details   PWM5 switch out port control function.  
			 * @param[in] port 复用IO枚举体。IO switch enumerator.
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE GPIO_PWM5_SWPort(GPIOSWPort_Type port)
			{
				if(port <= SW_Port3)
				{
					EAXFR_ENABLE();
					PWMxCR(PWM5CR_ADDRESS) = (PWMxCR(PWM5CR_ADDRESS) & 0xC7) | (port << 3);
					EAXFR_DISABLE();
					return FSC_SUCCESS;
				}
				else return FSC_FAIL;
			}


			/**
			 * @brief     PWM6切换复用IO函数。
			 * @details   PWM6 switch out port control function.  
			 * @param[in] port 复用IO枚举体。IO switch enumerator.
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE GPIO_PWM6_SWPort(GPIOSWPort_Type port)
			{
				if(port <= SW_Port3)
				{
					EAXFR_ENABLE();
					PWMxCR(PWM6CR_ADDRESS) = (PWMxCR(PWM6CR_ADDRESS) & 0xC7) | (port << 3);
					EAXFR_DISABLE();
					return FSC_SUCCESS;
				}
				else return FSC_FAIL;
			}

			
			/**
			 * @brief     PWM7切换复用IO函数。
			 * @details   PWM7 switch out port control function.  
			 * @param[in] port 复用IO枚举体。IO switch enumerator.
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE GPIO_PWM7_SWPort(GPIOSWPort_Type port)
			{
				if(port <= SW_Port3)
				{
					EAXFR_ENABLE();
					PWMxCR(PWM7CR_ADDRESS) = (PWMxCR(PWM7CR_ADDRESS) & 0xC7) | (port << 3);
					EAXFR_DISABLE();
					return FSC_SUCCESS;
				}
				else return FSC_FAIL;
			}


#endif
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/



