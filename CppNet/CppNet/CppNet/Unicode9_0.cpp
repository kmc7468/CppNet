#include "Unicode9_0.h"
using namespace CppNet;

Unicode9_0::Unicode9_0()
{
	numStarts = new std::vector<char32_t>;

	numStarts->push_back(0x30);
	numStarts->push_back(0x660);
	numStarts->push_back(0x6F0);
	numStarts->push_back(0x7C0);
	numStarts->push_back(0x966);
	numStarts->push_back(0x9E6);
	numStarts->push_back(0xA66);
	numStarts->push_back(0xAE6);
	numStarts->push_back(0xB66);
	numStarts->push_back(0xBE6);
	numStarts->push_back(0xC66);
	numStarts->push_back(0xCE6);
	numStarts->push_back(0xD66);
	numStarts->push_back(0xDE6);
	numStarts->push_back(0xE50);
	numStarts->push_back(0xED0);
	numStarts->push_back(0xF20);
	numStarts->push_back(0x1040);
	numStarts->push_back(0x1090);
	numStarts->push_back(0x17E0);
	numStarts->push_back(0x1810);
	numStarts->push_back(0x1946);
	numStarts->push_back(0x19D0);
	numStarts->push_back(0x1A80);
	numStarts->push_back(0x1A90);
	numStarts->push_back(0x1B50);
	numStarts->push_back(0x1BB0);
	numStarts->push_back(0x1C40);
	numStarts->push_back(0x1C50);
	numStarts->push_back(0xA620);
	numStarts->push_back(0xA8D0);
	numStarts->push_back(0xA900);
	numStarts->push_back(0xA9D0);
	numStarts->push_back(0xA9F0);
	numStarts->push_back(0xAA50);
	numStarts->push_back(0xABF0);
	numStarts->push_back(0xFF10);
	numStarts->push_back(0x104A0);
	numStarts->push_back(0x11066);
	numStarts->push_back(0x110F0);
	numStarts->push_back(0x11136);
	numStarts->push_back(0x111D0);
	numStarts->push_back(0x112F0);
	numStarts->push_back(0x11450);
	numStarts->push_back(0x114D0);
	numStarts->push_back(0x11650);
	numStarts->push_back(0x116C0);
	numStarts->push_back(0x11730);
	numStarts->push_back(0x118E0);
	numStarts->push_back(0x11C50);
	numStarts->push_back(0x16A60);
	numStarts->push_back(0x16B50);
	numStarts->push_back(0x1D7CE);
	numStarts->push_back(0x1D7D8);
	numStarts->push_back(0x1D7E2);
	numStarts->push_back(0x1D7EC);
	numStarts->push_back(0x1D7F6);
	numStarts->push_back(0x1E950);
}

Unicode9_0::~Unicode9_0()
{
	delete numStarts;
}

System::Int32 Unicode9_0::GetDecimalDightValue(const System::Char& c) const
{
	for (auto n : *numStarts)
	{
		if (c >= n && c <= (n + 9))
		{
			return c - n;
		}
	}
	return -1;
}

Unicode* Unicode9_0::Clone() const
{
	return new Unicode9_0();
}