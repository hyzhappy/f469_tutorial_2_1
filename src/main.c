/*让一只LED灯闪烁吧
 * */

#include <stdio.h>
#include <stdlib.h>
#include "diag/Trace.h"
#include "stm32f4xx_hal.h"
void SysTick_Handler()
{
	HAL_IncTick();
}
int
main(int argc, char* argv[])
{
	//使能SysTick，使其1ms中断一次
	HAL_SYSTICK_Config(SystemCoreClock/1000);
	//以下配置都是老套路了吧 <(￣︶￣)>
	//开启GPIOG的时钟
	__HAL_RCC_GPIOG_CLK_ENABLE();
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStructure.Pin = GPIO_PIN_6;
	GPIO_InitStructure.Pull = GPIO_PULLUP;
	GPIO_InitStructure.Speed = GPIO_SPEED_FAST;
	HAL_GPIO_Init(GPIOG, &GPIO_InitStructure);

	//先把G6电平拉低，点亮LED
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_6, GPIO_PIN_RESET);
	while (1)
    {
		//Toggle是翻转的意思哦，就是说原来是高电平就变为低电平，原来是低电平就变为高电平
		HAL_GPIO_TogglePin(GPIOG, GPIO_PIN_6);
		//通过SysTick延时1000个时间单位，也就是一秒钟喔 (゜▽＾*))
		HAL_Delay(1000);
    }
}
