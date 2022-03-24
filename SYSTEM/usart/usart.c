#include "sys.h"
#include "usart.h"	  
#include "modbus.h"

 /**
  * @brief ???????????NVIC
  * @param  нч
  * @retval нч
  */
static void NVIC_usart1_Configuration(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;
  
  /* ???????????? */
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
  
  /*??USART????*/
  NVIC_InitStructure.NVIC_IRQChannel = DEBUG_USART1_IRQ;
  /* ?????*/
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  /* ???? */
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  /* ???? */
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  /*?????NVIC */
  NVIC_Init(&NVIC_InitStructure);
}
 
static void NVIC_usart2_Configuration(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;
  
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
  
  NVIC_InitStructure.NVIC_IRQChannel = DEBUG_USART2_IRQ;
 
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
 
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
 
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
 
  NVIC_Init(&NVIC_InitStructure);
}


void USART1_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
 
	// ????GPIO???
	DEBUG_USART1_GPIO_APBxClkCmd(DEBUG_USART1_GPIO_CLK, ENABLE);
	
	// ?????????
	DEBUG_USART1_APBxClkCmd(DEBUG_USART1_CLK, ENABLE);
 
	// ?USART Tx?GPIO?????????
	GPIO_InitStructure.GPIO_Pin = DEBUG_USART1_TX_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(DEBUG_USART1_TX_GPIO_PORT, &GPIO_InitStructure);
 
  // ?USART Rx?GPIO?????????
	GPIO_InitStructure.GPIO_Pin = DEBUG_USART1_RX_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(DEBUG_USART1_RX_GPIO_PORT, &GPIO_InitStructure);
	
	// ?????????
	// ?????
	USART_InitStructure.USART_BaudRate = DEBUG_USART1_BAUDRATE;
	// ?? ?????
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	// ?????
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	// ?????
	USART_InitStructure.USART_Parity = USART_Parity_No ;
	// ???????
	USART_InitStructure.USART_HardwareFlowControl = 
	USART_HardwareFlowControl_None;
	// ??????,????
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	// ??????????
	USART_Init(DEBUG_USART1, &USART_InitStructure);
	
	// ?????????
	NVIC_usart1_Configuration();
	
	// ????????
	USART_ITConfig(DEBUG_USART1, USART_IT_RXNE, ENABLE);	
	
	// ????
	USART_Cmd(DEBUG_USART1, ENABLE);	    
}
 
//?????2
void USART2_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
 
	DEBUG_USART2_GPIO_APBxClkCmd(DEBUG_USART2_GPIO_CLK, ENABLE);
	
	DEBUG_USART2_APBxClkCmd(DEBUG_USART2_CLK, ENABLE);
 
	GPIO_InitStructure.GPIO_Pin = DEBUG_USART2_TX_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(DEBUG_USART2_TX_GPIO_PORT, &GPIO_InitStructure);
 
	GPIO_InitStructure.GPIO_Pin = DEBUG_USART2_RX_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(DEBUG_USART2_RX_GPIO_PORT, &GPIO_InitStructure);
 
	USART_InitStructure.USART_BaudRate = DEBUG_USART2_BAUDRATE;
 
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
 
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
 
	USART_InitStructure.USART_Parity = USART_Parity_No ;
 
	USART_InitStructure.USART_HardwareFlowControl = 
	USART_HardwareFlowControl_None;
 
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
 
	USART_Init(DEBUG_USART2, &USART_InitStructure);
	
	NVIC_usart2_Configuration();
	
	USART_ITConfig(DEBUG_USART2, USART_IT_RXNE, ENABLE);	
	
	USART_Cmd(DEBUG_USART2, ENABLE);	    
}

unsigned char usart1_rx_buf[USART1_RX_LENGTH_MAX];
unsigned int usart1_rx_length=0;
unsigned char usart2_rx_buf[USART2_RX_LENGTH_MAX];
unsigned int usart2_rx_length=0;
unsigned char usart3_rx_buf[USART3_RX_LENGTH_MAX];
unsigned int usart3_rx_length=0;
unsigned int time3_usart1,time3_usart2,time3_usart3;//time3?????????????
 
 
//??1??????
void DEBUG_USART1_IRQHandler(void)
{
	if(USART_GetITStatus(DEBUG_USART1,USART_IT_RXNE)!=RESET)
	{	
		time3_usart1 =0;
		usart1_rx_buf[usart1_rx_length] = USART_ReceiveData(DEBUG_USART1);
 
		if(usart1_rx_length < USART1_RX_LENGTH_MAX)
    usart1_rx_length++;
 
	}	 
}
//??2??????
void DEBUG_USART2_IRQHandler(void)
{
 
	if(USART_GetITStatus(DEBUG_USART2,USART_IT_RXNE)!=RESET)
	{		
		time3_usart2 =0;
		usart2_rx_buf[usart2_rx_length] = USART_ReceiveData(DEBUG_USART2);
      //   USART_SendData(DEBUG_USART1,u1_rx_buf[num]);  //?????????  
		if(usart2_rx_length < USART1_RX_LENGTH_MAX)
    usart2_rx_length++; 
	}	 
}

void Usart1_SendString(u8 *buff,u8 len)
{
	u8 t;
	for(t=0;t<len;t++)	
	{
		while(USART_GetFlagStatus(USART1,USART_FLAG_TC)==RESET);
		USART_SendData(USART1,buff[t]); 
	}	 
	while(USART_GetFlagStatus(USART1,USART_FLAG_TC)==RESET);
}

void Usart2_SendString(u8 *buff,u8 len)
{
	u8 t;
	for(t=0;t<len;t++)	
	{
		while(USART_GetFlagStatus(USART2,USART_FLAG_TC)==RESET);
		USART_SendData(USART1,buff[t]); 
	}	 
	while(USART_GetFlagStatus(USART2,USART_FLAG_TC)==RESET);
}
