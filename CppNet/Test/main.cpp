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

	DynamicVariable<int> i2;

	i2.Copy(i);

	Console::WriteLine(i2.At("A"));
	Console::WriteLine(i2.At("B"));

	MAIN_END
}