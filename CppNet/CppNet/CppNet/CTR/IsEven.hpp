#ifndef CPPNET_CTR_ISEVEN_HPP
#define CPPNET_CTR_ISEVEN_HPP

namespace CppNet::CTR
{
	template<typename T, T x>
	struct IsEven final
	{
		enum : bool
		{
			Value = (x % 2 == 0)
		};
	};
}

#endif