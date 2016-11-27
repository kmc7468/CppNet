#ifndef CPPNET_KMC_ARRAYND_HPP
#define CPPNET_KMC_ARRAYND_HPP

#include "Array1D.hpp"
#include "Array2D.hpp"
#include "Array3D.hpp"
#include "Array4D.hpp"
#include "Array5D.hpp"

namespace CppNet::KMC
{
	template<typename T, size_t one, size_t two, size_t three, size_t four, size_t five, size_t six>
	using Array6D = Array5D<Array1D<T, six>, one, two, three, four, five>;

	template<typename T, size_t one, size_t two, size_t three, size_t four, size_t five, size_t six, size_t seven>
	using Array7D = Array5D<Array2D<T, six, seven>, one, two, three, four, five>;

	template<typename T, size_t one, size_t two, size_t three, size_t four, size_t five, size_t six, size_t seven, size_t eight>
	using Array8D = Array5D<Array3D<T, six, seven, eight>, one, two, three, four, five>;

	template<typename T, size_t one, size_t two, size_t three, size_t four, size_t five, size_t six, size_t seven, size_t eight, size_t nine>
	using Array9D = Array5D<Array4D<T, six, seven, eight, nine>, one, two, three, four, five>;

	template<typename T, size_t one, size_t two, size_t three, size_t four, size_t five, size_t six, size_t seven, size_t eight, size_t nine, size_t ten>
	using Array10D = Array5D<Array5D<T, six, seven, eight, nine, ten>, one, two, three, four, five>;
}

#endif