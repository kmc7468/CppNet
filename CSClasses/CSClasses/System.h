
/*
	2016.09.07
	Created by kmc7468
*/

#ifndef SYSTEM_H
#define SYSTEM_H

#include "Language.h"

#include <string>

namespace System
{
	using Boolean = bool;
	using Char = wchar_t;

	using Byte = std::uint8_t;
	using SByte = std::int8_t;

	using Int16 = std::int16_t;
	using Int32 = std::int32_t;
	using Int64 = std::int64_t;

	using UInt16 = std::uint16_t;
	using UInt32 = std::uint32_t;
	using UInt64 = std::uint64_t;

	using Single = float;
	using Double = double;

	using String = std::wstring;
}

#include "Object.h"

#include "Exception.h"
#include "InvalidCastException.h"
#include "FormatException.h"

#include "Console.h"
#include "Math.h"
#include "Random.h"
#include "DateTime.h"
#include "TimeSpan.h"
#include "Convert.h"

#define interface struct

template<typename T, typename U>
Boolean is(U u)
{
	return dynamic_cast<T>(u) != nullptr;
}

#endif