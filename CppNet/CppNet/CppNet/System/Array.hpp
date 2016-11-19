#ifndef CPPNET_SYSTEM_ARRAY_HPP
#define CPPNET_SYSTEM_ARRAY_HPP

#include "../../Defines.h"
#include "../../Utility.h"

#include "Object.h"
#include "ICloneable.h"
#include "Collections/IList.hpp"
#include "Collections/IStructuralComparable.hpp"
#include "Collections/IStructuralEquatable.hpp"

namespace CppNet::System
{
	class Array final : public Object, public ICloneable, public Collections::IList, public Collections::IStructuralComparable, public Collections::IStructuralEquatable
	{
	_internal:
		Array() = default;

	public:
		// TODO AsReadOnly
	};
}

#endif