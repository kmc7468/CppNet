#ifndef SYSTEM_EVENTARGS_H
#define SYSTEM_EVENTARGS_H

#include "../Defines.h"

#include "Object.h"

namespace System
{
	class EventArgs : public Object
	{
	public:
		static const EventArgs Empty;

	public:
		EventArgs() = default;
	};
}

#endif