#include "Property.h"
using namespace CppNet;

template<typename T>
Property<T>::Property(std::function<T&(void)> getter, std::function<void(const T&)> setter)
{
	this->getter = getter;
	this->setter = setter;
}

template<typename T>
Property<T>& Property<T>::operator=(const T& value)
{
	setter(value);

	return *this;
}

template<typename T>
Property<T>::operator T&()
{
	return getter();
}

template<typename T>
PropertyR<T>::PropertyR(std::function<T&(void)> getter)
{
	this->getter = getter;
}

template<typename T>
PropertyR<T>::operator T&()
{
	return getter();
}