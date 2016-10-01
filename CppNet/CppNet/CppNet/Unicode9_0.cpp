#include "Unicode9_0.h"
using namespace CppNet;

System::Int32 Unicode9_0::GetDecimalDightValue(const System::Char& c) const
{
	System::Char cc = *const_cast<System::Char*>(&c);
	if (cc >= U'0' && cc <= U'9')
	{
		return cc - U'0';
	}
	else if (cc >= U'\u0660' && cc <= U'\u0669')
	{
		return cc - U'\u0660';
	}
	else if (cc >= U'\u06F0' && cc <= U'\u06F9')
	{
		return cc - U'\u06F0';
	}
	else if (cc >= U'\u07C0' && cc <= U'\u07C9')
	{
		return cc - U'\u07C0';
	}
	else if (cc >= U'\u0966' && cc <= U'\u096F')
	{
		return cc - U'\u0966';
	}
	else if (cc >= U'\u09E6' && cc <= U'\u09EF')
	{
		return cc - U'\u09EF';
	}
	else if (cc >= U'\u0A66' && cc <= U'\u0A6F')
	{
		return cc - U'\u0A66';
	}
	else if (cc >= U'\u0AE6' && cc <= U'\u0AEF')
	{
		return cc - U'\u0AE6';
	}
	else if (cc >= U'\u0B66' && cc <= U'\u0B6F')
	{
		return cc - U'\u0B66';
	}
	else if (cc >= U'\u0BE6' && cc <= U'\u0BEF')
	{
		return cc - U'\u0BE6';
	}
	else if (cc >= U'\u0C66' && cc <= U'\u0C6F')
	{
		return cc - U'\u0C66';
	}
	else if (cc >= U'\u0CE6' && cc <= U'\u0CEF')
	{
		return cc - U'\u0CE6';
	}
	else if (cc >= U'\u0D66' && cc <= U'\u0D6F')
	{
		return cc - U'\u0D66';
	}
	else if (cc >= U'\u0DE6' && cc <= U'\u0DEF')
	{
		return cc - U'\u0DE6';
	}
	else if (cc >= U'\u0E50' && cc <= U'\u0E59')
	{
		return cc - U'\u0E59';
	}
	else if (cc >= U'\u0ED0' && cc <= U'\u0ED0')
	{
		return cc - U'\u0ED0';
	}
	else if (cc >= U'\u0F20' && cc <= U'\u0F29')
	{
		return cc - U'\u0F20';
	}
	// TODO
	return -1;
}

Unicode* Unicode9_0::Clone() const
{
	return new Unicode9_0();
}