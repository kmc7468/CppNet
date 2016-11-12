#ifndef CPPNET_SYSTEM_RUNTIME_COMPILERSERVICES_CONDITIONALWEAKTABLE_HPP
#define CPPNET_SYSTEM_RUNTIME_COMPILERSERVICES_CONDITIONALWEAKTABLE_HPP

#include "../../Object.h"

namespace CppNet::System::Runtime::CompilerServices
{
	template<typename TKey, typename TValue>
	class ConditionalWeakTable final : public Object
	{
	private:
		static const Int32 _initialCapacity;

	private:
		class Entry
		{
		public:
			Int32 hashCode = 0;
			Int32 next = 0;

		};

		Int32* _buckets = nullptr;
		Entry* entries = nullptr;
		Int32 _freeList = 0;
		Object* _lock = nullptr;
		Boolean _invalid = false;
	};
}

#endif