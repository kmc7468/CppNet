#ifndef SYSTEM__STRING_H
#define SYSTEM__STRING_H

#include "Object.h"

#include "Int32.h"

namespace System
{
	class _String final : public Object
	{
	private:
		static const Int32 TrimHead;
		static const Int32 TrimTail;
		static const Int32 TrimBoth;

	public:
		static const _String Empty;

	private:
		Int32 length = 0;
	};
}

#endif