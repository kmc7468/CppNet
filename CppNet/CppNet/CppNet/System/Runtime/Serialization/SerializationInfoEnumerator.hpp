#ifndef CPPNET_SYSTEM_RUNTIME_SERIALIZATION_SERIALIZATIONINFOENUMERATOR_HPP
#define CPPNET_SYSTEM_RUNTIME_SERIALIZATION_SERIALIZATIONINFOENUMERATOR_HPP

#include "../../Object.h"

#include "../../Collections/IEnumerator.h"

namespace CppNet::System::Runtime::Serialization
{
	class SerializationInfoEnumerator final : public Object, public Collections::IEnumerator
	{

	};
}

#endif