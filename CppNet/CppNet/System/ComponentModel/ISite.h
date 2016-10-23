#ifndef SYSTEM_COMPONENTMODL_ISITE_H
#define SYSTEM_COMPONENTMODL_ISITE_H

#include "../../Defines.h"

#include "../../Utility.h"
#include "../IServiceProvider.h"
#include "../String.h"

namespace System
{
	namespace ComponentModel
	{
		interface ISite : public IServiceProvider
		{
			const String& Name() const;
			String& Name();

			Boolean DesignMode() const;

			// TODO
		};
	}
}

#endif