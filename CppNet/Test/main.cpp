#include <CppNet/CppNet.h>

#include <chrono>
using namespace std::chrono;

int a(int i, double d, const char* str)
{
	std::cout << "1 " << i << " " << d << " " << str << std::endl;
	return 1;
}

int b(int i, double d, const char* str)
{
	std::cout << "2 " << i << " " << d << " " << str << std::endl;
	return 2;
}

int c(int i, double d, const char* str)
{
	std::cout << "3 " << i << " " << d << " " << str << std::endl;
	return 3;
}

evnt(std::function<int(int, double, const char*)>, e);

int main()
{
	e += a;
	e += b;
	e += c;
	e += [](int i, double d, const char* str) {std::cout << "4 " << i << " " << d << " " << str << std::endl; return 4; };

	e(4, 5.0, "¤±¤¤¤·¤©");

	std::cout << e.Result(3) << std::endl;

	MAIN_END
}