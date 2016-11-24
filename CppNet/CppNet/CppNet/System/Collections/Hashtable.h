#ifndef SYSTEM_COLLECTIONS_HASHTABLE_H
#define SYSTEM_COLLECTIONS_HASHTABLE_H

#include "../../../Defines.h"
#include "../../../Utility.h"
#include "../../Box.hpp"

#include "../Object.h"
#include "../ICloneable.h"
#include "../Int32.h"
#include "../UInt32_64.h"
#include "../Single.h"
#include "../ArgumentException.h"

#include "../Runtime/Serialization/ISerializable.h"
#include "../Runtime/Serialization/IDeserializationCallback.h"

#include "ICollection.h"
#include "IEqualityComparer.hpp"
#include "CompatibleComparer.hpp"

#include <array>

namespace CppNet
{
	namespace System
	{
		namespace Collections
		{
			class Hashtable;

			class HashHelpers
			{
				friend class Hashtable;

			_internal:
				static const Int32 HashCollisionThreshold;
				static Boolean s_UseRandomizedStringHashing;
				static const std::array<Int32, 72> primes;
			};

			class Hashtable : public Object/*, public Runtime::Serialization::ISerializable, 
				public Runtime::Serialization::IDeserializationCallback, public ICloneable*/
			{
			private:
				static const Int32 HashPrime;
				static const Int32 InitialSize;
				static const String LoadFactorName;
				static const String VersionName;
				static const String ComparerName;
				static const String HashCodeProviderName;
				static const String HashSizeName;
				static const String KeysName;
				static const String ValuesName;
				static const String KeyComparerName;

				class bucket
				{
				public:
					Object Key;
					Object Value;
					Int32 hash_call;
				};

			private:
				bucket* buckets = nullptr;
				
				Int32 count;
				Int32 loadsize;
				Single loadFactor;
				volatile Int32 version;
				volatile Boolean isWriterInProgress;

				ICollection* keys = nullptr;
				ICollection* values = nullptr;

				IEqualityComparer* _keycomparer;
				Object _syncRoot;

			protected:
				const Box<IHashCodeProvider> GetHcp() const;
				void SetHcp(Box<IHashCodeProvider> val);

				const Box<IComparer> GetComparer() const;
				void SetComparer(Box<IComparer> val);

				const Box<IEqualityComparer> EqualityComparer() const;

			_internal:
				Hashtable(Boolean trash);

			public:
				Hashtable();
				Hashtable(Int32 capacity);
				Hashtable(Int32 capacity, Single loadFactor);
				Hashtable(Int32 capacity, Single loadFactor, IHashCodeProvider* hcp, IComparer* comparer);
				Hashtable(Int32 capacity, Single loadFactor, IEqualityComparer* equalityComparer);
			};
		}
	}
}

#endif