#ifndef CPPNET_SYSTEM_RUNTIME_SERIALIZATION_IDESERIALIZATIONCALLBACK_H
#define CPPNET_SYSTEM_RUNTIME_SERIALIZATION_IDESERIALIZATIONCALLBACK_H

#include "../../../../Utility.h"

#include "../../Object.h"

namespace CppNet
{
	namespace System
	{
		namespace Runtime
		{
			namespace Serialization
			{
				interface IDeserializationCallback
				{
					virtual void OnDeserialization(const Object& sender) = 0;
				};
			}
		}
	}
}

#endif