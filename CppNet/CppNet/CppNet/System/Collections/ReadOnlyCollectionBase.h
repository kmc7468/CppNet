#ifndef CPPNET_SYSTEM_COLLECTIONS_READONLYCOLLECTIONBASE_H
#define CPPNET_SYSTEM_COLLECTIONS_READONLYCOLLECTIONBASE_H

#include "../Int32.h"

#include "ICollection.h"
#include "ArrayList.h"

namespace CppNet::System::Collections
{
	class ReadOnlyCollectionBase : public ICollection
	{
	/*protected:
		ArrayList list;*/

	public:
		virtual Int32 Count() const;
		Boolean IsSynchronized() const override;
		const Object& SyncRoot() const override;

		// TODO CopyTo

		std::unique_ptr<IEnumerator> GetEnumerator() override;
	};
}

#endif