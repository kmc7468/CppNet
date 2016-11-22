#include "Hashtable.h"

namespace CppNet::System::Collections
{
	const Int32 Hashtable::HashPrime = 101;
	const Int32 Hashtable::InitialSize = 3;
	const String Hashtable::LoadFactorName = "LoadFactor";
	const String Hashtable::VersionName = "Version";
	const String Hashtable::ComparerName = "Comparer";
	const String Hashtable::HashCodeProviderName = "HashCodeProvider";
	const String Hashtable::HashSizeName = "HashSize";
	const String Hashtable::KeysName = "Keys";
	const String Hashtable::ValuesName = "Values";
	const String Hashtable::KeyComparerName = "KeyComparer";

	const Box<IHashCodeProvider> Hashtable::GetHcp() const
	{
		if (_keycomparer == nullptr)
			return nullptr;
		else if (is<CompatibleComparer>(*_keycomparer))
			return ((CompatibleComparer*)_keycomparer)->HashCodeProvider();

		throw ArgumentException();
	}

	void Hashtable::SetHcp(Box<IHashCodeProvider> val)
	{
		if (_keycomparer == nullptr)
			_keycomparer = new CompatibleComparer(nullptr, val.Data());
		else if (is<CompatibleComparer>(*(val.Data())))
		{
			CompatibleComparer* keyCom = (CompatibleComparer*)_keycomparer;
			_keycomparer = new CompatibleComparer(keyCom->comparer, val.Data());
			delete keyCom;
		}

		throw ArgumentException();
	}

	const Box<IComparer> Hashtable::GetComparer() const
	{
		if (_keycomparer == nullptr)
			return nullptr;
		else if (is<CompatibleComparer>(*_keycomparer))
			return ((CompatibleComparer*)_keycomparer)->comparer;

		throw ArgumentException();
	}

	void Hashtable::SetComparer(Box<IComparer> val)
	{
		if (_keycomparer == nullptr)
			_keycomparer = new CompatibleComparer(val.Data(), nullptr);
		else if (is<CompatibleComparer>(*_keycomparer))
		{
			CompatibleComparer* keyCom = (CompatibleComparer*)_keycomparer;
			_keycomparer = new CompatibleComparer(val.Data(), keyCom->hcp);
			delete keyCom;
		}

		throw ArgumentException();
	}

	const Box<IEqualityComparer> Hashtable::EqualityComparer() const
	{
		return make_box(_keycomparer, 2);
	}

	Hashtable::Hashtable(Boolean trash) {}

	Hashtable::Hashtable()
		: Hashtable(0, 1.0f)
	{}

	Hashtable::Hashtable(Int32 capacity)
		: Hashtable(capacity, 1.0f)
	{}

	Hashtable::Hashtable(Int32 capacity, Single loadFactor)
	{
		// TODO
	}
}