#ifndef CPPNET_KMC_DYNAMICVARIABLE_HPP
#define CPPNET_KMC_DYNAMICVARIABLE_HPP

#include "../../Defines.h"
#include "../../Language.h"

#include "../System/Object.h"

#include <map>

namespace CppNet::KMC
{
	template<typename T>
	class DynamicVariable final : public System::Object
	{
	private:
		std::map<System::String, T*> vars;

	public:
		DynamicVariable() = default;
		DynamicVariable(const DynamicVariable<T>&) = delete;
		DynamicVariable(DynamicVariable<T>&&) = delete;
		~DynamicVariable()
		{
			for (std::map<System::String, T*>::iterator iter = vars.begin(); iter != vars.end(); ++iter)
			{
				delete iter->second;
			}
		}

	public:
		DynamicVariable<T>& operator=(const DynamicVariable<T>&) = delete;
		DynamicVariable<T>& operator=(DynamicVariable<T>&&) = delete;

		T& operator[](const System::String& name)
		{
			try
			{
				return *(vars.at(name));
			}
			catch (std::out_of_range& exc)
			{
				throw System::IndexOutOfRangeException();
			}
		}

		const T& operator[](const System::String& name) const
		{
			try
			{
				return *(vars.at(name));
			}
			catch (std::out_of_range& exc)
			{
				throw System::IndexOutOfRangeException();
			}
		}

		void operator+=(const System::String& name)
		{
			vars.insert(std::pair<System::String, T*>(name, new T(T{})));
		}

		void operator-=(const System::String& name)
		{
			try
			{
				vars.erase(vars.find(name));
			}
			catch (std::out_of_range& exc)
			{
				throw System::IndexOutOfRangeException();
			}
		}

	public:
		T& At(const System::String& name)
		{
			try
			{
				return *(vars.at(name));
			}
			catch (std::out_of_range& exc)
			{
				throw System::IndexOutOfRangeException();
			}
		}

		const T& At(const System::String& name) const
		{
			try
			{
				return *(vars.at(name));
			}
			catch (std::out_of_range& exc)
			{
				throw System::IndexOutOfRangeException();
			}
		}

		void Alloc(const System::String& name)
		{
			vars.insert(std::pair<System::String, T*>(name, new T(T{})));
		}

		void Alloc(const System::String& name, const T& value)
		{
			vars.insert(std::pair<System::String, T*>(name, new T(value)));
		}

		void Free(const System::String& name)
		{
			try
			{
				vars.erase(vars.find(name));
			}
			catch (std::out_of_range& exc)
			{
				throw System::IndexOutOfRangeException();
			}
		}

		void Copy(const DynamicVariable<T>& v)
		{
			for (auto iter = v.vars.begin(); iter != v.vars.end(); ++iter)
			{
				vars.insert(std::pair<System::String, T*>(iter->first, new T(*(iter->second))));
			}
		}

		void Move(DynamicVariable<T>& v)
		{
			for (std::map<System::String, T*>::iterator iter = v.vars.begin(); iter != v.vars.end(); ++iter)
			{
				vars.insert(std::pair<System::String, T*>(iter->first, new T(*(iter->second))));

				delete iter->second;
			}

			v.vars.clear();
		}
	};
}

#endif