#ifndef CPPNET_MAXVALUE_HPP
#define CPPNET_MAXVALUE_HPP

#include <limits>

namespace CppNet
{
	template<typename T>
	inline static constexpr T MaxValue()
	{
		return std::numeric_limits<T>::max();
	}
}

#endif