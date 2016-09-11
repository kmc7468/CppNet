#include "ICloneable.h"

#include "NotImplementedException.h"

#include <string>
using namespace std;

namespace System
{
	Object ICloneable::Clone()
	{
		throw NotImplementedException(Exception::ExceptionData(L""s, L""s, L""s));
	}
}