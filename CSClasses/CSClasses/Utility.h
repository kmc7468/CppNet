#ifndef UTILITY_H
#define UTILITY_H

#include "System.h"

#include <type_traits>

#define interface struct
#define var auto

template <typename T, typename U>
constexpr System::Boolean is(U&& u)
{
	return std::is_base_of_v<T, U>;
}

#endif