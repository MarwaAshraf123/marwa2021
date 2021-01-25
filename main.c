/*
 * main.c
 *
 *  Created on: Jan 24, 2021
 *      Author: PC
 */
#include "avr/io.h"
#include "avr/interrupt.h"
#include "avr/delay.h"
#include "stdlib.h"
#include "string.h"
#include "UART_drive.h"
#include "UART_config.h"
#include "SPI_driver.h"
#include "config.h"
#include "macros.h"

extern unsigned char recieved; // @suppress("Unused variable declaration in file scope")

int main(){
	UART_init();
	SPI_init();

	UART_transmitString("Hello world");
	while (1){

	}

	return 0;
}


