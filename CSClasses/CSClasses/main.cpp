

/*
	2016.09.07
	Created by kmc7468
*/

#include "CSClasses.h"
using namespace System;
using namespace System::Collections::Generic;

int main(int argc, char** argv)
{
	Console::WriteLine(Math::PI);
	Random rd(RandomType::MT19937,40000);
	Console::WriteLine(rd.Next(5, 100));
	auto str = Console::ReadLine();
	Console::WriteLine(str);

	system("pause");

	return 0;
}