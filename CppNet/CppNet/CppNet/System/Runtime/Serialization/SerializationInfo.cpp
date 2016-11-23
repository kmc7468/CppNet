#include "SerializationInfo.h"

namespace CppNet::System::Runtime::Serialization
{
	const Int32 SerializationInfo::defaultSize = 4;

	SerializationInfo::SerializationInfo(Type* type, IFormatterConverter* converter)
		: SerializationInfo(type, converter, false)
	{}

	SerializationInfo::SerializationInfo(Type* type, IFormatterConverter* converter, Boolean requireSameTokenInPartialTrust)
	{
		if (type == nullptr)
			throw ArgumentNullException(nameof(type));
		if (converter == nullptr)
			throw ArgumentNullException(nameof(converter));

		objectType = type;
		m_fullTypeName = type->name();

		m_members = new String[defaultSize];
		m_data = new Object[defaultSize];
		m_types = (Type*)(new Byte[defaultSize * sizeof(Type)]);

		m_converter = converter;

		this->requireSameTokenInPartialTrust = requireSameTokenInPartialTrust;
	}

	String SerializationInfo::GetFullTypeName() const
	{
		return m_fullTypeName;
	}

	void SerializationInfo::SetFullTypeName(const String& value)
	{
		m_fullTypeName = value;
		isFullTypeNameSetExplicit = true;
	}

	void SerializationInfo::SetType(Type* type)
	{
		if (type == nullptr)
			throw ArgumentNullException(nameof(type));

		// TODO
	}
}