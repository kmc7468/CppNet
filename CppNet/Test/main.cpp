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

	Fraction64 f(1, 6);

	Fraction64 f2(12, 2);

	Fraction64 f3 = f2;

	Console::WriteLine(f3.ToString());
	Console::WriteLine(f3.ToReal64());

	MAIN_END
}