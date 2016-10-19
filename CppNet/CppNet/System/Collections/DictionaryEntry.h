#ifndef SYSTEM_COLLECTIONS_DICTIONARYENTRY_H
#define SYSTEM_COLLECTIONS_DICTIONARYENTRY_H

#include "../Object.h"

namespace System
{
	namespace Collections
	{
		class DictionaryEntry : public Object
		{
		private:
			Object& key, value;

		public:
			DictionaryEntry(Object& key, Object& value);

			inline const Object& Key() const;
			inline Object& Key();

			inline const Object& Value() const;
			inline Object& Value();
		};
	}
}

#include "DictionaryEntry.inl"

#endif