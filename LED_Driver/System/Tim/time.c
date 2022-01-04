#include "time.h"
#include "led.h"
#include "misc.h"

void timeInit(int pre,int psc)
{
	
	TIM_TimeBaseInitTypeDef TIM_InitStruct;
	NVIC_InitTypeDef NVIC_Struct;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);   //需要先定义结构体，在是使能时钟，否则报错
	TIM_InitStruct.TIM_Prescaler = psc;
	TIM_InitStruct.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_InitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_InitStruct.TIM_Period = pre;
	TIM_TimeBaseInit(TIM2, &TIM_InitStruct);
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
	
	NVIC_Struct.NVIC_IRQChannel = TIM2_IRQn ;
	NVIC_Struct.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_Struct.NVIC_IRQChannelSubPriority = 1;
	NVIC_Struct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_Struct);
	
	TIM_Cmd(TIM2, ENABLE);
}

void TIM2_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM2,TIM_IT_Update) != RESET)
	{
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
		LED0 = !LED0;
	}
}
