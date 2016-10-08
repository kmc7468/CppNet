#include <CppNet/CppNet.h>

#include <chrono>
using namespace std::chrono;

int main()
{
	system_clock::time_point a = system_clock::now();
	auto g = gc::newgc<int>(100);
	system_clock::time_point b = system_clock::now();

	duration<double> d = b - a;

	std::cout << d.count() << std::endl;

	std::cout << *g << std::endl;

	a = system_clock::now();
	auto g2 = gc::newgc<unsigned char, 10000>(20);
	b = system_clock::now();
	d = b - a;

	std::cout << d.count() << std::endl;
	
	/*size_t index = 0;
	for (auto a : g2)
	{
		std::cout << index << " " << *a << std::endl;
		index++;
	}*/

	MAIN_END
}