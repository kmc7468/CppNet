#ifndef UTILITY_H
#define UTILITY_H

#include "Defines.h"

#include "CppNet/System/Boolean.h"
#include "CppNet/event.h"

#include <type_traits>
#include <chrono>

#ifndef interface
#define interface struct
#endif

#ifndef var
#define var auto
#endif

#ifndef nameof
#define nameof(x) CppNet::System::String(#x)
#endif

#ifndef typeof
#define typeof(x) typeid(x)
#endif

#ifndef MAIN_END
#define MAIN_END system("pause");return 0;
#endif

#ifndef dref
#define dref(t) std::remove_reference<t>::type
#endif

#ifndef dcst
#define dcst(from, to_type) (*const_cast<to_type*>(&from))
#endif

#ifndef _is
#define _is(from, to_type) is<to_type>(from)
#endif

#ifndef _as
#define _as(from, to_type) as<to_type>(from)
#endif

#ifndef GET
#define GET
#endif

#ifndef SET
#define SET
#endif

#ifndef GETA
#define GETA return this->value;
#endif

#ifndef SETA
#define SETA this->value = value;
#endif

#ifndef prop
// 일반적인 프로퍼티
#define prop(type, name, getter, setter) \
class{\
private:\
type value;\
public:\
operator type() const {\
getter\
;\
}\
type& operator=(const type&value){\
setter\
;return this->value;\
}\
} name;
#endif

#ifndef props
// 초기 값이 있는 일반적인 프로퍼티
#define props(type, name, getter, setter, start) \
class{\
private:\
type value = start;\
public:\
operator type() const {\
getter\
;\
}\
type& operator=(const type&value){\
setter\
;return this->value;\
}\
} name;
#endif

#ifndef propv
// value 변수가 내장되지 않은 일반적인 프로퍼티
#define propv(type, name, getter, setter) \
class{\
public:\
operator type() const {\
getter\
;\
}\
type& operator=(const type&value){\
setter\
;return this->value;\
}\
} name;
#endif

#ifndef propg
// 읽기 전용인 프로퍼티
#define propg(type, name, getter) \
class{\
private:\
type value;\
public:\
operator type() const {\
getter\
;\
}\
} name;
#endif

#ifndef propgs
// 읽기 전용이고 초기 값이 있는 프로퍼티
#define propgs(type, name, getter, start) \
class{\
private:\
type value = start;\
public:\
operator type() const {\
getter\
;\
}\
} name;
#endif

#ifndef propgv
// value 변수가 내장되지 않고 읽기 전용인 프로퍼티
#define propgv(type, name, getter) \
class{\
public:\
operator type() const {\
getter\
;\
}\
} name;
#endif

namespace CppNet
{
	template <typename T, typename U>
	inline System::Boolean is(U& u)
	{
		/*std::is_base_of<U, T> r;

		System::Boolean result = r();

		if (result) return result;
		else
		{
			std::is_base_of<T, U> r2;

			return r2();
		}*/

		if (T* p = dynamic_cast<T*>(&u))
			return true;
		else
			return false;
	}

	template <typename T, typename U>
	inline T as(U& u)
	{
		return dynamic_cast<T>(u);
	}
}

#ifndef evnt
#define evnt(del, name) CppNet::event<del> name
#endif

#ifndef _MaxValue
#define _MaxValue(type) std::numeric_limits<type>::max()
#endif

#ifndef _MinValue
#define _MinValue(type) std::numeric_limits<type>::min()
#endif

#ifndef _CalcTime
#define _CalcTime(codes, result, result_name) std::chrono::system_clock::time_point _CalcTime_A = std::chrono::system_clock::now();\
codes; \
std::chrono::system_clock::time_point _CalcTime_B = std::chrono::system_clock::now();\
result result_name = _CalcTime_B - _CalcTime_A;
#endif

#ifndef _Default
#define _Default(type) type{}
#endif

#endif