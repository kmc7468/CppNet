﻿#ifndef SYSTEM_COLLECTIONS_IENUMERABLE_H
#define SYSTEM_COLLECTIONS_IENUMERABLE_H

#include "System.h"
#include "IEnumerable.h"

namespace System
{
	namespace Collections
	{
		interface IEnumerable
		{
			//TODO: GetEnumerator, AsParallel, AsQueryable

			template <typename TResult>
			virtual Generic::IEnumerable<TResult> Cast() = 0;

			template <typename TResult>
			virtual Generic::IEnumerable<TResult> OfType() = 0;

		};
	}
}

#endif