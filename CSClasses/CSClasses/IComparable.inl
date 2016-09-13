#include "IComparable.h"
#include "NotImplementedException.h"
#include <string>
using namespace std;

namespace System
{
	Int32 IComparable::CompareTo(const Object& obj)
	{
		throw NotImplementedException(Exception::ExceptionData(L""s, L""s, L""s));
	}
}