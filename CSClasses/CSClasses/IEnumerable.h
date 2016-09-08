#define SYSTEM_COLLECTIONS_GENERIC_IENUMERABLE_H

#include "System.h"

#include <functional>

namespace System
{
	namespace Collections
	{
		namespace Generic
		{
			template <typename T = Object>
			interface IEnumerable
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

				template <typename TCast>
				virtual IEnumerable<TCast> Cast() = 0;

				virtual IEnumerable<T> Concat(IEnumerable<T> second) = 0;

				virtual Boolean Contains(T value) = 0;

				//TODO: Contains(T, IEqualityComparer<T>)

			};
		}
	}
}

#endif
