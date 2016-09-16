#ifndef SYSTEM_CHAR_H
#define SYSTEM_CHAR_H

#include "Object.h"
#include "Int32.h"

namespace System
{
	class Char : public Object
	{
	private:
		Int32 dat;

	public:
		inline Int32 Unicode() const;
	};
}

#endif