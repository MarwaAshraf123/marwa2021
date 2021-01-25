/*
 * UART_drive.h
 *
 *  Created on: Jan 24, 2021
 *      Author: PC
 */

#ifndef UART_DRIVE_H_
#define UART_DRIVE_H_

void UART_init();

void UART_transmit(unsigned char x);

void UART_transmitString(unsigned char* s);



unsigned char recieved;





#endif /* UART_DRIVE_H_ */
