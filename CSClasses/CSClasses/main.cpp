

/*
	2016.09.07
	Created by kmc7468
*/


#define LANG_KOR

#include <string>
using namespace std;
#include "CSClassesCS.h"

int main(int argc, char** argv)
{
	std::wcout.imbue(std::locale(""));

	Console.WriteLine(L"Hello!"s);
	Console.WriteLine(Math.Abs(-20));

	try 
	{
		System::Convert::ToBoolean((wchar_t)5);
		Console.WriteLine(L"ぞし"s);
	}
	catch (System::Exception& e)
	{
		Console.WriteLine(e.Message());
		Console.WriteLine(L"ぞし2"s);
	}

	system("pause");

	return 0;
}