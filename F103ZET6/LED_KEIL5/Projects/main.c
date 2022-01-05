#include "led.h"
#include "sys.h"
#include "time.h"

void Delay(uint32_t count)
{
	u32 i = 0;
	for(;i<count;i++);
}

int main(void)
{
	LED_Init();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	timeInit(4999,7199);
//	GPIO_ResetBits(GPIOD, GPIO_Pin_7);                         //PA2引脚输出高电平
	while(1)
	{
		LED1 = !LED1;
		Delay(50000);
	}
		
}
