#include "Component.h"

namespace CppNet::System::ComponentModel
{
	const Object* Component::EventDisposed = new Object;

	Component::~Component()
	{
		Dispose(false);
	}

	Boolean Component::CanRaiseEvents() const
	{
		return true;
	}

	void Component::Dispose()
	{
		Dispose(true);
	}

	void Component::Dispose(Boolean disposing)
	{
		if (disposing)
		{
			// TODO
		}
	}

	const ISite& Component::Site() const
	{
		return *site;
	}

	ISite& Component::Site()
	{
		return *site;
	}
}