#define LANG_KOR
#define WIN32

#include <string>
#include <CSClasses\CSClasses.h>

using namespace std;
using namespace System;
using namespace System::Collections::Generic;

int main(void)
{
	locale::global(locale("korean"));

	Queue<int> queue;
	queue.Enqueue(3);
	queue.Enqueue(4);
	var enumerator = queue.GetEnumerator();
	while (enumerator->MoveNext())
	{
		Console::WriteLine(enumerator->Current());
	}

	var i = Console::Read();

	Console::WriteLine(i);
	Console::WriteLine(50000);

	Int16 integer = 20000;

	std::cout << &integer << std::endl;
	
	var a = BitConverter::GetBytes((Int16)integer);

	MAIN_END
}