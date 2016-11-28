#include <CppNet/CppNet.h>

int main()
{
	std::wcout.imbue(std::locale(""));
	std::wcin.imbue(std::locale(""));

	using namespace CppNet::System;
	using namespace CppNet::KMC;

	// TEST CODE INPUT

	ArrayND<Byte, 2, 2, 2> arr;

	Byte* i = new Byte[2];
	i[0] = 1;
	i[1] = 2;

	arr[0][0] = i;
	arr[0][1][0] = 3;
	arr[0][1][1] = 4;
	arr[1][0][0] = 5;
	arr[1][0][1] = 6;
	arr[1][1][0] = 7;
	arr[1][1][1] = 8;

	CppNet::CTR::MultiPointer<int, 2>::Type t;

	MAIN_END
}