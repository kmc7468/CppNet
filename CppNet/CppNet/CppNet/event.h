#ifndef CPPNET_EVENT_H
#define CPPNET_EVENT_H

#include <vector>
#include <functional>
#include <array>

namespace CppNet
{
	template<typename R>
	struct function_traits;

	template<typename R, typename ...Args>
	struct function_traits<std::function<R(Args...)>>
	{
		static const size_t nargs = sizeof...(Args);

		typedef R result_type;

		template <size_t i>
		struct arg
		{
			typedef typename std::tuple_element<i, std::tuple<Args...>>::type type;
		};
	};

	template <typename TResult>
	class event;

	template<typename TResult, typename... TArgs>
	class event<std::function<TResult(TArgs...)>> final
	{
	private:
		mutable std::vector<std::function<TResult(TArgs...)>> functions;
		mutable std::vector<TResult> vars;

	public:
		event() = default;
		event(const event<std::function<TResult(TArgs...)>>& evt) = delete;
		event(event<std::function<TResult(TArgs...)>>&& evt) = delete;
		~event() = default;

	public:
		event<std::function<TResult(TArgs...)>>& operator=(const event<std::function<TResult(TArgs...)>>& evt) = delete;
		event<std::function<TResult(TArgs...)>>& operator=(event<std::function<TResult(TArgs...)>>&& evt) = delete;

		template<typename T>
		event<std::function<TResult(TArgs...)>>& operator+=(T func);

		template<typename T>
		event<std::function<TResult(TArgs...)>>& operator-=(T func);

		template<typename...Args>
		void operator()(Args&&... args) const;

		TResult& Result(size_t index = 0) const;
		
	public:
		typedef std::function<TResult(TArgs...)> function_type;
	};

#pragma region Æ¯¼öÈ­(void)
	template<typename... TArgs>
	class event<std::function<void(TArgs...)>> final
	{
	private:
		std::vector<std::function<void(TArgs...)>> functions;

	public:
		event() = default;
		event(const event<std::function<void(TArgs...)>>& evt) = delete;
		event(event<std::function<void(TArgs...)>>&& evt) = delete;
		~event() = default;

	public:
		event<std::function<void(TArgs...)>>& operator=(const event<std::function<void(TArgs...)>>& evt) = delete;
		event<std::function<void(TArgs...)>>& operator=(event<std::function<void(TArgs...)>>&& evt) = delete;

		template<typename T>
		event<std::function<void(TArgs...)>>& operator+=(T func);

		template<typename T>
		event<std::function<void(TArgs...)>>& operator-=(T func);

		template<typename...Args>
		void operator()(Args&&... args) const;

	public:
		typedef std::function<std::function<void(TArgs...)>> function_type;
	};
#pragma endregion
}

#include "event.inl"

#endif