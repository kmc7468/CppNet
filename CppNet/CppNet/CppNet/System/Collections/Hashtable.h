#ifndef SYSTEM_COLLECTIONS_HASHTABLE_H
#define SYSTEM_COLLECTIONS_HASHTABLE_H

#include "../../../Defines.h"

#include "../Object.h"
#include "../ICloneable.h"

#include "../Runtime/Serialization/ISerializable.h"
#include "../Runtime/Serialization/IDeserializationCallback.h"

namespace CppNet
{
	namespace System
	{
		namespace Collections
		{
			class Hashtable : public Object/*, public Runtime::Serialization::ISerializable, 
				public Runtime::Serialization::IDeserializationCallback, public ICloneable*/
			{

			};
		}
	}
}

#endif