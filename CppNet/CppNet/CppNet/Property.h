#ifndef CPPNET_PROPERTY_H
#define CPPNET_PROPERTY_H

#include <functional>
#include "../System/Boolean.h"

namespace CppNet
{
	template<typename T>
	class Property final
	{
	private:
		std::function<T&(void)> getter;
		std::function<void(const T&)> setter;

	public:
		Property(std::function<T&(void)> getter, std::function<void(const T&)> setter);

	public:
		Property<T>& operator=(const T& value);
		operator T&();
	};

	// 읽기 전용

	template<typename T>
	class PropertyR final
	{
	private:
		std::function<T&(void)> getter;

	public:
		PropertyR(std::function<T&(void)> getter);

	public:
		operator T&();
	};
}

#include "Property.inl"

#endif