#include <CppNet/CppNet.h>

#include <chrono>
using namespace std::chrono;

prop(int, testa, GETA, SETA)

int main()
{
	std::cout << testa << std::endl;
	testa = 5;
	std::cout << testa << std::endl;

	system_clock::time_point a = system_clock::now();
	Integer i = 1;
	system_clock::time_point b = system_clock::now();
	duration<double> c = b - a;
	std::cout << c.count() << std::endl;

	Integer i2 = 1;

	a = system_clock::now();
	Integer i3 = i + i2;
	b = system_clock::now();

	c = b - a;

	std::cout << c.count() << std::endl;

	a = system_clock::now();
	UInt64 i4 = 1 + 1;
	b = system_clock::now();

	c = b - a;

	std::cout << c.count() << std::endl;

	MAIN_END
}