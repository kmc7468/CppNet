#include "Math.h"

#include "../../Defines.h"
#include "../../Language.h"

#include <algorithm>

namespace CppNet
{
	namespace System
	{
		const Double Math::PI = 3.14159265358979323846;
		const Double Math::E = 2.7182818284590452354;
		const Int32 Math::C = 299792458;
		const UInt64 Math::C2 = 89875517873681764ULL;

		std::vector<Int64> Math::PrimeNumbers(Int64 min, Int64 max)
		{
			if (min > max)
				throw ArgumentException();
			else if (min < 0 || max < 0)
				throw ArgumentException(TXT_INVALID_ARGUMENT_INT_MINUS);

			std::vector<Int64> v;

			std::vector<Int64> remove;

			auto isPrime = [](Int64 n) -> bool
			{
				if (n <= 1) return false;
				for (int i = 2; i * i <= n; ++i) {
					if (n % i == 0)
						return false;
				}
				return true;
			};

			for (Int64 i = min; i < max + 1; ++i)
			{
				if (i == 0 || i == 1) continue;
				else if (std::find(remove.begin(), remove.end(), i) != remove.end()) continue;

				if (!isPrime(i))
					remove.push_back(i);
				else
					v.push_back(i);

				for (Int64 j = 2; ; ++j)
				{
					Int64 n = j * i;

					if (n > max) break;
					else if (std::find(remove.begin(), remove.end(), i) != remove.end())
						remove.push_back(n);
				}
			}

			return v;
		}

		std::vector<UInt64> CppNet::System::Math::PrimeNumbers(UInt64 min, UInt64 max)
		{
			if (min > max)
				throw ArgumentException();
			else if (min < 0 || max < 0)
				throw ArgumentException(TXT_INVALID_ARGUMENT_INT_MINUS);

			std::vector<UInt64> v;

			std::vector<UInt64> remove;

			auto isPrime = [](UInt64 n) -> bool
			{
				if (n <= 1) return false;
				for (int i = 2; i * i <= n; ++i) {
					if (n % i == 0)
						return false;
				}
				return true;
			};

			for (UInt64 i = min; i < max + 1; ++i)
			{
				if (i == 0 || i == 1) continue;
				else if (std::find(remove.begin(), remove.end(), i) != remove.end()) continue;

				if (!isPrime(i))
					remove.push_back(i);
				else
					v.push_back(i);

				for (UInt64 j = 2; ; ++j)
				{
					UInt64 n = j * i;

					if (n > max) break;
					else if (std::find(remove.begin(), remove.end(), i) != remove.end())
						remove.push_back(n);
				}
			}

			return v;
		}
	}
}