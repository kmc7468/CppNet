#ifndef CPPNET_AS_HPP
#define CPPNET_AS_HPP

namespace CppNet
{
	template <typename T, typename U>
	inline static T as(U& u)
	{
		return dynamic_cast<T>(u);
	}
}

#endif