#ifndef CPPNET_SYSTEM_PREDICATE_HPP
#define CPPNET_SYSTEM_PREDICATE_HPP

#include <functional>
#include "Boolean.h"

namespace CppNet::System
{
	template <typename T>
	using Predicate = std::function<Boolean(const T&)>;
}

#endif