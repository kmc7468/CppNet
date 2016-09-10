#include "Utility.h"

// FIXME: hpp 파일로 분리

template <typename T, typename U>
System::Boolean is(U&& u)
{
	return std::is_base_of_v<T, U>;
}