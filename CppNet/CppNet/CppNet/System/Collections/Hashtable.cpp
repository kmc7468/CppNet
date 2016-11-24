#include "Hashtable.h"

#include "../ArgumentOutOfRangeException.hpp"

namespace CppNet::System::Collections
{
#pragma region HashHelpers
	
	const Int32 HashHelpers::HashCollisionThreshold = 100;
	Boolean HashHelpers::s_UseRandomizedStringHashing = true;
	const std::array<Int32, 72> HashHelpers::primes = {
		3, 7, 11, 17, 23, 29, 37, 47, 59, 71, 89, 107, 131, 163, 197, 239, 293, 353, 431, 521, 631, 761, 919,
		1103, 1327, 1597, 1931, 2333, 2801, 3371, 4049, 4861, 5839, 7013, 8419, 10103, 12143, 14591,
		17519, 21023, 25229, 30293, 36353, 43627, 52361, 62851, 75431, 90523, 108631, 130363, 156437,
		187751, 225307, 270371, 324449, 389357, 467237, 560689, 672827, 807403, 968897, 1162687, 1395263,
		1674319, 2009191, 2411033, 2893249, 3471899, 4166287, 4999559, 5999471, 7199369 };

#pragma endregion

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
		if (capacity < 0)
			throw ArgumentOutOfRangeException(nameof(capacity));
		if (!(loadFactor >= 0.1f && loadFactor <= 1.0f))
			throw ArgumentOutOfRangeException(nameof(loadFactor));

		this->loadFactor = 0.72f * loadFactor;

		Double rawsize = capacity / this->loadFactor;
		if (rawsize > MaxValue<Int32>())
			throw ArgumentException();

		Int32 hashsize = (rawsize > InitialSize) ? /*HashHelpers.GetPrime((int)rawsize)*/3 : InitialSize;
		buckets = new bucket[hashsize];

		loadsize = (Int32)(this->loadFactor * hashsize);
		isWriterInProgress = false;
	}

	Hashtable::Hashtable(Int32 capacity, Single loadFactor, IHashCodeProvider* hcp, IComparer* comparer)
		: Hashtable(capacity, loadFactor)
	{
		if (!hcp && !comparer)
		{
			_keycomparer = nullptr;
		}
		else
		{
			_keycomparer = new CompatibleComparer(comparer, hcp);
		}
	}

	Hashtable::Hashtable(Int32 capacity, Single loadFactor, IEqualityComparer* equalityComparer)
		: Hashtable(capacity, loadFactor)
	{
		_keycomparer = equalityComparer;
	}
}