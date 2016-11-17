#include <CppNet/CppNet.h>

int main()
{
	std::wcout.imbue(locale(""));
	std::wcin.imbue(locale(""));

	Box<DoubleT> i_a = nullptr;
	Box<DoubleT> i_b;
	Box<DoubleT> i_c = 5;

	i_a = 10;
	i_b = 5;
	i_c = 12;

	Box<DoubleT> i_d = i_a;
	Box<DoubleT> i_e = i_b;
	Box<DoubleT> i_f = i_c;

	std::cout << i_a->Data() << std::endl;
	std::cout << i_b->Data() << std::endl;
	std::cout << i_c->Data() << std::endl;

	std::cout << i_a.ReferenceCount() << std::endl;
	std::cout << i_d.ReferenceCount() << std::endl;

	MAIN_END
}