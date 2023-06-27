#include "stm32f4xx.h"

#define SYSTICK_LOAD_VAL	16000  //Default clock is 16Mhz
#define CTRL_EN			(1U<<0)
#define CTRL_CSR		(1U<<2)
#define CTRL_COUNTFLAG	(1U<<16)


void systickDelayMS(int delay)
{
	//1.Reload with number of clocks per ms
	SysTick->LOAD = SYSTICK_LOAD_VAL;

	//2.Clear Systick Current Value Register
	SysTick->VAL = 0;

	//3. Enable Systick and select internal clock source
	SysTick->CTRL = CTRL_EN | CTRL_CSR;

	for (int i=0; i<delay; i++)
	{
		//Wait until the CountFlag is set
		while (!(SysTick->CTRL & CTRL_COUNTFLAG)){}

	}
	SysTick->CTRL = 0;
}
