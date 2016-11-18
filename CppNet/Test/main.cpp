#include <CppNet/CppNet.h>

int main()
{
	std::wcout.imbue(locale(""));
	std::wcin.imbue(locale(""));

	Console::WriteLine(MaxValue<Int32>());
	Console::WriteLine(MinValue<Int32>());

	MAIN_END
}