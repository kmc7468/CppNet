#include <CppNet/CppNet.h>

int main()
{
	std::wcout.imbue(locale(""));
	std::wcin.imbue(locale(""));

	Console::WriteLine(CTR::Factorial<5>::Value);
	Console::WriteLine(CTR::Fibonacci<5>::Value);

	MAIN_END
}