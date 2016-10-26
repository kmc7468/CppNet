#include "_String.h"

namespace CppNet
{
	namespace System
	{
		template<size_t size>
		_String::_String(std::array<Char, size> arr)
		{
			chars = new Char[size + 10];
			alloc = size + 10;
			length = size;

			for (size_t i = 0; i < size; i++)
				chars[i] = arr[i];
		}

		template<size_t size>
		_String::_String(std::array<Char, size> arr, size_t start, size_t length)
			: _String(arr.data(), start, length)
		{ }
	}
}