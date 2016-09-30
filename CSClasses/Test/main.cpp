#define LANG_KOR
#define WIN32

#include <string>
#include <CSClasses\CSClasses.h>
#include <chrono>

using namespace std;
using namespace System;
using namespace System::Collections::Generic;

int main(void)
{
	cout.imbue(locale("korean"));
	cin.imbue(locale("korean"));

	{
		var time_a = std::chrono::system_clock::now();

		Decimal d = 2.0;

		var time_b = std::chrono::system_clock::now();

		std::chrono::duration<double> sec = time_b - time_a;

		Console::WriteLine(sec.count());
	}

	{
		var time_a = std::chrono::system_clock::now();

		Decimal d = "3.141592"s;

		var time_b = std::chrono::system_clock::now();

		std::chrono::duration<double> sec = time_b - time_a;

		Console::WriteLine(sec.count());
	}

	{
		Decimal d1 = 5.3;
		Decimal d2 = "15.9"s;
		Decimal d3;
		
		var time_a = std::chrono::system_clock::now();

		d3 = d1 + d2;

		var time_b = std::chrono::system_clock::now();

		std::chrono::duration<double> sec = time_b - time_a;

		Console::WriteLine(sec.count());
		Console::WriteLine(d3.ToString());
	}

	{
		String a = Console::ReadLine();
		String b = Console::ReadLine();

		Decimal d1 = a;
		Decimal d2 = b;
		Decimal d3 = d1 - d2;


		if (d1 > d2)
			Console::WriteLine("d1 > d2"s);
		else if (d1 < d2)
			Console::WriteLine("d1 < d2"s);
		else if (d1 == d2)
			Console::WriteLine("d1 == d2"s);

		Console::WriteLine(d3.ToString());
	}

	MAIN_END
}