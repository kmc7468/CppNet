#ifndef CPPNET_SYSTEM_COLLECTIONS_COMPATIBLECOMPARER_HPP
#define CPPNET_SYSTEM_COLLECTIONS_COMPATIBLECOMPARER_HPP

#include "../../../Utility.h"

#include "IEqualityComparer.hpp"
#include "IComparer.hpp"
#include "IHashCodeProvider.hpp"
#include "Hashtable.h"

#include "../IComparable.h"
#include "../Int32.h"
#include "../ArgumentException.h"

namespace CppNet::System::Collections
{
	class CompatibleComparer : public IEqualityComparer
	{
		friend class Hashtable;
	private:
		IComparer* comparer = nullptr;
		IHashCodeProvider* hcp = nullptr;

	_internal:
		CompatibleComparer(IComparer* comparer, IHashCodeProvider* hcp)
		{
			this->comparer = comparer;
			this->hcp = hcp;
		}

		CompatibleComparer(const CompatibleComparer& com)
		{
			this->comparer = com.comparer;
			this->hcp = com.hcp;
		}

		CompatibleComparer(CompatibleComparer&& com)
		{
			this->comparer = com.comparer;
			this->hcp = com.hcp;
		}

		Int32 Compare(const Object& a, const Object& b) const
		{
			if (a == b) return 0;
			if (comparer)
				return comparer->Compare(a, b);
			const IComparable<>* ia = as_c<const IComparable<>*>(&a);
			if (ia)
				return ia->CompareTo(b);

			throw ArgumentException();
		}

		inline Boolean Equals(const Object& x, const Object& y) const override
		{
			return Compare(x, y) == 0;
		}

		Int32 GetHashCode(const Object& obj) const override
		{
			if (hcp)
				return hcp->GetHashCode(obj);
			
			return -1;
		}

		IComparer* Comparer() const
		{
			return comparer;
		}

		IHashCodeProvider* HashCodeProvider() const
		{
			return hcp;
		}
	};
}

#endif