#ifndef CPPNET_SYSTEM_ARRAY_HPP
#define CPPNET_SYSTEM_ARRAY_HPP

#include "../../Defines.h"
#include "../../Utility.h"

#include "Object.h"
#include "ICloneable.h"
#include "Collections/IList.hpp"
#include "Collections/IStructuralComparable.hpp"
#include "Collections/IStructuralEquatable.hpp"

#include "Int32.h"

namespace CppNet::System
{
	class Array : public Object, public ICloneable, public Collections::IList, public Collections::IStructuralComparable, public Collections::IStructuralEquatable
	{
		ABSTRACT_CLASS

	_internal:
		Array() = default;

	public:
		// TODO AsReadOnly

		template<typename T>
		static void Resize(Array& arr, Int32 newsize)
		{

		}
	};
}

#endif