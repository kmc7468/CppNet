#ifndef UTILITY_H
#define UTILITY_H

#include "Boolean.h"

#include <type_traits>

#define interface struct
#define var auto

#define MAIN_END system("pause");return 0;

#define ref(type) type &
#define out(type) std::unique_ptr<type>

template <typename T, typename U>
inline System::Boolean is(U&& u)
{
	std::is_base_of<T, U> r;

	return r();
}

template <typename T, typename U>
inline T as(U&& u)
{
	return dynamic_cast<T>(u);
}

#endif