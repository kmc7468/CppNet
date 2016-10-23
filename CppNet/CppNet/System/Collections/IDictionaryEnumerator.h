#ifndef SYSTEM_COLLECTIONS_IDICTIONARYENUMERATOR_H
#define SYSTEM_COLLECTIONS_IDICTIONARYENUMERATOR_H

#include "../../Defines.h"

#include "../../Utility.h"
#include "IEnumerator.h"
#include "DictionaryEntry.h"

namespace System
{
	namespace Collections
	{
		interface IDictionaryEnumerator : public IEnumerator
		{
			const Object& Key() const;
			const Object& Value() const;

			const DictionaryEntry& Entry() const;
		};
	}
}

#endif