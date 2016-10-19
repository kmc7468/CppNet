#ifndef SYSTEM_COLLECTIONS_IDICTIONARY_H
#define SYSTEM_COLLECTIONS_IDICTIONARY_H

#include "../../Utility.h"
#include "ICollection.h"
#include "../Object.h"
#include "IDictionaryEnumerator.h"

namespace System
{
	namespace Collections
	{
		interface _IDictionary
		{
			virtual std::unique_ptr<IDictionaryEnumerator> GetEnumerator() = 0;
		};

		interface IDictionary : public ICollection, public _IDictionary
		{
			virtual const Object& operator[](const Object& key) const = 0;
			virtual Object& operator[](const Object& key) = 0;
			virtual std::unique_ptr<ICollection> Keys() const = 0;
			virtual std::unique_ptr<ICollection> Values() const = 0;

			virtual Boolean Contrains(const Object& key) const = 0;
			virtual void Add(Object& key, Object& value) = 0;
			virtual void Clear() = 0;
			virtual Boolean Remove(const Object& key) = 0;

			virtual Boolean IsReadOnly() const = 0;
			virtual Boolean IsFixedSize() const = 0;

			virtual std::unique_ptr<IDictionaryEnumerator> _IDictionary::GetEnumerator() = 0;
		};
	}
}

#endif