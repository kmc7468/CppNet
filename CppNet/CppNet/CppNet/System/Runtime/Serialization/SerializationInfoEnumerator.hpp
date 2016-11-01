#ifndef CPPNET_SYSTEM_RUNTIME_SERIALIZATION_SERIALIZATIONINFOENUMERATOR_HPP
#define CPPNET_SYSTEM_RUNTIME_SERIALIZATION_SERIALIZATIONINFOENUMERATOR_HPP

#include "../../Object.h"

#include "../../Collections/IEnumerator.h"

namespace CppNet::System::Runtime::Serialization
{
	class SerializationInfoEnumerator final : public Object, public Collections::IEnumerator
	{
	private:
		String* members = nullptr;
		Object* data = nullptr;
		Type* types = nullptr;
		Int32 numItems;
		Int32 currItem;
		Boolean current;
	
	private:
		SerializationInfoEnumerator(String* members, Object* info, Type* types, Int32 numItems)
			: numItems(numItems)
		{
			
		}
	};
}

#endif