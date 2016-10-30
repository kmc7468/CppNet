#ifndef SYSTEM_TIMESPAN_H
#define SYSTEM_TIMESPAN_H

#include "../../Defines.h"

#include "UInt64.h"
#include "Int64.h"
#include "Int32.h"
#include "Boolean.h"
#include "Double.h"
#include "Object.h"
#include "IComparable.h"
#include "IEquatable.h"
#include "IFormattable.h"

namespace CppNet
{
	namespace System
	{
		class TimeSpan : public Object, public IComparable<>, public IComparable<TimeSpan>, public IEquatable<TimeSpan>/*, public IFormattable*/
		{
		public:
			static const Int64 TicksPerDay;
			static const Int64 TicksPerHour;
			static const Int64 TicksPerMillisecond;
			static const Int64 TicksPerMinute;
			static const Int64 TicksPerSecond;

			static const TimeSpan Zero;
			static const TimeSpan MaxValue;
			static const TimeSpan MinValue;

		private:
			static const Double DaysPerTick;
			static const Double HoursPerTick;
			static const Double MillisecondsPerTick;
			static const Double MinutesPerTick;
			static const Double SecondsPerTick;

			static const Int32 MillisPerSecond;
			static const Int32 MillisPerMinute;
			static const Int32 MillisPerHour;
			static const Int32 MillisPerDay;

		public:
			TimeSpan(Int32 hour, Int32 min, Int32 sec);
			TimeSpan(Int32 day, Int32 hour, Int32 min, Int32 sec);
			TimeSpan(Int32 day, Int32 hour, Int32 min, Int32 sec, Int32 mill_sec);
			TimeSpan(Int64 ticks);

		private:
			Int64 ticks = 0;

		public:
			inline Int64 Ticks() const;
			inline Int32 Days() const;
			inline Int32 Hours() const;
			inline Int32 Milliseconds() const;
			inline Int32 Minutes() const;
			inline Int32 Seconds() const;
			inline Double TotalDays() const;
			inline Double TotalHours() const;
			inline Double TotalMilliseconds() const;
			inline Double TotalMinutes() const;
			inline Double TotalSeconds() const;

		public:
			static Int32 Compare(const TimeSpan& t1, const TimeSpan& t2);
			static Boolean Equals(const TimeSpan& t1, const TimeSpan& t2);

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
			TimeSpan Add(const TimeSpan& ts) const;

			Int32 CompareTo(const Object& obj) const override;
			Int32 CompareTo(const TimeSpan& value) const override;
			Boolean Equals(const TimeSpan& value) const override;

			TimeSpan Duration() const;
			TimeSpan Negate() const;
			TimeSpan Subtract(const TimeSpan& ts) const;

		public:
			TimeSpan operator +(const TimeSpan& t) const;
			TimeSpan operator -(const TimeSpan& t) const;

			Boolean operator ==(const TimeSpan& t) const;
			Boolean operator !=(const TimeSpan& t) const;
			Boolean operator <(const TimeSpan& t) const;
			Boolean operator >(const TimeSpan& t) const;
			Boolean operator <=(const TimeSpan& t) const;
			Boolean operator >=(const TimeSpan& t) const;

		private:
			static Int64 TimeToTicks(Int32 hour, Int32 min, Int32 second);
			static TimeSpan Interval(Double value, Int32 scale);

		public:
			inline static TimeSpan FromDays(Double value);
			inline static TimeSpan FromHours(Double value);
			inline static TimeSpan FromMinutes(Double value);
			inline static TimeSpan FromSeconds(Double value);
			inline static TimeSpan FromMilliseconds(Double value);
			inline static TimeSpan FromTicks(Int64 ticks);
		};
	}
}

#include "TimeSpan.inl"

#endif