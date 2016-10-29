#include <CppNet/CppNet.h>

int main()
{
	std::wcout.imbue(locale(""));

	wstring org = L"六六六六";
	wstring key = L"擠傍";

	Sor16 s(key);

	auto a = s.Encrypt(const_cast<wchar_t*>(org.data()), org.length());

	auto b = s.Decrypt(std::get<0>(a), org.length());

	std::wcout << std::get<0>(b) << std::endl;

	MAIN_END
}