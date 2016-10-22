#include <CppNet/CppNet.h>

#include <chrono>
using namespace std::chrono;

void a(int i)
{
	std::cout << "1 " << i << std::endl;
}

void b(int i)
{
	std::cout << "2 " << i << std::endl;
}

void c(int i)
{
	std::cout << "3 " << i << std::endl;
}

evnt(std::function<void(int)>, e);

int main()
{
	e += a;
	e += decltype(e)::function_type(b);
	e += decltype(e)::function_type(c);
	e += [](int i) {std::cout << i << std::endl; };

	e(5);

	MAIN_END
}