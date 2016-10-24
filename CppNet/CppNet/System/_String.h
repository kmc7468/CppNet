#ifndef SYSTEM__STRING_H
#define SYSTEM__STRING_H

#include "Object.h"
#include "Char.h"
#include "Text/Encoding.h"

#include "Int32.h"

namespace System
{
	class Char;

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
		Int32 alloc = 0;
		Char* chars = nullptr;

	public:
		_String();
		_String(Char* chars);
		_String(Char* chars, Int32 start, Int32 length);
		_String(Char chr, Int32 length);
		template<size_t size>
		_String(std::array<Char, size> arr);
		template<size_t size>
		_String(std::array<Char, size> arr, Int32 start, Int32 length);
		_String(const char* chars);
		_String(const char* chars, Int32 start, Int32 length);
		//_String(const char* chars, Int32 start, Int32 length, Text::Encoding encoding);
		~_String();
	};
}

#include "_String.inl"

#endif