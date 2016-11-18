#ifndef CPPNET_IS_HPP
#define CPPNET_IS_HPP

#include "System/Boolean.h"

namespace CppNet
{
	template<typename T, typename U>
	inline static System::Boolean is(U& u)
	{
		if (T* p = dynamic_cast<T*>(&u))
			return true;
		else
			return false;
	}
}

#endif