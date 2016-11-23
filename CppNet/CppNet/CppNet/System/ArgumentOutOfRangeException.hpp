#ifndef CPPNET_SYSTEM_ARGUMENTOUTOFRANGEEXCEPTION_HPP
#define CPPNET_SYSTEM_ARGUMENTOUTOFRANGEEXCEPTION_HPP

#include "../../Defines.h"
#include "../../Language.h"

#include "ArgumentException.h"
#include "Runtime/Serialization/ISerializable.h"

namespace CppNet::System
{
	class ArgumentOutOfRangeException : public ArgumentException, public Runtime::Serialization::ISerializable
	{
	private:
		Object* m_actualValue = nullptr;

	public:
		ArgumentOutOfRangeException()
			: ArgumentException(TXT_INVALID_ARGUMENT_OUTOFRANGE_DEFMSG)
		{}

		ArgumentOutOfRangeException(const String& paramName)
			: ArgumentException(TXT_INVALID_ARGUMENT_OUTOFRANGE_DEFMSG, paramName)
		{}

		ArgumentOutOfRangeException(const String& paramName, const String& message)
			: ArgumentException(message, paramName)
		{}

		ArgumentOutOfRangeException(const String& message, Exception* innerException)
			: ArgumentException(message, innerException)
		{}

		ArgumentOutOfRangeException(const String& paramName, const Object& actualValue, const String& message)
			: ArgumentException(message, paramName)
		{
			m_actualValue = new Object(actualValue);
		}

		ArgumentOutOfRangeException(const ArgumentOutOfRangeException& arg)
			: ArgumentException(arg)
		{
			m_actualValue = new Object(*(arg.m_actualValue));
		}

		ArgumentOutOfRangeException(ArgumentOutOfRangeException&& arg)
			: ArgumentException(arg)
		{
			m_actualValue = arg.m_actualValue;
			arg.m_actualValue = nullptr;
		}

		~ArgumentOutOfRangeException()
		{
			if (m_actualValue)
				delete m_actualValue;
		}

		ArgumentOutOfRangeException& operator=(const ArgumentOutOfRangeException& arg)
		{
			ArgumentException::operator=(arg);

			m_actualValue = new Object(*(arg.m_actualValue));

			return *this;
		}

		ArgumentOutOfRangeException& operator=(ArgumentOutOfRangeException&& arg)
		{
			ArgumentException::operator=(arg);

			m_actualValue = arg.m_actualValue;
			arg.m_actualValue = nullptr;

			return *this;
		}

		String Message() const override
		{
			String msg = ArgumentException::Message();

			if (m_actualValue)
			{
				msg += "\n(";
				msg += m_actualValue->ToString();
				msg += ")";
			}

			return msg;
		}

	public:
		virtual const Object* const ActualValue() const
		{
			return m_actualValue;
		}
	};
}

#endif