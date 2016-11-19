#ifndef CPPNET_SYSTEM_COLLECTIONS_OBJECTMODEL_READONLYCOLLECTION_HPP
#define CPPNET_SYSTEM_COLLECTIONS_OBJECTMODEL_READONLYCOLLECTION_HPP

#include <memory>

#include "../IList.hpp"
#include "../Generic/IList.h"
#include "../Generic/IReadOnlyList.hpp"
#include "../../Object.h"

namespace CppNet::System::Collections::ObjectModel
{
	template<typename T>
	class ReadOnlyCollection : public IList, public Generic::IList<T>, public Generic::IReadOnlyList<T>
	{
	private:
		std::unique_ptr<Generic::IList<T>> list;
		Object* _syncRoot = nullptr;

	public:
		ReadOnlyCollection(std::unique_ptr<Generic::IList<T>> list)
		{
			if (list == nullptr)
			{

			}

			this->list = std::move(list);
		}
	};
}

#endif