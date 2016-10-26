#ifndef SYSTEM_RUNTIME_REMOTING_MESSAGING_IMESSAGE_H
#define SYSTEM_RUNTIME_REMOTING_MESSAGING_IMESSAGE_H

#include "../../../../../Utility.h"

#include "../../../Collections/IDictionary.h"

namespace CppNet
{
	namespace System
	{
		namespace Runtime
		{
			namespace Remoting
			{
				namespace Messaging
				{
					interface IMessage
					{
						virtual const Collections::IDictionary& Properties() const = 0;
					};
				}
			}
		}
	}
}

#endif