/*
 * common.h
 *
 * Created: 9/8/2018 9:53:08 PM
 *  Author: ahmed
 */ 


#ifndef COMMON_H_
#define COMMON_H_
#define _DEBUG
//#define SetBit(reg,pin) reg|=(1<<pin)
//#define ClrBit(reg,pin) reg&=~(1<<pin)
//#define ToggleBit(reg,pin) reg^=(1<<pin)
#define TRUE 1
#define  FALSE 0
#define NULL ((void *)0)
#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;
typedef signed short int s16;
typedef signed long int s32;
typedef float f32;

int32_t map(int32_t value, int32_t fromLow, int32_t fromHigh, int32_t toLow, int32_t toHigh);
int intToStr(int num, char* str, int start);
void floatToString(float num, char* str, int precision);
#endif /* COMMON_H_ */