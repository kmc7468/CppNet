#ifndef CPPNET_EVENT_H
#define CPPNET_EVENT_H

#include <vector>
#include <functional>

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
	class event<TResult(TArgs...)> final
	{
	private:
		std::vector<std::function<TResult(TArgs...)>> functions;
		TResult val{};

	public:
		event() = default;
		event(const event<TResult(TArgs...)>& evt) = delete;
		event(event<TResult(TArgs...)>&& evt) = delete;
		~event() = default;

	public:
		event<TResult(TArgs...)>& operator=(const event<TResult(TArgs...)>& evt) = delete;
		event<TResult(TArgs...)>& operator=(event<TResult(TArgs...)>&& evt) = delete;

		template<typename T>
		event<TResult(TArgs...)>& operator+=(T func);

		template<typename T>
		event<TResult(TArgs...)>& operator-=(T func);

		template<typename...Args>
		void operator()(Args&&... args) const;

		const TResult& Result() const;
		TResult& Result();
		
	public:
		typedef std::function<TResult(TArgs...)> function_type;
	};

#pragma region Æ¯¼öÈ­(void)
	template<typename... TArgs>
	class event<void(TArgs...)> final
	{
	private:
		std::vector<std::function<void(TArgs...)>> functions;

	public:
		event() = default;
		event(const event<void(TArgs...)>& evt) = delete;
		event(event<void(TArgs...)>&& evt) = delete;
		~event() = default;

	public:
		event<void(TArgs...)>& operator=(const event<void(TArgs...)>& evt) = delete;
		event<void(TArgs...)>& operator=(event<void(TArgs...)>&& evt) = delete;

		template<typename T>
		event<void(TArgs...)>& operator+=(T func);

		template<typename T>
		event<void(TArgs...)>& operator-=(T func);

		template<typename...Args>
		void operator()(Args&&... args) const;

	public:
		typedef std::function<void(TArgs...)> function_type;
	};
#pragma endregion
}

#include "event.inl"

#endif