#include <CppNet/CppNet.h>

#include <chrono>
using namespace std::chrono;

int main()
{
	auto g = gc::newgc<CppNet::KMC::Decimal>(3, "141592");

	std::cout << (*g).ToString() << std::endl;

	auto g2 = gc::newgc<CppNet::KMC::Decimal, 3>();

	std::cout << (g2[0])->ToString() << std::endl;
	std::cout << (g2[1])->ToString() << std::endl;
	std::cout << (g2[2])->ToString() << std::endl;

	MAIN_END
}