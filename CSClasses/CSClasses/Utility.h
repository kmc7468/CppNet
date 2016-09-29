#ifndef UTILITY_H
#define UTILITY_H

#include "Boolean.h"

#include <type_traits>

#define interface struct
#define var auto

#define MAIN_END system("pause");return 0;

template <typename T, typename U>
inline System::Boolean is(U&& u)
{
	std::is_base_of<U, T> r;

	System::Boolean result = r();

	if (result) return result;
	else
	{
		std::is_base_of<T, U> r2;

		return r2();
	}
}

template<typename T, typename U>
inline System::Boolean is()
{
	std::is_base_of<U, T> r;

	System::Boolean result = r();

	if (result) return result;
	else
	{
		std::is_base_of<T, U> r2;

		return r2();
	}
}

template <typename T, typename U>
inline T as(U&& u)
{
	return dynamic_cast<T>(u);
}

#endif