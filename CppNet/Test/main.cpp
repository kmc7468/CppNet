#include <CppNet/CppNet.h>

int main()
{
	std::wcout.imbue(std::locale(""));
	std::wcin.imbue(std::locale(""));

	auto data = CppNet::System::Math::PrimeNumbers(1LL, 10000);

	CppNet::System::Console::WriteLine(data.size());

	for (auto i : data)
	{
		CppNet::System::Console::WriteLine(i);
	}

	MAIN_END
}