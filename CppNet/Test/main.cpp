#define LANG_KOR
#define WIN32

#include <string>
#include <chrono>
#include <tuple>

#include <CppNet/CppNet.h>

using namespace std;
using namespace System;
using namespace System::Collections::Generic;
using namespace CppNet;
using namespace CppNet::KMC;

int main(void)
{
	cout.imbue(locale("korean"));
	cin.imbue(locale("korean"));

	UInt64 integer = std::stoull(Console::ReadLine());

	var binstr = BitConverter::BytesToBinString(BitConverter::GetBytes(integer));

	Console::WriteLine(binstr);

	var hexstr = BitConverter::BytesToHexString(BitConverter::GetBytes(integer));

	Console::WriteLine(hexstr);

	UInt64 org = BitConverter::ToUInt64(BitConverter::BinStringToBytes<8>(binstr));

	Console::WriteLine(org);

	org = BitConverter::ToUInt64(BitConverter::HexStringToBytes<8>(hexstr));

	Console::WriteLine(org);

	MAIN_END
}