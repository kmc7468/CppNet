#include "ReadOnlyCollectionBase.h"

namespace CppNet::System::Collections
{
	// FIXME

	Int32 ReadOnlyCollectionBase::Count() const
	{
		/*return list.Count();*/
		return 0;
	}

	Boolean ReadOnlyCollectionBase::IsSynchronized() const
	{
		/*return list.IsSynchronized();*/
		return false;
	}

	const Object& ReadOnlyCollectionBase::SyncRoot() const
	{
		/*return list.SyncRoot();*/
		return *(new Object);
	}

	std::unique_ptr<IEnumerator> ReadOnlyCollectionBase::GetEnumerator()
	{
		/*return list.GetEnumerator();*/
		return nullptr;
	}
}