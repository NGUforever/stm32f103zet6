#ifndef __SYS_H
#define __SYS_H
#include "stm32f10x.h"

//定义系统文件夹是否支持UCOS,0-不支持，1-支持
#define SYSTEM_SUPPORT_OS 0
//位带操作
//I/O端口操作宏定义
#define BITBAND(addr, bitnum) ((addr & 0xF0000000)+0x2000000+((addr &0xFFFFF)<<5)+(bitnum<<2))
#define MEM_ADDR(addr)  *((volatile unsigned long *)(addr))
#define BIT_ADDR(addr, bitnum)  MEM_ADDR(BITBAND(addr, bitnum))
//I/O端口地址映射
#define GPIOA_ODR_Addr  (GPIOA_BASE+12)      //0x1001080C
#define GPIOB_ODR_Addr  (GPIOB_BASE+12)      //0x10010C0C
#define GPIOC_ODR_Addr  (GPIOC_BASE+12)      //0x1001100C
#define GPIOD_ODR_Addr  (GPIOD_BASE+12)      //0x1001140C
#define GPIOE_ODR_Addr  (GPIOE_BASE+12)      //0x1001180C
#define GPIOF_ODR_Addr  (GPIOF_BASE+12)      //0x10011A0C
#define GPIOG_ODR_Addr  (GPIOG_BASE+12)      //0x10011E0C
#define GPIOA_IDR_Addr  (GPIOA_BASE+8)      //0x10010808
#define GPIOB_IDR_Addr  (GPIOB_BASE+8)      //0x10010C08
#define GPIOC_IDR_Addr  (GPIOC_BASE+8)      //0x10011008
#define GPIOD_IDR_Addr  (GPIOD_BASE+8)      //0x10011408
#define GPIOE_IDR_Addr  (GPIOE_BASE+8)      //0x10011808
#define GPIOF_IDR_Addr  (GPIOF_BASE+8)      //0x10011A08
#define GPIOG_IDR_Addr  (GPIOG_BASE+8)      //0x10011E08
//I/O端口操作，只对单一的IO端口引脚，n取值为0~15
#define PAout(n)  BIT_ADDR(GPIOA_ODR_Addr,n)  //输出
#define PAin(n)   BIT_ADDR(GPIOA_IDR_Addr,n)  //输入
#define PBout(n)  BIT_ADDR(GPIOB_ODR_Addr,n)  //输出
#define PBin(n)   BIT_ADDR(GPIOB_IDR_Addr,n)  //输入
#define PCout(n)  BIT_ADDR(GPIOC_ODR_Addr,n)  //输出
#define PCin(n)   BIT_ADDR(GPIOC_IDR_Addr,n)  //输入
#define PDout(n)  BIT_ADDR(GPIOD_ODR_Addr,n)  //输出
#define PDin(n)   BIT_ADDR(GPIOD_IDR_Addr,n)  //输入
#define PEout(n)  BIT_ADDR(GPIOE_ODR_Addr,n)  //输出
#define PEin(n)   BIT_ADDR(GPIOE_IDR_Addr,n)  //输入
#define PFout(n)  BIT_ADDR(GPIOF_ODR_Addr,n)  //输出
#define PFin(n)   BIT_ADDR(GPIOF_IDR_Addr,n)  //输入
#define PGout(n)  BIT_ADDR(GPIOG_ODR_Addr,n)  //输出
#define PGin(n)   BIT_ADDR(GPIOG_IDR_Addr,n)  //输入
//汇编函数
void WFI_SET(void);                           //执行WFI命令
void INTX_DISABLE(void);                      //关闭所有中断
void INTX_ENABLE(void);                       //开启所有中断
void MSR_MSP(u32 addr);                       //设置堆栈地址
#endif
