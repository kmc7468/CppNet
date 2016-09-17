#define LANG_KOR
#define WIN32

#include <string>
#include <CSClasses\CSClasses.h>

using namespace std;
using namespace System;
using namespace System::Collections::Generic;

int main(void)
{
	wcout.imbue(locale(""));
	wcin.imbue(locale(""));

	Queue<int> queue;
	queue.Enqueue(3);
	queue.Enqueue(4);
	var enumerator = queue.GetEnumerator();
	while (enumerator->MoveNext())
	{
		Console::WriteLine(enumerator->Current());
	}

	var arr = BitConverter::GetBytes(50000000000);
	
	var chr = BitConverter::ToInt64(arr);

	Console::WriteLine(chr);

	Console::WriteLine(DoubleT::Zero.Data());
	Console::WriteLine(DoubleT::NaN.Data());

	Console::WriteLine(DoubleT::IsNaN(DoubleT::NaN));

	Console::WriteLine(DoubleT::PositiveInfinity.Data());
	Console::WriteLine(DoubleT::NegativeInfinity.Data());
	Console::WriteLine(DoubleT::MaxValue.Data());
	Console::WriteLine(DoubleT::MinValue.Data());
	Console::WriteLine(DoubleT::Epsilon.Data());

	var a = BitConverter::GetBytes(std::numeric_limits<UInt64>::max());

	var c = BitConverter::BytesToHexString(a);

	Console::WriteLine(c);

	var a2 = BitConverter::HexStringToBytes<8>(c);

	Console::WriteLine(BitConverter::ToInt64(a2));

	Char Âm(u8"À§", 3);
	
	Console::WriteLine(Âm.Unicode());

	Console::WriteLine(Âm);

	MAIN_END
}