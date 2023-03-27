/*
 * general_purpose.c
 *
 * Created: 3/26/2023 10:30:57 PM
 *  Author: ahmed
 */
#include "general_purpose.h" 
int map(int value, int fromLow, int fromHigh, int toLow, int toHigh) {
	// Check if the value is within the input range
	if (value < fromLow) {
		value = fromLow;
	}
	if (value > fromHigh) {
		value = fromHigh;
	}
	
	// Map the value to the output range
	int output = ((value - fromLow) * (toHigh - toLow)) / (fromHigh - fromLow) + toLow;
	
	return output;
}