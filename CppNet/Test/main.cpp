#include <CppNet/CppNet.h>

int main()
{
	std::wcout.imbue(std::locale(""));
	std::wcin.imbue(std::locale(""));

	using namespace CppNet::System;
	using namespace CppNet::KMC;

	while (true)
	{
		Decimal a = Console::ReadLine();
		Decimal b = Console::ReadLine();

		Console::WriteLine((a * b).ToString());
	}

	MAIN_END
}