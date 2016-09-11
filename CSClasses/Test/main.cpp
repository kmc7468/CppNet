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
	Console::WriteLine(queue.Dequeue());
	Console::WriteLine(queue.Dequeue());
}