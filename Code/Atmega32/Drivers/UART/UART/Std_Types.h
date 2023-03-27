#ifndef STD_TYPES_H
#define STD_TYPES_H

typedef unsigned char boolean;
typedef signed char sint8;
typedef unsigned char uint8;
typedef signed short sint16;
typedef unsigned short uint16;
typedef signed long sint32;
typedef unsigned long uint32;

#define TRUE 1
#define FALSE 0

typedef enum
{
	E_OK = 0,
	E_NOT_OK
} Std_ReturnType;

#endif /* STD_TYPES_H */