#ifndef SYSTEM_TIMESPAN_H
#define SYSTEM_TIMESPAN_H

#include "System.h"

namespace System
{
	class TimeSpan : public Object
	{
	public:
		static const Int64 TicksPerDay = 864000000000;
		static const Int64 TicksPerHour = 36000000000;
		static const Int64 TicksPerMillisecond = 10000;
		static const Int64 TicksPerMinute = 600000000;
		static const Int64 TicksPerSecond = 10000000;

	public:
		TimeSpan(Int32 hour, Int32 min, Int32 sec)
			: TimeSpan(0, hour, min, sec, 0)
		{ }

		TimeSpan(Int32 day, Int32 hour, Int32 min, Int32 sec)
			: TimeSpan(day, hour, min, sec, 0)
		{ }

		TimeSpan(Int32 day, Int32 hour, Int32 min, Int32 sec, Int32 mill_sec)
		{
			this->day = day;
			this->hour = hour;
			this->min = min;
			this->sec = sec;
			this->mill_sec = mill_sec;

			// TODO: https://msdn.microsoft.com/ko-kr/library/system.timespan.duration(v=vs.110).aspx
			//       의 예제를 참고하면 음수값인 경우 양수로 들어온 시간에 그 만큼 빼줘야 합니다.
		}

		explicit TimeSpan(Int64 ticks)
		{
			// TODO: 
		}

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
		static Int32 Compare(const TimeSpan& t1, const TimeSpan& t2)
		{
			if (t1.day < t2.day)
				return -1;
			else if (t1.day > t2.day)
				return 1;

			if (t1.hour < t2.hour)
				return -1;
			else if (t1.hour > t2.hour)
				return 1;

			if (t1.min < t2.min)
				return -1;
			else if (t1.min > t2.min)
				return 1;

			if (t1.sec < t2.sec)
				return -1;
			else if (t1.sec > t2.sec)
				return 1;

			if (t1.mill_sec < t2.mill_sec)
				return -1;
			else if (t1.mill_sec > t2.mill_sec)
				return 1;

			return 0;
		}

		static Boolean Equals(const TimeSpan& t1, const TimeSpan& t2)
		{
			return (Compare(t1, t2) == 0);
		}

		static TimeSpan FromDays(Double value)
		{
			return TimeSpan(static_cast<Int64>(value * TicksPerDay));
		}

		static TimeSpan FromHours(Double value)
		{
			return TimeSpan(static_cast<Int64>(value * TicksPerHour));
		}

		static TimeSpan FromMilliseconds(Double value)
		{
			return TimeSpan(static_cast<Int64>(value * TicksPerMillisecond));
		}

		static TimeSpan FromMinutes(Double value)
		{
			return TimeSpan(static_cast<Int64>(value * TicksPerMinute));
		}

		static TimeSpan FromSeconds(Double value)
		{
			return TimeSpan(static_cast<Int64>(value * TicksPerSecond));
		}

		static TimeSpan FromTicks(Int64 value)
		{
			return TimeSpan(value);
		}

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

		Int32 CompareTo(const TimeSpan& value)
		{
			return Compare(*this, value);
		}

		TimeSpan Duration()
		{
			// TODO: 음수 시간을 어떻게 표현할지 불분명하므로 아래 코드는 임시 조치임.
			return TimeSpan(std::abs(day), std::abs(hour), std::abs(min), std::abs(sec), std::abs(mill_sec));
		}

		//TODO: override bool Equals(object value);
		//TODO: bool Equals(const TimeSpan& obj);
		//TODO: override int GetHashCode();

		TimeSpan Negate()
		{
			// TODO: 음수 시간을 어떻게 표현할지 불분명하므로 아래 코드는 임시 조치임.
			return TimeSpan(-day, hour, min, sec, mill_sec);
		}

		//TODO: TimeSpan Subtract(const TimeSpan& ts)

	public:
		//TODO: TimeSpan operator +(const TimeSpan& t);
		//TODO: TimeSpan operator -(const TimeSpan& t);

		Boolean operator ==(const TimeSpan& t)
		{
			return (CompareTo(t) == 0);
		}

		Boolean operator !=(const TimeSpan& t)
		{
			return (CompareTo(t) != 0);
		}

		Boolean operator <(const TimeSpan& t)
		{
			return (CompareTo(t) < 0);
		}

		Boolean operator >(const TimeSpan& t)
		{
			return (CompareTo(t) > 0);
		}

		Boolean operator <=(const TimeSpan& t)
		{
			return (CompareTo(t) <= 0);
		}

		Boolean operator >=(const TimeSpan& t)
		{
			return (CompareTo(t) >= 0);
		}
	};
}

#endif