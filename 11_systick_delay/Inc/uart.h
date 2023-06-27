/*
 * uart.h
 *
 *  Created on: May 2, 2023
 *      Author: 14699
 */

#ifndef UART_H_
#define UART_H_

#include <stdint.h>
#include <stm32f4xx.h>

void uart2_tx_init(void);
char UART2_readChar(void);
void uart2_rxtx_init(void);


#endif /* UART_H_ */
