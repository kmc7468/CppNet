#ifndef CPPNET_CTR_MUL_HPP
#define CPPNET_CTR_MUL_HPP

namespace CppNet::CTR
{
	template<typename T, T x, T y>
	struct Mul final
	{
		enum : T { Value = x * y };
	};
}

#endif