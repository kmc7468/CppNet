#ifndef CPPNET_SYSTEM_ARRAY_HPP
#define CPPNET_SYSTEM_ARRAY_HPP

#include "Object.h"
#include "ICloneable.h"
#include "Collections/IList.hpp"

namespace CppNet::System
{
	class Array final : public Object, public ICloneable, public Collections::IList
	{

	};
}

#endif