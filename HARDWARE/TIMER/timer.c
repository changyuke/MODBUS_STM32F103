#include "timer.h"
#include "led.h"
#include "sys.h"
#include "modbus.h"
#include "usart.h"
//?????3?????
//APB1?SYSCLK?2??,?36M,????????APB1?2??,?72M
//arr:?????
//psc:?????
//?????????3!
void TIM3_Int_Init(u16 arr,u16 psc)
{
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
 
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); //????
	
	//???TIM3???
	TIM_TimeBaseStructure.TIM_Period = arr; //????????????
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //??????TIMx??????????
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //??????:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM??????
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //??????????TIMx???????
 
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE ); //?????TIM3??,??????
 
	//?????NVIC??
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;  //TIM3??
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  //?????0?
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;  //????3?
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQ?????
	NVIC_Init(&NVIC_InitStructure);  //???NVIC???
 
 
	TIM_Cmd(TIM3, ENABLE);  //??TIMx					 
}
////???3??????,100us
//u16 time3_usart1 = 0;
//u16 time3_usart2 = 0;
//u16 time3_usart3 = 0;
void TIM3_IRQHandler(void)   //TIM3??
{
	if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)  //??TIM3????????
		{
			TIM_ClearITPendingBit(TIM3, TIM_IT_Update  );  //??TIMx??????
			if(time3_usart1<=200)
        time3_usart1++;
			if(time3_usart2<=200)
        time3_usart2++;
			if(time3_usart3<=5000)
        time3_usart3++;
		}
		
}

