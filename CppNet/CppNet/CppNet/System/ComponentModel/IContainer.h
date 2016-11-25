#ifndef CPPNET_SYSTEM_COMPONENTMODEL_ICONTAINER_H
#define CPPNET_SYSTEM_COMPONENTMODEL_ICONTAINER_H

#include "../../../Defines.h"
#include "../../../Utility.h"

#include "../../Box.hpp"

#include "../IDisposable.h"
#include "../String.h"

#include "IComponent.h"
#include "ComponentCollection.h"

namespace CppNet::System::ComponentModel
{
	interface IContainer : public IDisposable
	{
		virtual void Add(Box<IContainer> component) = 0;
		virtual void Add(Box<IContainer> component, const String& name) = 0;
		virtual const ComponentCollection& Components() const = 0;
		virtual void Remove(Box<IContainer> component) = 0;
	};
}

#endif