#ifndef SYSTEM_COLLECTIONS_GENERIC_IENUMERABLE_H
#define SYSTEM_COLLECTIONS_GENERIC_IENUMERABLE_H

#include "System.h"

#include <functional>

namespace System
{
	namespace Collections
	{
		class IEnumerable;

		namespace Generic
		{
			//FIXME: 실제 구현 시 불필요한 복사 등이 많이 일어날 가능성이 있음.
			template <typename T>
			interface IEnumerable : public System::Collections::IEnumerable
			{
				//TODO: GetEnumerator

				virtual T Aggregate(Func<T, T, T> func) = 0;

				template <typename TAccumulate>
				virtual TAccumulate Aggregate(TAccumulate seed, Func<TAccumulate, TAccumulate, T> func) = 0;

				template <typename TAccumulate, typename TResult>
				virtual TResult Aggregate(TAccumulate seed, Func<TAccumulate, TAccumulate, T> func, Func<TResult, TAccumulate> resultSelector) = 0;

				virtual Boolean All(Func<Boolean, T> predicate) = 0;

				//TODO: Ancestors

				virtual Boolean Any() = 0;

				virtual Boolean Any(Func<Boolean, T> predicate) = 0;

				virtual IEnumerable<T> AsEnumerable() = 0;

				//TODO: AsParallel

				//TODO: AsQueryable

				//TODO: Decimal Average(Func<Decimal, T> selector)

				virtual Double Average(Func<Double, T> selector) = 0;

				virtual Int32 Average(Func<Int32, T> selector) = 0;

				virtual Int64 Average(Func<Int64, T> selector) = 0;

				//TODO: Nullable Average

				virtual Single Average(Func<Single, T> selector) = 0;

				//NOTE: 원래 IEnumerable -> IEnumerable<T> 인데 C++ 템플릿은 저런 걸 지원을 안함.
				template <typename TCast>
				virtual IEnumerable<TCast> Cast() = 0;

				virtual IEnumerable<T> Concat(IEnumerable<T> second) = 0;

				virtual Boolean Contains(T value) = 0;

				//TODO: Contains(T, IEqualityComparer<T>)

				//TODO: CopyToDataTable

				virtual Int32 Count() = 0;

				virtual Int32 Count(Func<T, Boolean> predicate) = 0;

				//TODO: DefaultIfEmpty ~ Zip

			};
		}
	}
}

#endif
