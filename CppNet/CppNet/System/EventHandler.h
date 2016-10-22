#ifndef SYSTEM_EVENTHANDLER_H
#define SYSTEM_EVENTHANDLER_H

#include "Object.h"
#include "EventArgs.h"

#include <functional>

namespace System
{
	template<typename TEventArgs = EventArgs>
	using EventHandler = std::function<void(Object, TEventArgs)>;
}

#endif