#include <CppNet/CppNet.h>

int main()
 {
	std::wcout.imbue(std::locale(""));
	std::wcin.imbue(std::locale(""));

	using namespace CppNet::System;
	using namespace CppNet::KMC;

	// TEST CODE INPUT

	Array7D<int, 2, 2, 2, 2, 2, 2, 2> arr;

	arr[0][0][0][0][0][0][0] = 5;

	Console::WriteLine(arr[0][0][0][0][0][0][0]);

	MAIN_END
}