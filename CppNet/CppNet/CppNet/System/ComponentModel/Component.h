#ifndef CPPNET_SYSTEM_COMPONENTMODEL_COMPONENT_H
#define CPPNET_SYSTEM_COMPONENTMODEL_COMPONENT_H

#include "IComponent.h"

namespace CppNet::System::ComponentModel
{
	class Component : public IComponent
	{
	private:
		static const Object EventDisposed;

	private:
		ISite* site = nullptr;
	};
}

#endif