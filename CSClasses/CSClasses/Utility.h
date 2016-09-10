#ifndef UTILITY_H
#define UTILITY_H

#include "System.h"

#define interface struct
#define var auto

template <typename T, typename U>
constexpr System::Boolean is(U u)
{
	return is_base_of<T, U>::value;
}

#endif