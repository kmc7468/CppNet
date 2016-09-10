#ifndef UTILITY_H
#define UTILITY_H

#include "System.h"

#define interface struct
#define var auto

template<typename T, typename U>
System::Boolean& is(U u)
{
	// FIXME: ERROR
	return (bool) (dynamic_cast<T*>(u) != nullptr);
}

#endif