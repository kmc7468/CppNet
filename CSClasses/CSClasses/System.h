
#ifndef SYSTEM_H

#define SYSTEM_H

<<<<<<< HEAD
using Boolean = bool;
using Char = wchar_t;

using Byte = unsigned char;
using SByte = signed char;

using Int16 = short;
using Int32 = int;
using Int64 = long long;

using UInt16 = unsigned short;
using UInt32 = unsigned int;
using UInt64 = unsigned long long;

using Single = float;
using Double = double;
=======
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
typedef bool Boolean;

#include "Object.h"
#include "Console.h"
#include "Math.h"

System::Console Console;
System::Math Math;

#endif