#include <CppNet/CppNet.h>

int main()
{
	std::wcout.imbue(locale(""));
	std::wcin.imbue(locale(""));

	DynamicVariable<int> i;

	i.Alloc("A", 5);
	i.Alloc("B", 10);

	Console::WriteLine(i.At("A"));
	Console::WriteLine(i.At("B"));

	i.Free("A");
	i.Free("B");

	try 
	{
		Console::WriteLine(i.At("A"));
	}
	catch (Exception& ex)
	{
		Console::WriteLine("오류: "s + ex.Message());
	}

	try
	{
		Console::WriteLine(i.At("B"));
	}
	catch (Exception& ex)
	{
		Console::WriteLine("오류: "s + ex.Message());
	}
	

	MAIN_END
}