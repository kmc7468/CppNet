#ifndef SYSTEM_RUNTIME_ISERIALIZABLE_H
#define SYSTEM_RUNTIME_ISERIALIZABLE_H

#include "../../../Utility.h"

namespace System
{
	namespace Runtime
	{
		namespace Serialization
		{
			interface ISerializable
			{
				virtual void GetObjectData(const SerializationInfo& info, const StreamingContext& context) const = 0;
			};
		}
	}
}

#endif