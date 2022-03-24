#ifndef __MODBUS_H
#define __MODBUS_H
 
#include "stm32f10x.h"
#include <stdio.h>
 
extern  u32 MODBUS_BaudRate[10];
extern  u16   Flash_Modbus_ADDR;   
extern  u16   Flash_Usart_BaudRate;   
  
void MODBUS_Send(unsigned char *buf,unsigned int length);
void MODBUS(unsigned char *buf,unsigned int length,unsigned int UsartNUM);
void MODBUS_ReadFromEEPROM(void);
void MODBUS_event(void);
void MODBUS_datain(void); 
unsigned int CRC_Calculate(unsigned char *str,unsigned int usDataLen);
extern unsigned short modbus_reg[];
 
#endif	

