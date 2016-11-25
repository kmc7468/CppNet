#include "ReadOnlyCollectionBase.h"

namespace CppNet::System::Collections
{
	Int32 ReadOnlyCollectionBase::Count() const
	{
		return 0; // FIXME
	}

	Boolean ReadOnlyCollectionBase::IsSynchronized() const
	{
		return true; // FIXME
	}

	const Object& ReadOnlyCollectionBase::SyncRoot() const
	{
		return Object(); // FIXME
	}

	std::unique_ptr<IEnumerator> ReadOnlyCollectionBase::GetEnumerator()
	{
		return nullptr; // FIXME
	}
}