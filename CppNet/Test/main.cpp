#include <CppNet/CppNet.h>

int main()
{
	Decimal a(3.141592), b(1.4142);
	Console::WriteLine((a - b).ToString());
	return 0;
}