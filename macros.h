/*
 * macros.h
 *
 *  Created on: Jan 24, 2021
 *      Author: PC
 */

#ifndef MACROS_H_
#define MACROS_H_


#define setBit(port,pin) (port |=(1<<pin))
#define clearBit(port,pin) (port &= ~(1<<pin))
#define toggleBit(port,pin) (port ^= (1<<pin))
#define readBit(port,pin) (port&(1<<pin))








#endif /* MACROS_H_ */
