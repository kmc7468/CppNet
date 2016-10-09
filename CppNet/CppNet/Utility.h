#ifndef UTILITY_H
#define UTILITY_H

#include "Defines.h"

#include "System/Boolean.h"

#include <type_traits>

#define interface struct
#define var auto

#define nameof(x) String(#x);
#define typeof(x) typeid(x)

#define MAIN_END system("pause");return 0;

#define dref(t) std::remove_reference<##t>::type
#define dcst(from, to_type) (*const_cast<to_type##*>(&##from))

#define _is(from_type, to_type) is<to_type, from_type>()
#define __is(from, to_type) is<to_type>(from)

#define _as(from, to_type) as<to_type>(from)

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