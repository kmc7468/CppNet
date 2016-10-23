#ifndef SYSTEM_RUNTIME_REMOTING_MESSAGING_IMESSAGECTRL_H
#define SYSTEM_RUNTIME_REMOTING_MESSAGING_IMESSAGECTRL_H

#include "../../../../Utility.h"
#include "IMessage.h"

namespace System
{
	namespace Runtime
	{
		namespace Remoting
		{
			namespace Messaging
			{
				interface IMessageCtrl
				{
					virtual void Cancel(Int32 msToCancel) = 0;
				};
			}
		}
	}
}

#endif