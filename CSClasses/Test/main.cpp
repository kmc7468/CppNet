#define LANG_KOR
#define WIN32

#include <string>
#include <CSClasses\CSClasses.h>

using namespace std;
using namespace System;
using namespace System::Collections::Generic;

int main(void)
{
	Queue<int> queue;
	queue.Enqueue(3);
	queue.Enqueue(4);
	var enumerator = queue.GetEnumerator();
	while (enumerator->MoveNext())
	{
		Console::WriteLine(enumerator->Current());
	}
}