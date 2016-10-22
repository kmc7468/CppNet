#include "event.h"
using namespace CppNet;

#include <algorithm>

template<typename delegate>
template<typename... Args>
void event<delegate>::operator()(Args&&... args) const
{
	for (auto a : functions)
	{
		a(std::forward<Args>(args)...);
	}
}

template<typename delegate>
template<typename T>
inline event<delegate>& CppNet::event<delegate>::operator+=(T func)
{
	functions.push_back(del(func));

	return *this;
}

template<typename delegate>
template<typename T>
inline event<delegate>& CppNet::event<delegate>::operator-=(T func)
{
	auto a = std::find(functions.begin(), functions.end(), del(func));

	if (a != functions.cend())
		functions.erase(a);

	return *this;
}