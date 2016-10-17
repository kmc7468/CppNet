#ifndef SYSTEM_COLLECTIONS_GENERIC_IDICTIONARY_H
#define SYSTEM_COLLECTIONS_GENERIC_IDICTIONARY_H

#include "../../../Utility.h"
#include "../../KeyValuePair.h"

namespace System
{
	namespace Collections
	{
		namespace Generic
		{
			template<typename TKey, typename TValue>
			interface IDictionary : public ICollection<KeyValuePair<TKey, TValue>>
			{
				virtual TValue& operator[](const TKey& key) const = 0;
				virtual ICollection<TKey> Keys() const = 0;
				virtual ICollection<TValue> Values() const = 0;

				virtual Boolean ContrainsKey(const TKey& key) const = 0;
				virtual void Add(TKey& key, TKey& value) = 0;
				virtual Boolean Remove(const TKey& key) = 0;
				virtual Boolean TryGetValue(const TKey& key, TValue& result_value) const = 0;
			};
		}
	}	
}

#endif