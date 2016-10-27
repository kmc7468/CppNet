#include <CppNet/CppNet.h>

int main()
{
	Sor8 s("\u0001");

	auto a = s.Encrypt((Byte*)"\0", 1);

	std::cout << (int)(*(std::get<0>(a))) << std::endl;

	auto b = s.Decrypt(std::get<0>(a), 1);

	std::cout << (int)(*(std::get<0>(b))) << std::endl;

	MAIN_END
}