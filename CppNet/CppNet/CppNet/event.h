#ifndef CPPNET_EVENT_H
#define CPPNET_EVENT_H

#include <vector>

namespace CppNet
{
	template<typename delegate>
	class event final
	{
	private:
		std::vector<delegate> functions;

	public:
		event() = default;
		event(const event<delegate>& evt) = delete;
		event(event<delegate>&& evt) = delete;
		~event() = default;

	public:
		event<delegate>& operator=(const event<delegate>& evt) = delete;
		event<delegate>& operator=(event<delegate>&& evt) = delete;

		template<typename T>
		event<delegate>& operator+=(T func);

		template<typename T>
		event<delegate>& operator-=(T func);

		template<typename...Args>
		void operator()(Args&&... args) const;

	public:
		typedef delegate del;
	};
}

#include "event.inl"

#endif