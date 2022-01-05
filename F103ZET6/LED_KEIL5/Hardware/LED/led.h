#ifndef __LED_H
#define __LED_H
#include "sys.h"

//LED端口定义
#define LED0 PBout(5)    //定义LED0为PB5输出位，位带操作
#define LED1 PEout(5)    //定义LED1为PE5输出位，位带操作
void LED_Init(void);      //LED端口初始化

#endif
