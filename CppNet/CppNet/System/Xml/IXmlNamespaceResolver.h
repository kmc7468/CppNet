#ifndef SYSTEM_XML_IXMLNAMESPACERESOLVER_H
#define SYSTEM_XML_IXMLNAMESPACERESOLVER_H

#include "XmlNamespaceScope.h"

namespace System
{
	namespace Xml
	{
		interface IXmlNamespaceResolver
		{
			virtual Collections::Generic::IDictionary<String, String> GetNamespacesInScope(XmlNamespaceScope scope) const = 0;
			virtual String LookupNamespace(const String& prefix) const = 0;
			virtual String LookupPrefix(const String& namespaceName) const = 0;
		};
	}
}

#endif