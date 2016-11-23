#ifndef CPPNET_SYSTEM_RUNTIME_SERIALIZATION_IFORMATTERCONVERTER_HPP
#define CPPNET_SYSTEM_RUNTIME_SERIALIZATION_IFORMATTERCONVERTER_HPP

#include "../../../../Defines.h"
#include "../../../../Utility.h"

#include <type_traits>

#include "../../Object.h"
#include "../../Type.h"

namespace CppNet::System::Runtime::Serialization
{
	interface IFormatterConverter
	{
		virtual Object* Convert(Object& value, Type& type) = 0;
	};
}

#endif