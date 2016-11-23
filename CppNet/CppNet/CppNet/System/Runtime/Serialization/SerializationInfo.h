#ifndef SYSTEM_RUNTIME_SERIALIZATION_SERIALIZATIONINFO_H
#define SYSTEM_RUNTIME_SERIALIZATION_SERIALIZATIONINFO_H

#include "../../../../Defines.h"
#include "../../../../Utility.h"

#include "../../Object.h"
#include "../../Int32.h"
#include "../../String.h"
#include "../../Type.h"
#include "../../ArgumentNullException.hpp"

#include "../../Collections/Generic/Dictionary.h"

#include "IFormatterConverter.hpp"

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
					Type* m_types = nullptr;

				private:
					Collections::Generic::Dictionary<String, Int32> m_nameToIndex;

				_internal:
					Int32 m_currMember;
					IFormatterConverter* m_converter = nullptr;

				private:
					String m_fullTypeName;
					Type* objectType = nullptr;
					Boolean isFullTypeNameSetExplicit;
					Boolean requireSameTokenInPartialTrust;


				public:
					SerializationInfo(Type* type, IFormatterConverter* converter);
					SerializationInfo(Type* type, IFormatterConverter* converter, Boolean requireSameTokenInPartialTrust);

					String GetFullTypeName() const;
					void SetFullTypeName(const String& value);

					void SetType(Type* type);
					
					// TODO
				};
			}
		}
	}
}

#endif