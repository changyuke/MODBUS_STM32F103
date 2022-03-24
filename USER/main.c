#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
#include "timer.h"
#include "modbus.h" 
//#include "stdio.h"
 
/************************************************
 ALIENTEK精英STM32开发板实验4
 串口 实验   
 技术支持：www.openedv.com
 淘宝店铺：http://eboard.taobao.com 
 关注微信公众平台微信号："正点原子"，免费获取STM32资料。
 广州市星翼电子科技有限公司  
 作者：正点原子 @ALIENTEK
************************************************/
	unsigned char send_buf[10];
    char receive_buf[205];
	unsigned char i;
 
 
int main(void)
{	
 
  USART1_Init();
	USART2_Init();
  LED_Init();
	delay_init();
	TIM3_Int_Init(1,7199);				//500us
	Flash_Modbus_ADDR=0x0001;			//
	Flash_Usart_BaudRate=0x0007;
	LED0_ON;
	LED1_ON;
	delay_ms(200);
	LED0_OFF;
	LED1_OFF;

	
  while(1)
	{	
		 MODBUS_event();						//MODBUS
	}	
}
