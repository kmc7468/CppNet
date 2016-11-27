#include <CppNet/CppNet.h>

int main()
 {
	std::wcout.imbue(std::locale(""));
	std::wcin.imbue(std::locale(""));

	using namespace CppNet::System;
	using namespace CppNet::KMC;

	// TEST CODE INPUT

	Array5D<Byte, 1, 2, 2, 2, 2> arr(0);

	Byte**** i = new Byte***[2];
	i[0] = new Byte**[2];
	i[0][0] = new Byte*[2];
	i[0][0][0] = new Byte[2];
	i[0][0][0][0] = 1;
	i[0][0][0][1] = 2;
	i[0][0][1] = new Byte[2];
	i[0][0][1][0] = 3;
	i[0][0][1][1] = 4;
	i[0][1] = new Byte*[2];
	i[0][1][0] = new Byte[2];
	i[0][1][0][0] = 5;
	i[0][1][0][1] = 6;
	i[0][1][1] = new Byte[2];
	i[0][1][1][0] = 7;
	i[0][1][1][1] = 8;
	i[1] = new Byte**[2];
	i[1][0] = new Byte*[2];
	i[1][0][0] = new Byte[2];
	i[1][0][0][0] = 9;
	i[1][0][0][1] = 10;
	i[1][0][1] = new Byte[2];
	i[1][0][1][0] = 11;
	i[1][0][1][1] = 12;
	i[1][1] = new Byte*[2];
	i[1][1][0] = new Byte[2];
	i[1][1][0][0] = 13;
	i[1][1][0][1] = 14;
	i[1][1][1] = new Byte[2];
	i[1][1][1][0] = 15;
	i[1][1][1][1] = 16;

	arr[0] = i;

	MAIN_END
}