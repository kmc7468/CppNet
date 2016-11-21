#ifndef CPPNET_SYSTEM_COMPONENTMODEL_COMPONENT_H
#define CPPNET_SYSTEM_COMPONENTMODEL_COMPONENT_H

#include "../../../Defines.h"
#include "../../../Utility.h"

#include "../../Box.hpp"
#include "../EventHandler.h"

#include "IComponent.h"

namespace CppNet::System::ComponentModel
{
	class Component : public IComponent
	{
	private:
		static const Object* EventDisposed;

	private:
		ISite* site = nullptr;

	public:
		~Component();

		const ISite& Site() const override;
		ISite& Site() override;

	protected:
		virtual Boolean CanRaiseEvents() const;
		
		void Dispose() override;

	protected:
		virtual void Dispose(Boolean disposing);
	};
}

#endif