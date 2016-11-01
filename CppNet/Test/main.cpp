#include <CppNet/CppNet.h>

#include <chrono>

int main()
{
	std::wcout.imbue(locale(""));
	std::wcin.imbue(locale(""));

	/*_CalcTime(Console::WriteLine(Math::Energy(Decimal("5.5")).ToString()), std::chrono::duration<Double>, c)

	Console::WriteLine(c.count());*/

	Console::WriteLine((Decimal("5234") * Decimal("352")).ToString());

	Console::WriteLine((Decimal("0") / Decimal("0")).ToString());
	Console::WriteLine((Decimal("1") / Decimal("0")).ToString());
	Console::WriteLine((Decimal("-1") / Decimal("0")).ToString());

	MAIN_END
}