#include <CppNet/CppNet.h>

int main()
{
	std::cout.imbue(locale("korean"));

	Sor8 s("¤±");

	auto a = s.Encrypt((Byte*)"¤»", 1);

	std::cout << (int)(*(std::get<0>(a))) << std::endl;

	auto b = s.Decrypt(std::get<0>(a), 1);

	std::cout << (int)(*(std::get<0>(b))) << std::endl;

	String c = s.GetKey();

	std::cout << c << std::endl;

	MAIN_END
}