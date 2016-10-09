#include "Integer.h"
using namespace CppNet::KMC;

#include "../../System/Int16.h"
#include "../../System/BitConverter.h"

#include <cstring>

Integer::Integer()
{
	len = 1;
	data = (Byte*)calloc(1, 1);
	if (data == NULL)
		throw std::bad_alloc();
}

Integer::Integer(Int64 i)
{
	len = 8;
	data = (Byte*)calloc(8, 1);
	if (data == NULL)
		throw std::bad_alloc();

	if (BitConverter::IsLittleEndian)
	{
		for (size_t j = 0; j < 8; j++)
		{
			memcpy(data + j, ((Byte*)(&i)) + (7 - j), 1);
		}
	}
	else
	{
		for (size_t j = 0; j < 8; j++)
		{
			memcpy(data + j, ((Byte*)(&i) + j), 1);
		}
	}

	size_t r = 0;

	for (size_t i = 0; i < 8; i++)
	{
		if (data[i] == 0)
			r++;
		else
			break;
	}

	resize(8 - r);
}

Integer::Integer(const Integer& i)
{
	len = i.len;

	if (i.data)
		data = (Byte*)calloc(len, 1);

	if (data == NULL)
		throw std::bad_alloc();

	std::memcpy(data, i.data, len);
}

Integer::Integer(Integer&& i)
{
	len = i.len;

	if (i.data)
		data = (Byte*)calloc(len, 1);

	if (data == NULL)
		throw std::bad_alloc();

	std::memcpy(data, i.data, len);
}

Integer::~Integer()
{
	if (data) free(data);
}

void Integer::resize(size_t newsize)
{
	if (newsize == len) return;
	else if (newsize > len) // newsize가 len보다 큼
	{
		Byte* n_data = (Byte*)calloc(newsize, 1);
		if (n_data == NULL)
			throw std::bad_alloc();

		std::memmove(n_data + (newsize - len), data, len);
		std::memset(n_data, 0, newsize - len);

		free(data);

		len = newsize;
		data = n_data;
	}
	else // len이 newsize보다 큼
	{
		Byte* n_data = (Byte*)calloc(newsize, 1);
		if (n_data == NULL)
			throw std::bad_alloc();

		std::memmove(n_data, data, newsize);

		free(data);

		len = newsize;
		data = n_data;
	}
}

Integer Integer::operator+(const Integer& i) const
{
	Integer res;

	Integer a = *this;
	Integer b = i;

	size_t newsize = a.len > b.len ? a.len : b.len;

	a.resize(newsize);
	b.resize(newsize);

	res.resize(newsize);

	Byte up = 0; // 올림

	for (size_t j = newsize - 1; j >= 0; j--)
	{
		Int16 added = a.data[j] + b.data[j] + up;

		up = 0;

		if (added > 9)
		{
			up = 1;
			res.data[j] = (Byte)(added - 10);
		}
		else
			res.data[j] = (Byte)added;

		if (j == 0) break;
	}

	if (up != 0)
	{
		res.resize(res.len + 1);
		res.data[0] = up;
	}

	return res;
}

Integer& Integer::operator+=(const Integer& i)
{
	auto a = *this + i;

	resize(a.len);

	std::memmove(data, a.data, len);

	return *this;
}

String Integer::ToString() const
{
	return "";
}