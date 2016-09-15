#define LANG_KOR
#define WIN32

#include <string>
#include <CSClasses\CSClasses.h>

using namespace std;
using namespace System;
using namespace System::Collections::Generic;

int main(void)
{
	wcout.imbue(locale(""));
	wcin.imbue(locale(""));

	Queue<int> queue;
	queue.Enqueue(3);
	queue.Enqueue(4);
	var enumerator = queue.GetEnumerator();
	while (enumerator->MoveNext())
	{
		Console::WriteLine(enumerator->Current());
	}

	var arr = BitConverter::GetBytes(50000000000);
	
	var chr = BitConverter::ToInt64(arr);

	Console::WriteLine(chr);

	MAIN_END
}