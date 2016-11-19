#include "event.h"
#include <algorithm>
#include "System/Byte.h"

namespace CppNet
{
	template<typename TResult, typename... TArgs>
	template<typename... Args>
	void event<std::function<TResult(TArgs...)>>::operator()(Args&&... args) const
	{
		vars.clear();

		for (auto&& a : functions)
		{
			auto temp = a(std::forward<Args>(args)...);
			vars.push_back(temp);
		}
	}

	template<typename TResult, typename... TArgs>
	template<typename T>
	event<std::function<TResult(TArgs...)>>& event<std::function<TResult(TArgs...)>>::operator+=(T func)
	{
		functions.push_back(func);

		return *this;
	}

	template<typename TResult, typename... TArgs>
	template<typename T>
	event<std::function<TResult(TArgs...)>>& event<std::function<TResult(TArgs...)>>::operator-=(T func)
	{
		auto a = std::find(functions.begin(), functions.end(), func);

		if (a != functions.cend())
			functions.erase(a);

		return *this;
	}

	template<typename TResult, typename ...TArgs>
	TResult& event<std::function<TResult(TArgs...)>>::Result(size_t index) const
	{
		return vars.at(index);
	}

#pragma region Æ¯¼öÈ­(void)
	template<typename... TArgs>
	template<typename... Args>
	void event<std::function<void(TArgs...)>>::operator()(Args&&... args) const
	{
		for (auto&& a : functions)
		{
			a(std::forward<Args>(args)...);
		}
	}

	template<typename... TArgs>
	template<typename T>
	event<std::function<void(TArgs...)>>& event<std::function<void(TArgs...)>>::operator+=(T func)
	{
		functions.push_back(func);

		return *this;
	}

	template<typename... TArgs>
	template<typename T>
	event<std::function<void(TArgs...)>>& event<std::function<void(TArgs...)>>::operator-=(T func)
	{
		auto a = std::find(functions.begin(), functions.end(), func);

		if (a != functions.cend())
			functions.erase(a);

		return *this;
	}
#pragma endregion
}