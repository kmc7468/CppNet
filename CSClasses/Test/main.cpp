#define LANG_KOR
#define WIN32

#include <string>
#include <CSClasses\CSClasses.h>

using namespace std;
using namespace System;
using namespace System::Collections::Generic;

int main(void)
{
	Queue<int> queue(100);
	for (int i = 0; i < 100; ++i)
		queue.Enqueue(i);
	
	Console::WriteLine(queue.Count());
	Console::WriteLine(queue.Contains(7));
	Console::WriteLine(queue.Contains(101));
	queue.Clear();
	Console::WriteLine(queue.Count());
}