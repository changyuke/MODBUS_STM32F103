#ifndef __LED_H
#define __LED_H	 
//#include "sys.h"
#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK��ӢSTM32������
//LED��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2012/9/2
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2009-2019
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 
//#define LED0 PBout(5)// PB5
//#define LED1 PEout(5)// PE5	

#define LED0_ON GPIO_ResetBits(GPIOB,GPIO_Pin_5)	 
#define LED1_ON GPIO_ResetBits(GPIOE,GPIO_Pin_5) 

#define LED0_OFF GPIO_SetBits(GPIOB,GPIO_Pin_5)
#define LED1_OFF GPIO_SetBits(GPIOE,GPIO_Pin_5)

void LED_Init(void);//��ʼ��

		 				    
#endif
