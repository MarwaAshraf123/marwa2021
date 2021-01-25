

#include"stdlib.h"
#include"avr/io.h"
#include"avr/interrupt.h"
#include"avr/delay.h"
#include"config.h"
#include"SPI_driver.h"
#include "UART_drive.h"
#include"macros.h"

extern unsigned char received_spi;
//extern unsigned char a;

void SPI_init(){

	SPCR |=(1<<SPE) |(1<<DORD) |(1<<MSTR)|(1<<CPOL);
	DDRB |=(1<<4)|(1<<5)|(1<<7);
	DDRB &=~(1<<6);
    PORTB|=(1<<4);

//#if INTERRUPT == ENABLED
	SPCR |=(1<<SPIE);
	sei();
//#endif

}

void SPI_send(unsigned char data)
{
	PORTB &=~(1<<4);
	SPDR=data;
	_delay_ms(10);
	PORTB |=(1<<4);
}
ISR(SPI_STC_vect){
	received_spi=SPDR;
	UART_transmit(received_spi);
}
