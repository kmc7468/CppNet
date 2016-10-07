#ifndef SYSTEM_COLLECTIONS_GENERIC_IENUMERABLE_H
#define SYSTEM_COLLECTIONS_GENERIC_IENUMERABLE_H

#include "../../../Defines.h"

#include <memory>

#include "../../System.h"
#include "IEnumerator.h"

namespace System
{
	namespace Collections
	{
		namespace Generic
		{
			//이 경우 여기서는 GetEnumerator 함수를 재정의하는 것이 불가능하므로
			//아예 다른 클래스로 분리했습니다 (여기서의 상속은 의미가 없다고 판단)

			template <typename T>
			interface IEnumerable
			{
				virtual std::unique_ptr<IEnumerator<T>> GetEnumerator() = 0;
			};
		}
	}
}

#endif