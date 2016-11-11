#ifndef CPPNET_CTR_DIV_HPP
#define CPPNET_CTR_DIV_HPP

namespace CppNet::CTR
{
	template<typename T, T x, T y>
	struct Div final
	{
		enum : T { Value = x / y };
	};
}

#endif