#ifndef SYSTEM_RUNTIME_SERIALIZATION_SERIALIZATIONINFO_H
#define SYSTEM_RUNTIME_SERIALIZATION_SERIALIZATIONINFO_H

#include "../../../../Defines.h"
#include "../../../../Utility.h"

#include "../../Object.h"
#include "../../Int32.h"
#include "../../String.h"

#include "../../Collections/Generic/Dictionary.h"

#include <type_traits>

namespace CppNet
{
	namespace System
	{
		namespace Runtime
		{
			namespace Serialization
			{
				class SerializationInfo final : public Object
				{
				private:
					static const Int32 defaultSize;

				_internal:
					String* m_members = nullptr;
					Object* m_data = nullptr;
					std::type_info* m_types = nullptr;

				private:
					Collections::Generic::Dictionary<String, Int32> m_nameToIndex;

				_internal:
					Int32 m_currMember;

				};
			}
		}
	}
}

#endif