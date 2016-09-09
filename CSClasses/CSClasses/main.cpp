

/*
	2016.09.07
	Created by kmc7468
*/


#define LANG_KOR

#include <string>
using namespace std;

#include "CSClasses.h"
using namespace System;
using namespace System::Collections::Generic;

int main(int argc, char** argv)
{
	std::wcout.imbue(std::locale(""));

	List<int> i;
	i.push_back(5);
	i.push_back(10);

	for (auto integer : i)
	{
		Console::WriteLine(integer);
	}

	try
	{
		Convert::ToBoolean((Char)5);
	}
	catch (Exception& e)
	{
		Console::WriteLine(e.Message());
	}

	try
	{
		auto b = Convert::ToBoolean(L"TrUe"s);
	
		Console::WriteLine(b);
	}
	catch (Exception& e)
	{
		Console::WriteLine(e.Message());
	}

	Console::WriteLine(sizeof(Int16));

	system("pause");

	return 0;
}