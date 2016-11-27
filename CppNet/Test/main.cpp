#include <CppNet/CppNet.h>

int main()
 {
	std::wcout.imbue(std::locale(""));
	std::wcin.imbue(std::locale(""));

	using namespace CppNet::System;
	using namespace CppNet::KMC;

	// TEST CODE INPUT

	Array4D<Byte, 2, 2, 2, 2> arr(255);

	Byte*** i = new Byte**[2];
	i[0] = new Byte*[2];
	i[0][0] = new Byte[2];
	i[0][0][0] = 1;
	i[0][0][1] = 2;
	i[0][1] = new Byte[2];
	i[0][1][0] = 3;
	i[0][1][1] = 4;
	i[1] = new Byte*[2];
	i[1][0] = new Byte[2];
	i[1][0][0] = 5;
	i[1][0][1] = 6;
	i[1][1] = new Byte[2];
	i[1][1][0] = 7;
	i[1][1][1] = 8;

	arr[0] = i;

	MAIN_END
}