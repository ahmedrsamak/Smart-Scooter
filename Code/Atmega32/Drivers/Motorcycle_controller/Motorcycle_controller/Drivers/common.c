/*
 * common.c
 *
 * Created: 3/28/2023 2:36:52 AM
 *  Author: ahmed
 */ 
#include "common.h"
int32_t map(int32_t value, int32_t fromLow, int32_t fromHigh, int32_t toLow, int32_t toHigh)
{
	// Determine the range of the input value
	int32_t fromRange = fromHigh - fromLow;
	
	// Determine the range of the output value
	int32_t toRange = toHigh - toLow;
	
	// Scale the input value to the output range
	int32_t output = ((value - fromLow) * toRange) / fromRange + toLow;
	
	// Return the mapped value
	return output;
}

void reverse(char* str, int len) {
	int i = 0, j = len - 1;
	while (i < j) {
		char temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}

int intToStr(int num, char* str, int start) {
	int i = 0;
	do {
		str[start + i] = (num % 10) + '0';
		num /= 10;
		i++;
	} while (num != 0);
	reverse(str + start, i);
	return i;
}

void floatToString(float num, char* str, int precision) {
	int ipart = (int)num;
	float fpart = num - (float)ipart;

	int i = intToStr(ipart, str, 0);

	if (precision != 0) {
		str[i] = '.';
		fpart = fpart * 10;
		while (precision > 0) {
			int digit = (int)fpart;
			str[i + 1] = digit + '0';
			fpart = fpart - (float)digit;
			fpart = fpart * 10;
			i++;
			precision--;
		}
	}
	str[i + 1] = '\0';
}