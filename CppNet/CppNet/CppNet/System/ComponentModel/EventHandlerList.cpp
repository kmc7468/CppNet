#include "EventHandlerList.h"

namespace CppNet::System::ComponentModel
{
	EventHandlerList::ListEntry::ListEntry(const Object& key, void* handler, const ListEntry& next)
		: key(key), handler(handler), next(new ListEntry(next))
	{}

	EventHandlerList::ListEntry::ListEntry(ListEntry&& l)
		: key(std::move(l.key)), handler(std::move(l.handler)), next(new ListEntry(std::move(*(l.next))))
	{}

	EventHandlerList::ListEntry::ListEntry(const ListEntry& l)
		: key(l.key), handler(l.handler), next(new ListEntry(*(l.next)))
	{}

	EventHandlerList::EventHandlerList(std::unique_ptr<Component> parent)
	{
		this->parent = std::move(parent);
	}
}