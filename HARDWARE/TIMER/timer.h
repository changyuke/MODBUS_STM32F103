#ifndef __TIMER_H
#define __TIMER_H
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ���������ɣ��������������κ���;
//ALIENTEKս��STM32������
//��ʱ�� ��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2012/9/3
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) �������������ӿƼ����޹�˾ 2009-2019
//All rights reserved									  
//////////////////////////////////////////////////////////////////////////////////   


void TIM3_Int_Init(u16 arr,u16 psc);
void TIM3_IRQHandler(void);
/*extern ����ȫ�ֱ���*/
extern u16 Receive_Complete;//�����Ƿ�������0Ϊδ���
//extern u16 Receive_Time;		//�����ϴν��ܹ�ȥ�೤ʱ��
extern u16 Received_Data_len;
#endif