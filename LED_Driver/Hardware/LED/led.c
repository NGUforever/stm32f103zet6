#include "led.h"

//初始化与LED相连接的PE5和PB5引脚为输出，并使能这两个引脚的时钟
void LED_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);    //使能PB引脚
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;     //PB5引脚配置
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;         //推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;        //I/O端口速率为50MHz
	GPIO_Init(GPIOB, &GPIO_InitStructure);                   //初始化GPIOB
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);    //使能PE引脚
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;     //PE5引脚配置
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;         //推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;        //I/O端口速率为50MHz
	GPIO_Init(GPIOE, &GPIO_InitStructure);                   //初始化GPIOE
	
	GPIO_SetBits(GPIOB, GPIO_Pin_5);                         //PB5引脚输出高电平
	GPIO_SetBits(GPIOE, GPIO_Pin_5);                         //PE5引脚输出高电平
	
}
