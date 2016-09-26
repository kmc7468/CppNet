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

	CSClasses::KMC::Decimal64 d = 5.3;
	CSClasses::KMC::Decimal64 d2 = 3.3;

	d *= d2;

	Console::WriteLine(d.ToString());

	CSClasses::KMC::Decimal d3("3.1415926535");

	Console::WriteLine(d3.ToString(15));

	MAIN_END
}