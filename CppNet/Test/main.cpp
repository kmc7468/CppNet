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
	e += decltype(e)::del(b);
	e += decltype(e)::del(c);

	e(5);

	MAIN_END
}