#ifndef CPPNET_MINVALUE_HPP
#define CPPNET_MINVALUE_HPP

#include <limits>

namespace CppNet
{
	template<typename T>
	inline static constexpr T MinValue()
	{
		return std::numeric_limits<T>::min();
	}

	template<typename T>
	inline static T MinValueR()
	{
		return std::numeric_limits<T>::min();
	}
}

#endif