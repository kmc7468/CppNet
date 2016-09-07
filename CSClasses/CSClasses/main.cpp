

/*
	2016.09.07
	Created by kmc7468
*/

#include "System.h"
using namespace System;

int main(int argc, char** argv)
{
	Console::WriteLine(Math::PI);
	Random rd(RandomType::MT19937,40000);
	Console::WriteLine(rd.Next(5, 100));

	system("pause");

	return 0;
}