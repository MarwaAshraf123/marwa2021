/*
 * UART_drive.c
 *
 *  Created on: Jan 24, 2021
 *      Author: PC
 */

#include "avr/io.h"
#include "avr/interrupt.h"
#include "stdlib.h"
#include "string.h"
#include "UART_drive.h"
#include "config.h"
#include "SPI_driver.h"
#include "macros.h"


extern unsigned char recieved;

void UART_init(){

	UCSRB |= (1<<TXEN) | (1<<RXEN);
	UBRRL = 103;
	UBRRH=(103>>8);

	UCSRC |= (1<<URSEL) | (1<<UCSZ1) | (1<<UCSZ0);
	UCSRC &= ~(1<<URSEL);


	//clearBit(UCSRC,UMSEL);
	//clearBit(UCSRC,UPM1);
	//clearBit(UCSRC,UPM0);
	//clearBit(UCSRC,USBS);
	//clearBit(UCSRB,UCSZ2);

//#if Interrupt == ENABLED

	sei();
//#endif
}

void UART_transmit(unsigned char x){

	while(((1<<UDRE)&(UCSRA))==0);
	UDR = x;

}

void UART_transmitString(unsigned char* s){

	int i=0;
	for(i=0;i<strlen(s);i++){
		//UART_transmit(s[i]);
		while(((1<<UDRE)&(UCSRA))==0)
			UDR=s[i];
	}
}


ISR(USART_RXC_vect){

	recieved = UDR;
	UART_transmitString(" It's sending:");
	//UART_transmit(recieved);
	SPI_send(recieved);
}

ISR(USART_TXC_vect){

}



