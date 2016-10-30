#include "TimeSpan.h"

#include "DoubleT.h"
#include "ArgumentException.h"

namespace CppNet
{
	namespace System
	{
		const Int64 TimeSpan::TicksPerDay = 864000000000;
		const Int64 TimeSpan::TicksPerHour = 36000000000;
		const Int64 TimeSpan::TicksPerMillisecond = 10000;
		const Int64 TimeSpan::TicksPerMinute = 600000000;
		const Int64 TimeSpan::TicksPerSecond = 10000000;

		const TimeSpan TimeSpan::Zero = TimeSpan(0);
		const TimeSpan TimeSpan::MaxValue = TimeSpan(_MaxValue(Int64));
		const TimeSpan TimeSpan::MinValue = TimeSpan(_MinValue(Int64));

		const Double TimeSpan::DaysPerTick = 1.0 / TimeSpan::TicksPerDay;
		const Double TimeSpan::HoursPerTick = 1.0 / TimeSpan::TicksPerHour;
		const Double TimeSpan::MillisecondsPerTick = 1.0 / TimeSpan::TicksPerMillisecond;
		const Double TimeSpan::MinutesPerTick = 1.0 / TimeSpan::TicksPerMinute;
		const Double TimeSpan::SecondsPerTick = 1.0 / TimeSpan::TicksPerSecond;

		const Int32 TimeSpan::MillisPerSecond = 1000;
		const Int32 TimeSpan::MillisPerMinute = TimeSpan::MillisPerSecond * 60;
		const Int32 TimeSpan::MillisPerHour = TimeSpan::MillisPerMinute * 60;
		const Int32 TimeSpan::MillisPerDay = TimeSpan::MillisPerHour * 24;

		TimeSpan::TimeSpan(Int32 hour, Int32 min, Int32 sec)
		{
			ticks = TimeToTicks(hour, min, sec);
		}

		TimeSpan::TimeSpan(Int32 day, Int32 hour, Int32 min, Int32 sec)
			: TimeSpan(day, hour, min, sec, 0)
		{ }

		TimeSpan::TimeSpan(Int32 day, Int32 hour, Int32 min, Int32 sec, Int32 mill_sec)
		{
			Int64 totalMilliSeconds = ((Int64)day * 3600 * 24 + (Int64)hour * 3600 + (Int64)min * 60 + sec) * 1000 + mill_sec;
			ticks = (Int64)totalMilliSeconds * TicksPerMillisecond;
		}

		TimeSpan::TimeSpan(Int64 ticks)
		{
			this->ticks = ticks;
		}

		TimeSpan TimeSpan::Add(const TimeSpan& time) const
		{
			return ticks + time.ticks;
		}

		Int32 TimeSpan::Compare(const TimeSpan& t1, const TimeSpan& t2)
		{
			if (t1.ticks > t2.ticks) return 1;
			if (t1.ticks < t2.ticks) return -1;
			return 0;
		}

		Boolean TimeSpan::Equals(const TimeSpan& t1, const TimeSpan& t2)
		{
			return (Compare(t1, t2) == 0);
		}

		Int32 TimeSpan::CompareTo(const Object& obj) const
		{
			return CompareTo((const TimeSpan&)obj);
		}

		Int32 TimeSpan::CompareTo(const TimeSpan& value) const
		{
			return Compare(*this, value);
		}

		TimeSpan TimeSpan::Duration() const
		{
			return ticks >= 0 ? ticks : -ticks;
		}

		TimeSpan TimeSpan::Negate() const
		{
			return -ticks;
		}

		Boolean TimeSpan::operator==(const TimeSpan& t) const
		{
			return (CompareTo(t) == 0);
		}

		Boolean TimeSpan::operator!=(const TimeSpan& t) const
		{
			return (CompareTo(t) != 0);
		}

		Boolean TimeSpan::operator<(const TimeSpan& t) const
		{
			return (CompareTo(t) < 0);
		}

		Boolean TimeSpan::operator>(const TimeSpan& t) const
		{
			return (CompareTo(t) > 0);
		}

		Boolean TimeSpan::operator<=(const TimeSpan& t) const
		{
			return (CompareTo(t) <= 0);
		}

		Boolean TimeSpan::operator>=(const TimeSpan& t) const
		{
			return (CompareTo(t) >= 0);
		}

		Int64 TimeSpan::TimeToTicks(Int32 hour, Int32 min, Int32 sec)
		{
			Int64 totalSeconds = (Int64)hour * 3600 + (Int64)min * 60 + (Int64)sec;
			return totalSeconds * TicksPerSecond;
		}

		Boolean TimeSpan::Equals(const TimeSpan& value) const
		{
			return this->operator==(value);
		}

		TimeSpan TimeSpan::Subtract(const TimeSpan& ts) const
		{
			return ticks - ts.ticks;
		}

		TimeSpan TimeSpan::operator+(const TimeSpan& value) const
		{
			return Add(value);
		}

		TimeSpan TimeSpan::operator-(const TimeSpan& value) const
		{
			return Subtract(value);
		}

		TimeSpan TimeSpan::Interval(Double value, Int32 scale)
		{
			if (DoubleT::IsNaN(value))
				throw ArgumentException(); // FIXME ¾ð¾î

			Double tmp = value * scale;
			Double millis = tmp + (value >= 0 ? 0.5 : -0.5);

			return TimeSpan((Int64)millis * TicksPerMillisecond);
		}
	}
}