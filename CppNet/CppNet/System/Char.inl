#include "Char.h"

#include "../Utility.h"
#include "Exception.h"

namespace System
{
	Int32 Char::CompareTo(const Object& obj) const
	{
		if (is<const Char&>(obj))
		{
			var c = as<const Char&>(obj);

			return (dat - c.dat);
		}
		else
			throw Exception("응 인자오류~"); // FIXME ArgumentException
	}

	Int32 Char::CompareTo(const Char& obj) const
	{
		return (dat - obj.dat);
	}

	Char::operator UInt32()
	{
		return dat;
	}

	Char Char::operator=(Char&& c)
	{
		dat = std::move(c.dat);
	}

	Char Char::operator=(const Char& c)
	{
		dat = c.dat;
	}

	Boolean Char::operator==(const Object& obj) const
	{
		return Equals(*const_cast<Object*>(&obj));
	}

	Boolean Char::operator!=(const Object& obj) const
	{
		return !Equals(*const_cast<Object*>(&obj));
	}

	Boolean Char::operator<(const Char& obj) const
	{
		return (dat < obj.dat);
	}
	 
	Boolean Char::operator<=(const Char& obj) const
	{
		return (dat <= obj.dat);
	}

	Boolean Char::operator>(const Char& obj) const
	{
		return (dat > obj.dat);
	}
	 
	Boolean Char::operator>=(const Char& obj) const
	{
		return (dat >= obj.dat);
	}

	Boolean Char::operator<(char32_t obj) const
	{
		return (dat < obj);
	}

	Boolean Char::operator<=(char32_t obj) const
	{
		return (dat <= obj);
	}

	Boolean Char::operator>(char32_t obj) const
	{
		return (dat > obj);
	}

	Boolean Char::operator>=(char32_t obj) const
	{
		return (dat >= obj);
	}

	Boolean Char::Equals(const Char& c) const
	{
		if (c.dat == dat)
			return true;
		else
			return false;
	}

	Boolean Char::Equals(Object& obj) const
	{
		if (is<Char&>(obj))
			return Equals(as<Char&>(obj));
		else
			return false;
	}

	Char Char::operator+(const Char& c) const
	{
		return dat + c.dat;
	}

	Char Char::operator-(const Char& c) const
	{
		return dat - c.dat;
	}

	Char Char::operator*(const Char& c) const
	{
		return dat * c.dat;
	}

	Char Char::operator/(const Char& c) const
	{
		return dat / c.dat;
	}

	Char Char::operator%(const Char& c) const
	{
		return dat % c.dat;
	}

	Char& Char::operator+=(const Char& c)
	{
		dat += c.dat;

		return *this;
	}

	Char& Char::operator-=(const Char& c)
	{
		dat -= c.dat;

		return *this;
	}

	Char& Char::operator*=(const Char& c)
	{
		dat *= c.dat;

		return *this;
	}

	Char& Char::operator/=(const Char& c)
	{
		dat /= c.dat;

		return *this;
	}

	Char& Char::operator%=(const Char& c)
	{
		dat %= c.dat;

		return *this;
	}
}