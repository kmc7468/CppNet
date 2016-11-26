#ifndef CPPNET_SYSTEM_COLLECTIONS_GENERIC_LIST_HPP
#define CPPNEP_SYSTEM_COLLECTIONS_GENERIC_LIST_HPP

#include "IList.h"
#include "IReadOnlyList.hpp"
#include "../../Predicate.hpp"

namespace CppNet::System::Collections::Generic
{
	template <typename T>
	class List : public IList<T>
	{
	public:
		List();
		List(const IEnumerable<T>& collection);
		List(Int32 capacity);

	public:
		virtual Int32 Count() const override;
		virtual Boolean Contains(const T& item) const override;
		
	public:
		virtual const T& operator[](Int32 index) const override;
		virtual T& operator[](Int32 index) override;

	public:
		virtual void Add(const T& item) override;
		virtual void AddRange(const IEnumerable<T>& collection) override;
		//TODO: AsReadOnly
		virtual Int32 BinarySearch(const T& item) const;
		//TODO: virtual Int32 BinarySearch(const T& item, const IComparer<T>& comparer)
		//TODO: virtual Int32 BinarySearch(Int32 index, Int32 count, const T& item, const IComparer<T>& comparer)
		virtual void Clear() override;
		//TODO: template <typename TOutput>
		//		virtual Box<List<TOutput>> ConvertAll(const Converter<T, TOutput>& converter) const;
		//TODO: CopyTo
		virtual Boolean Exists(const Predicate<T>& predicate) const;
		virtual T& Find(const Predicate<T>& predicate);
		virtual Box<List<T>> FindAll(const Predicate<T>& predicate);
		//TODO...

	private:
		std::vector<T> vector;

	private:
		struct Enumerator : public IEnumerator<T>
		{
		public:
			virtual T& Current() override;
			virtual Boolean MoveNext() override;
			virtual void Reset() override;

		private:
			Enumerator(List<T>& original);

		private:
			List<T>& original;
			typename std::vector<T>::iterator iter;
			bool first;
		};
	};
}

#include "List.inl"

#endif