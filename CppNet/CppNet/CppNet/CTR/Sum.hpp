#ifndef CPPNET_CTR_SUM_HPP
#define CPPNET_CTR_SUM_HPP

namespace CppNet::CTR
{
	template<typename T, T x, T y>
	struct Sum final
	{
		enum : T { Value = x + y };
	};
}

#endif