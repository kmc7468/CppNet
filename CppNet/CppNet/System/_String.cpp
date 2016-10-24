#include "_String.h"

namespace System
{
	const Int32 _String::TrimHead = 0;
	const Int32 _String::TrimTail = 1;
	const Int32 _String::TrimBoth = 2;

	const _String _String::Empty = _String();

	_String::_String()
	{
		chars = new Char[10];
		alloc = 10;
	}

	_String::~_String()
	{
		if (chars != nullptr)
		{
			delete[] chars;
			chars = nullptr;
		}
	}

	_String::_String(Char* chars)
	{
		size_t len = strlen((char*)chars) / (sizeof(Char) / sizeof(char));

		this->chars = new Char[len + 10];
		alloc = len + 10;
		length = len;

		memcpy(this->chars, chars, length);
	}

	_String::_String(Char* chars, Int32 start, Int32 length)
	{
		this->chars = new Char[this->length + 10];
		alloc = length + 10;
		this->length = length;

		memcpy(this->chars, chars + start, length);
	}

	_String::_String(Char chr, Int32 length)
	{
		chars = new Char[length + 10];
		alloc = length + 10;
		this->length = length;

		for (Int32 i = 0; i < length; i++)
			chars[i] = chr;
	}

	_String::_String(const char* chars)
	{
		size_t len = strlen(chars);

		this->chars = new Char[len + 10];
		alloc = len + 10;
		length = len;

		memcpy(this->chars, chars, len);
	}

	_String::_String(const char* chars, Int32 start, Int32 length)
	{
		this->chars = new Char[length + 10];
		alloc = length + 10;
		this->length = length;

		memcpy(this->chars, chars + start, length);
	}
}