#ifndef UTILITY_H
#define UTILITY_H

#include "Boolean.h"

#include <type_traits>

#define interface struct
#define var auto

template <typename T, typename U>
inline System::Boolean is(U&& u)
{
	std::is_base_of<T, U> r;

	return r();
}

#endif