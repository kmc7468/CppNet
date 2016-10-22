#include "event.h"
using namespace CppNet;

#include <algorithm>
#include "../System/Byte.h"

template<typename TResult, typename... TArgs>
template<typename... Args>
void event<TResult(TArgs...)>::operator()(Args&&... args) const
{
	bool isWriteResult = false;
	for (auto&& a : functions)
	{
		if (isWriteResult)
			a(std::forward<Args>(args)...);
		else
		{
			val = a(std::forward<Args>(args)...);
		}
	}
}

template<typename TResult, typename... TArgs>
template<typename T>
event<TResult(TArgs...)>& event<TResult(TArgs...)>::operator+=(T func)
{
	functions.push_back(function_type(func));

	return *this;
}

template<typename TResult, typename... TArgs>
template<typename T>
event<TResult(TArgs...)>& event<TResult(TArgs...)>::operator-=(T func)
{
	auto a = std::find(functions.begin(), functions.end(), del(func));

	if (a != functions.cend())
		functions.erase(a);

	return *this;
}

template<typename TResult, typename ...TArgs>
const TResult& event<TResult(TArgs...)>::Result() const
{
	return val;
}

template<typename TResult, typename ...TArgs>
TResult& event<TResult(TArgs...)>::Result()
{
	return val;
}

#pragma region Æ¯¼öÈ­(void)
template<typename... TArgs>
template<typename... Args>
void event<void(TArgs...)>::operator()(Args&&... args) const
{
	for (auto&& a : functions)
	{
		a(std::forward<Args>(args)...);
	}
}

template<typename... TArgs>
template<typename T>
event<void(TArgs...)>& event<void(TArgs...)>::operator+=(T func)
{
	functions.push_back(del(func));

	return *this;
}

template<typename... TArgs>
template<typename T>
event<void(TArgs...)>& event<void(TArgs...)>::operator-=(T func)
{
	auto a = std::find(functions.begin(), functions.end(), function_type(func));

	if (a != functions.cend())
		functions.erase(a);

	return *this;
}
#pragma endregion