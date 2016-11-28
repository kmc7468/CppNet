#include <CppNet/CppNet.h>

int main()
{
	std::wcout.imbue(std::locale(""));
	std::wcin.imbue(std::locale(""));

	using namespace CppNet::System;
	using namespace CppNet::KMC;

	// TEST CODE INPUT

	ArrayND<Byte, 2, 2, 2> arr(5);

	CppNet::CTR::MultiPointer<int, 2>::Type t;

	MAIN_END
}