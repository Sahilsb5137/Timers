//STM32F411 Nucleo Board

//PA2 -> USART2 Tx
//PA3 -> USART2 Rx
//PA2 & PA3 -> AF07 (GPIO Alternate Function)
#include <stdio.h>
#include <stdint.h>
#include <stm32f4xx.h>
#include <uart.h>
#include <adc.h>

#include "systick.h"

#define GPIOAEN		(1U<<0)
#define PIN5		(1U<<5)
#define LED			PIN5



int main(void)
{
	//1.Enable Clock Access to GPIOA
	RCC->AHB1ENR |= GPIOAEN;

	//2.Set PA5 as output Pin
	GPIOA->MODER |= (1U<<10);
	GPIOA->MODER &= ~(1U<<11);

	uart2_tx_init();

	while(1)
	{

		printf("A second just passed!! \n\r");

		//Toggle the LED
		GPIOA->ODR ^= LED;

		//Call the function and pass the delay
		systickDelayMS(1000);
	}

}

