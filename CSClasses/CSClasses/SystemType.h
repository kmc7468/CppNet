#ifndef SYSTEM_SYSTEMTYPE_H
#define SYSTEM_SYSTEMTYPE_H

#include <string>
#include <functional>

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

	template <typename TResult, typename... Args>
	using Func = std::function<TResult(Args...)>;
}

#endif