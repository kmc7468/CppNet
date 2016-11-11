#ifndef CPPNET_CTR_SUB_HPP
#define CPPNET_CTR_SUB_HPP

namespace CppNet::CTR
{
	template<typename T, T x, T y>
	struct Sub final
	{
		enum : T { Value = x - y };
	};
}

#endif