#define LANG_KOR
#define WIN32

#include <string>
#include <chrono>

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

	Fraction64 f(5, 10);

	f.Reduction();

	MAIN_END
}