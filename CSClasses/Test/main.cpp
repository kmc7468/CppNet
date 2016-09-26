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

	CSClasses::KMC::Decimal d;

	Console::WriteLine(d.ToString());

	CSClasses::KMC::Decimal d2 = 3.14;

	Console::WriteLine(d2.ToString());

	CSClasses::KMC::Decimal d3 = d + d2;

	Console::WriteLine(d3.ToString());

	MAIN_END
}