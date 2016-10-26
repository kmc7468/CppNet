#ifndef SYSTEM_RUNTIME_REMOTING_MESSAGING_IMESSAGESINK_H
#define SYSTEM_RUNTIME_REMOTING_MESSAGING_IMESSAGESINK_H

#include "../../../../../Utility.h"
#include "IMessage.h"
#include "IMessageCtrl.h"

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
					interface IMessageSink
					{
						virtual std::unique_ptr<IMessage> SyncProcessMessage(std::unique_ptr<IMessage> msg) = 0;
						virtual std::unique_ptr<IMessageCtrl> AsyncProcessMessage(std::unique_ptr<IMessage> msg, std::unique_ptr<IMessageSink> replySink) = 0;
						virtual std::unique_ptr<IMessageSink> NextSink();
					};
				}
			}
		}
	}
}

#endif