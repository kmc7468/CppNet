#include <CppNet/CppNet.h>

#include <chrono>

#include <cmath>

#define P_Inf std::numeric_limits<double>::infinity()
#define N_Inf -std::numeric_limits<double>::infinity()

int main()
{
	std::wcout.imbue(locale(""));
	std::wcin.imbue(locale(""));

	/*_CalcTime(Console::WriteLine(Math::Energy(Decimal("5.5")).ToString()), std::chrono::duration<Double>, c)

	Console::WriteLine(c.count());*/

	Console::WriteLine(N_Inf + P_Inf);
	Console::WriteLine(N_Inf - P_Inf);
	Console::WriteLine(N_Inf * P_Inf);
	Console::WriteLine(N_Inf / P_Inf);
	Console::WriteLine(fmod(N_Inf, P_Inf));

	MAIN_END
}