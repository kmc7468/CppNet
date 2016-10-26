#ifndef SYSTEM_EVENTHANDLER_H
#define SYSTEM_EVENTHANDLER_H

#include "../../Defines.h"

#include "Object.h"
#include "EventArgs.h"

#include <functional>

namespace CppNet
{
	namespace System
	{
		template<typename TEventArgs = EventArgs>
		using EventHandler = std::function<void(Object, TEventArgs)>;
	}
}

#endif