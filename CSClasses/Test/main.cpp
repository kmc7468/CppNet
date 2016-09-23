#define LANG_KOR
#define WIN32

#include <string>
#include <CSClasses\CSClasses.h>

using namespace std;
using namespace System;
using namespace System::Collections::Generic;

int main(void)
{
	cout.imbue(locale("korean"));
	cin.imbue(locale("korean"));

	var arr = BitConverter::GetBytes((Int16)30000);
	Console::WriteLine(BitConverter::BytesToHexString(arr));
	
	arr = BitConverter::HexStringToBytes<2>(BitConverter::BytesToHexString(arr));

	Console::WriteLine(BitConverter::ToInt16(arr));

	MAIN_END
}