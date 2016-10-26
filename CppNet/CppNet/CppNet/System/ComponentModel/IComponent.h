#ifndef SYSTEM_COMPONENTMODEL_ICOMPONENT_H
#define SYSTEM_COMPONENTMODEL_ICOMPONENT_H

#include "../../../Defines.h"

#include "../../../Utility.h"
#include "../IDisposable.h"
#include "ISite.h"
#include "../EventHandler.h"

#include <functional>
#include <algorithm>
#include <type_traits>

namespace CppNet
{
	namespace System
	{
		namespace ComponentModel
		{
			interface IComponent : public IDisposable
			{
				virtual const ISite& Site() const = 0;
				virtual ISite& Site() = 0;

				evnt(EventHandler<>, Disposed);
			};
		}
	}
}

#endif