#include <CppNet/CppNet.h>

int main()
{
	std::wcout.imbue(std::locale(""));
	std::wcin.imbue(std::locale(""));

	using namespace CppNet::System;
	using namespace CppNet::KMC;

	Sor16 s(L"’×");

	auto a = s.Encrypt(L"wwww", 27);
	auto b = s.Decrypt(std::get<0>(a), 27);

	std::wcout << std::wstring(std::get<0>(a), std::get<1>(a)) << std::endl;
	std::wcout << std::wstring(std::get<0>(b), std::get<1>(b)) << std::endl;

	MAIN_END
}