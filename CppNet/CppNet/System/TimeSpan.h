#ifndef SYSTEM_TIMESPAN_H
#define SYSTEM_TIMESPAN_H

#include "../Defines.h"

#include "Int64.h"
#include "Int32.h"
#include "Boolean.h"
#include "Double.h"
#include "Object.h"

namespace System
{
	class TimeSpan : public Object
	{
	public:
		static const Int64 TicksPerDay;
		static const Int64 TicksPerHour;
		static const Int64 TicksPerMillisecond;
		static const Int64 TicksPerMinute;
		static const Int64 TicksPerSecond;

	public:
		TimeSpan(Int32 hour, Int32 min, Int32 sec);
		TimeSpan(Int32 day, Int32 hour, Int32 min, Int32 sec);
		TimeSpan(Int32 day, Int32 hour, Int32 min, Int32 sec, Int32 mill_sec);
		TimeSpan(Int64 ticks);

	private:
		Int32 day = 0;
		Int32 hour = 0;
		Int32 min = 0;
		Int32 sec = 0;
		Int32 mill_sec = 0;

	public:
		// TODO: 
		/*int Days{ get; }
		int Hours{ get; }
		int Milliseconds{ get; }
		int Minutes{ get; }
		int Seconds{ get; }
		long Ticks{ get; }
		double TotalDays{ get; }
		double TotalHours{ get; }
		double TotalMilliseconds{ get; }
		double TotalMinutes{ get; }
		double TotalSeconds{ get; }*/

	public:
		static Int32 Compare(const TimeSpan& t1, const TimeSpan& t2);

		static Boolean Equals(const TimeSpan& t1, const TimeSpan& t2);

		static TimeSpan FromDays(Double value);
		static TimeSpan FromHours(Double value);
		static TimeSpan FromMilliseconds(Double value);
		static TimeSpan FromMinutes(Double value);
		static TimeSpan FromSeconds(Double value);
		static TimeSpan FromTicks(Int64 value);

		//TODO: static TimeSpan Parse(const String& s);
		//TODO: static TimeSpan Parse(String input, IFormatProvider formatProvider);
		//TODO: static TimeSpan ParseExact(String input, String[] formats, IFormatProvider formatProvider);
		//TODO: static TimeSpan ParseExact(String input, String format, IFormatProvider formatProvider);
		//TODO: static TimeSpan ParseExact(String input, String format, IFormatProvider formatProvider, TimeSpanStyles styles);
		//TODO: static TimeSpan ParseExact(String input, String[] formats, IFormatProvider formatProvider, TimeSpanStyles styles);
		//TODO: static Boolean TryParse(const String& s, TimeSpan& result);
		//TODO: static Bool TryParse(String input, IFormatProvider formatProvider, out TimeSpan result);
		//TODO: static Bool TryParseExact(String input, String format, IFormatProvider formatProvider, out TimeSpan result);
		//TODO: static Bool TryParseExact(String input, String[] formats, IFormatProvider formatProvider, out TimeSpan result);
		//TODO: static Bool TryParseExact(String input, String format, IFormatProvider formatProvider, TimeSpanStyles styles, out TimeSpan result);
		//TODO: static Bool TryParseExact(String input, String[] formats, IFormatProvider formatProvider, TimeSpanStyles styles, out TimeSpan result);
		//TODO: TimeSpan Add(const TimeSpan& ts);
		//TODO: Int32 CompareTo(Object value);

		Int32 CompareTo(const TimeSpan& value);

		TimeSpan Duration();

		//TODO: override bool Equals(object value);
		//TODO: bool Equals(const TimeSpan& obj);
		//TODO: override int GetHashCode();

		TimeSpan Negate();

		//TODO: TimeSpan Subtract(const TimeSpan& ts)

	public:
		//TODO: TimeSpan operator +(const TimeSpan& t);
		//TODO: TimeSpan operator -(const TimeSpan& t);

		Boolean operator ==(const TimeSpan& t);
		Boolean operator !=(const TimeSpan& t);
		Boolean operator <(const TimeSpan& t);
		Boolean operator >(const TimeSpan& t);
		Boolean operator <=(const TimeSpan& t);
		Boolean operator >=(const TimeSpan& t);
	};
}

#endif