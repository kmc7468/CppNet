#include <CppNet/CppNet.h>

#include <chrono>
using namespace std::chrono;

class test : public IDictionary
{
	std::unique_ptr<IDictionaryEnumerator> GetEnumerator() override
	{

	}
};

int main()
{
	MAIN_END
}