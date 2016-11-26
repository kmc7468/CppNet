#include <iterator>

namespace CppNet::System::Collections::Generic
{
	template<typename T>
	List<T>::List()
	{
	}

	template<typename T>
	List<T>::List(const IEnumerable<T>& collection)
	{
		AddRange(collection);
	}

	template<typename T>
	List<T>::List(Int32 capacity)
	{
		vector.reserve(capacity);
	}

	template<typename T>
	Int32 List<T>::Count() const
	{
		return vector.size();
	}
	template<typename T>
	Boolean List<T>::Contains(const T & item) const
	{
		return find(vector.cbegin(), vector.cend(), item) != vector.cend();
	}

	template<typename T>
	const T & List<T>::operator[](Int32 index) const
	{
		return vector[index];
	}

	template<typename T>
	T & List<T>::operator[](Int32 index)
	{
		return vector[index];
	}
	template<typename T>
	void List<T>::Add(const T & item)
	{
		vector.push_back(item);
	}
	template<typename T>
	void List<T>::AddRange(const IEnumerable<T>& collection)
	{
		for (auto e = collection.GetEnumerator(); e->MoveNext();)
			vector.push_back(e->Current());
	}
	template<typename T>
	Int32 List<T>::BinarySearch(const T & item) const
	{
		auto iter = std::lower_bound(vector.cbegin(), vector.cend(), item);
		if (iter != vector.cend())
		{
			Int32 ret = std::distance(vector.cbegin(), iter);
			return std::binary_search(vector.cbegin(), vector.cend(), item) ? ret : ~ret;
		}
		else
			return ~Count();
	}
	template<typename T>
	void List<T>::Clear()
	{
		vector.clear();
	}
	template<typename T>
	Boolean List<T>::Exists(const Predicate<T>& predicate) const
	{
		return std::find_if(vector.cbegin(), vector.cend(), predicate);
	}
	template<typename T>
	T & List<T>::Find(const Predicate<T>& predicate)
	{
		//TODO: T의 기본값을 전달해야 하는데...
	}
	template<typename T>
	Box<List<T>> List<T>::FindAll(const Predicate<T>& predicate)
	{
		Box<List<T>> ret = Box<List<T>>(new List<T>());
		std::copy_if(vector.begin(), vector.end(), std::back_inserter(ret->vector), predicate);
		return ret;
	}

	template <typename T>
	T& List<T>::Enumerator::Current()
	{
		if (first || iter == original.vector.end())
			throw InvalidOperationException();
		return *iter;
	}

	template<typename T>
	Boolean List<T>::Enumerator::MoveNext()
	{
		if (first)
			return !(first = false);
		if (++iter == original.vector.end())
			return false;
		return true;
	}

	template<typename T>
	void List<T>::Enumerator::Reset()
	{
		iter = original.vector.begin();
		first = true;
	}

	template <typename T>
	List<T>::Enumerator::Enumerator(List<T>& original)
		: original(original), iter(original.vector.begin()), first(true)
	{
	}
}