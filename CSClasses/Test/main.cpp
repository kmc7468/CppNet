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

	CSClasses::KMC::Decimal64 d = 0.0;
	CSClasses::KMC::Decimal64 d2 = 0.2;

	for (int i = 0; i < 100; i++)
	{
		d += d2;
	}

	Console::WriteLine(d.ToString());

	MAIN_END
}