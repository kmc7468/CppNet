#ifndef CPPNET_CTR_MULTIPOINTER_HPP
#define CPPNET_CTR_MULTIPOINTER_HPP

namespace CppNet::CTR
{
	template<typename T, size_t count>
	struct MultiPointer final
	{
		typedef typename MultiPointer<T*, count - 1>::Type Type;
	};

	template<typename T>
	struct MultiPointer<T, 0> final
	{
		typedef T Type;
	};
}

#endif