#ifndef SYSTEM_H
#define SYSTEM_H

typedef unsigned char Byte;
typedef signed char SByte;
typedef unsigned short UInt16;
typedef unsigned int UInt32;
typedef unsigned long long UInt64;
typedef short Int16;
typedef int Int32;
typedef long long Int64;
typedef double Double;
typedef float Single;
typedef bool Boolean

#include "Object.h"
#include "Console.h"
#include "Math.h"

System::Console Console;
System::Math Math;

#endif