#include <CppNet/CppNet.h>

int main()
{
	while (true)
	{
		String temp = Console::ReadLine();

		if (temp == "X") break;

		String temp2 = Console::ReadLine();

		Decimal a(temp), b(temp2);

		Console::WriteLine((a * b).ToString());
	}

	MAIN_END
}