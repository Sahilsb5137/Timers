/*
 * tim.c
 *
 *  Created on: May 17, 2023
 *      Author: 14699
 */
#include "stm32f4xx.h"

#define TIM2EN	(1U<<0)
#define CR1_EN	(1U<<0)

void tim2_1Hz_init(void)
{
	//1.Enable the clock access to timer 2.
	RCC->APB1ENR |= TIM2EN;

	//2.Set the pre-scalar value
	TIM2->PSC = 1600-1; //16 000 000/1600 = 10 000.

	//3.Set auto-reload value
	TIM2->ARR = 10000-1; //10 000/10 000 = 1 or 1Hz

	//4.Clear counter
	TIM2->CNT =0;

	//5.Enable timer
	TIM2->CR1 = CR1_EN;

}

