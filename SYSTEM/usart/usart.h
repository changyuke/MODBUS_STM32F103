#ifndef __USART_H
#define __USART_H
#include "stdio.h"	
#include "sys.h" 
#define USART1_RX_LENGTH_MAX    200
#define USART2_RX_LENGTH_MAX    200
#define USART3_RX_LENGTH_MAX    250
 
extern unsigned char USART2_OV_FLAG;
extern unsigned char USART1_OV_FLAG;
extern unsigned char usart1_rx_buf[USART1_RX_LENGTH_MAX];//??1???????
extern unsigned int  usart1_rx_length;
extern unsigned char usart2_rx_buf[USART2_RX_LENGTH_MAX];
extern unsigned int  usart2_rx_length;
extern unsigned char usart3_rx_buf[USART3_RX_LENGTH_MAX];
extern unsigned int  usart3_rx_length;
extern unsigned int  time3_usart1,time3_usart2,time3_usart3;

void USART1_Init(void);
void USART2_Init(void);
void Usart1_SendString(u8 *buff,u8 len);
void Usart2_SendString(u8 *buff,u8 len);
//	
//??1USART1
#define  DEBUG_USART1                    USART1
#define  DEBUG_USART1_CLK                RCC_APB2Periph_USART1
#define  DEBUG_USART1_APBxClkCmd         RCC_APB2PeriphClockCmd
#define  DEBUG_USART1_BAUDRATE           115200           ///???
 
// USART GPIO ???????
#define  DEBUG_USART1_GPIO_CLK           (RCC_APB2Periph_GPIOA)
#define  DEBUG_USART1_GPIO_APBxClkCmd    RCC_APB2PeriphClockCmd
    
#define  DEBUG_USART1_TX_GPIO_PORT       GPIOA   
#define  DEBUG_USART1_TX_GPIO_PIN        GPIO_Pin_9
#define  DEBUG_USART1_RX_GPIO_PORT       GPIOA
#define  DEBUG_USART1_RX_GPIO_PIN        GPIO_Pin_10
 
#define  DEBUG_USART1_IRQ                USART1_IRQn
#define  DEBUG_USART1_IRQHandler         USART1_IRQHandler
 
 
//??2-USART2
#define  DEBUG_USART2                   USART2
#define  DEBUG_USART2_CLK                RCC_APB1Periph_USART2
#define  DEBUG_USART2_APBxClkCmd         RCC_APB1PeriphClockCmd
#define  DEBUG_USART2_BAUDRATE           115200
 
// USART GPIO ???????
#define  DEBUG_USART2_GPIO_CLK           (RCC_APB2Periph_GPIOA)
#define  DEBUG_USART2_GPIO_APBxClkCmd    RCC_APB2PeriphClockCmd
    
#define  DEBUG_USART2_TX_GPIO_PORT       GPIOA   
#define  DEBUG_USART2_TX_GPIO_PIN        GPIO_Pin_2
#define  DEBUG_USART2_RX_GPIO_PORT       GPIOA
#define  DEBUG_USART2_RX_GPIO_PIN        GPIO_Pin_3
 
#define  DEBUG_USART2_IRQ                USART2_IRQn
#define  DEBUG_USART2_IRQHandler         USART2_IRQHandler
#endif


