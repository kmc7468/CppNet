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

	Fraction64 a = Console::ReadLine();
	Fraction64 b = Console::ReadLine();

	Console::WriteLine((a + b).ToString());
	Console::WriteLine((a - b).ToString());
	Console::WriteLine((a * b).ToString());
	Console::WriteLine((a / b).ToString());

	MAIN_END
}