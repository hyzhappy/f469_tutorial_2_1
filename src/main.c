/*��һֻLED����˸��
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
	//ʹ��SysTick��ʹ��1ms�ж�һ��
	HAL_SYSTICK_Config(SystemCoreClock/1000);
	//�������ö�������·�˰� <(�����)>
	//����GPIOG��ʱ��
	__HAL_RCC_GPIOG_CLK_ENABLE();
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStructure.Pin = GPIO_PIN_6;
	GPIO_InitStructure.Pull = GPIO_PULLUP;
	GPIO_InitStructure.Speed = GPIO_SPEED_FAST;
	HAL_GPIO_Init(GPIOG, &GPIO_InitStructure);

	//�Ȱ�G6��ƽ���ͣ�����LED
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_6, GPIO_PIN_RESET);
	while (1)
    {
		//Toggle�Ƿ�ת����˼Ŷ������˵ԭ���Ǹߵ�ƽ�ͱ�Ϊ�͵�ƽ��ԭ���ǵ͵�ƽ�ͱ�Ϊ�ߵ�ƽ
		HAL_GPIO_TogglePin(GPIOG, GPIO_PIN_6);
		//ͨ��SysTick��ʱ1000��ʱ�䵥λ��Ҳ����һ����� (�b����*))
		HAL_Delay(1000);
    }
}
