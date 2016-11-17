#ifndef CPPNET_CTR_ISODD_HPP
#define CPPNET_CTR_ISODD_HPP

namespace CppNet::CTR
{
	template<typename T, T x>
	struct IsOdd final
	{
		enum : bool
		{
			Value = (x % 2 == 1)
		};
	};
}

#endif