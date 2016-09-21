#include "CharUnicodeInfo.h"
using namespace System;
using namespace System::Globalization;

Int32 CharUnicodeInfo::GetDecimalDightValue(const Char& c)
{
	Char cc = *const_cast<Char*>(&c);
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
	// TODO
	return -1;
}
