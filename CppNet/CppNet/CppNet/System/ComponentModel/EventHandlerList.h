#ifndef CPPNET_SYSTEM_COMPONENTMODEL_EVENTHANDLERLIST_H
#define CPPNET_SYSTEM_COMPONENTMODEL_EVENTHANDLERLIST_H

#include <memory>

#include "../IDisposable.h"
#include "../Object.h"

#include "Component.h"

namespace CppNet::System::ComponentModel
{
	class EventHandlerList final : public IDisposable
	{
	private:
		class ListEntry
		{
		public:
			ListEntry(const Object& key, void* handler, const ListEntry& next);
			ListEntry(ListEntry&& l);
			ListEntry(const ListEntry& l);

			ListEntry* next = nullptr;
			Object key;
			void* handler = nullptr;
		};

	private:
		ListEntry* head = nullptr;
		std::unique_ptr<Component> parent;

	public:
		EventHandlerList() = default;
		~EventHandlerList() = default;

	private:
		EventHandlerList(std::unique_ptr<Component> parent);
	};
}

#endif