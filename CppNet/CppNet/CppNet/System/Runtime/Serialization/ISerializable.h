#ifndef SYSTEM_RUNTIME_SERIALIZATION_ISERIALIZABLE_H
#define SYSTEM_RUNTIME_SERIALIZATION_ISERIALIZABLE_H

#include "../../../../Defines.h"

#include "../../../../Utility.h"

#include "SerializationInfo.h"
#include "StreamingContext.h"

namespace CppNet
{
	namespace System
	{
		namespace Runtime
		{
			namespace Serialization
			{
				class SerializationInfo;
				class StreamingContext;

				interface ISerializable
				{
					virtual void GetObjectData(const SerializationInfo& info, const StreamingContext& context) const = 0;
				};
			}
		}
	}
}

#endif