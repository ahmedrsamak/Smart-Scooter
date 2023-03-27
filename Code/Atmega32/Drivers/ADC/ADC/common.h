/*
 * common.h
 *
 * Created: 3/25/2023 4:01:51 PM
 *  Author: ahmed
 */ 


#ifndef COMMON_H_
#define COMMON_H_

#define Set_Bit(REG,BIT) (REG |= (1<<BIT))
#define Clear_Bit(REG,BIT) (REG &= (~(1<<BIT)))
#define Toggle_Bit(REG,BIT) (REG ^= (1<<BIT))
#define ROR(REG,NUM) (REG = ((REG >> NUM) | (REG << (8-NUM))))
#define ROL(REG,NUM) (REG = ((REG << NUM) | (REG >> (8-NUM))))
#define Bit_Is_Set(REG,BIT) (REG & (1<<BIT))
#define Bit_Is_Clear(REG,BIT) (!(REG & (1<<BIT)))

#define NULL ((void*)0)
#define F_CPU 8000000UL


#include <avr/io.h>
#include <stdint.h>
#include <stdlib.h>
#include "util/delay.h"


#endif /* COMMON_H_ */

