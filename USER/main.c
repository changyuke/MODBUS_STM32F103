#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
#include "timer.h"
#include "modbus.h" 
//#include "stdio.h"
 
/************************************************
 ALIENTEK��ӢSTM32������ʵ��4
 ���� ʵ��   
 ����֧�֣�www.openedv.com
 �Ա����̣�http://eboard.taobao.com 
 ��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 ������������ӿƼ����޹�˾  
 ���ߣ�����ԭ�� @ALIENTEK
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
