#ifndef SYSTEM_RUNTIME_REMOTING_CONTEXTS_ICONTEXTPROPERTY_H
#define SYSTEM_RUNTIME_REMOTING_CONTEXTS_ICONTEXTPROPERTY_H

#include "../../../../Defines.h"

#include "../../../String.h"
#include "../../../Boolean.h"
#include "Context.h"

namespace System
{
	namespace Runtime
	{
		namespace Remoting
		{
			namespace Contexts
			{
				class Context;

				struct IContextProperty
				{
					virtual const String& Name() const = 0;
					virtual Boolean IsNewContextOK(const Context& context) const = 0;
					virtual void Freeze(const Context& context) const = 0;
				};
			}
		}
	}
}

#endif