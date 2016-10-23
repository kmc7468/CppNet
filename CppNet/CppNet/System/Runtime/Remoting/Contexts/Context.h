#ifndef SYSTEM_RUNTIME_REMOTING_CONTEXTS_CONTEXT_H
#define SYSTEM_RUNTIME_REMOTING_CONTEXTS_CONTEXT_H

#include "../../../../Defines.h"

#include "../../../Object.h"
#include "../../../Int32.h"
#include "IContextProperty.h"
#include "../Messaging/IMessageSink.h"

namespace System
{
	namespace Runtime
	{
		namespace Remoting
		{
			namespace Contexts
			{
				class Context : public Object
				{
				private:
					static const Int32 CTX_DEFAULT_CONTEXT;
					static const Int32 CTX_FROZEN;
					static const Int32 CTX_THREADPOOL_AWARE;
					static const Int32 GROW_BY;
					static const Int32 STATICS_BUCKET_SIZE;

				private:
					IContextProperty* _ctxProps = nullptr;
					std::unique_ptr<Messaging::IMessageSink> _serverContextChain = nullptr;
					std::unique_ptr<Messaging::IMessageSink> _clientContextChain = nullptr;
				};
			}
		}
	}
}

#endif