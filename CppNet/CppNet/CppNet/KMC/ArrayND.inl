#include "ArrayND.hpp"

namespace CppNet::KMC
{
	template<typename T, size_t... sizes>
	const std::vector<size_t> ArrayND<T, sizes...>::Arguments = { sizes... };
}