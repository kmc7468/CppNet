#include <CppNet/CppNet.h>

#include <chrono>

int main()
{
	std::wcout.imbue(locale(""));
	std::wcin.imbue(locale(""));
	
	Console::WriteLine(Math::C);

	std::chrono::system_clock::time_point a = std::chrono::system_clock::now();

	Console::WriteLine(Math::Energy(Decimal("5")).ToString());

	std::chrono::system_clock::time_point b = std::chrono::system_clock::now();

	std::chrono::duration<Double> c = b - a;

	Console::WriteLine(c.count());

	MAIN_END
}