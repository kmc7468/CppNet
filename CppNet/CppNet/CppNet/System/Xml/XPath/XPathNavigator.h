#ifndef SYSTEM_XML_XPATH_XPATHNAVIGATOR_H
#define SYSTEM_XML_XPATH_XPATHNAVIGATOR_H

#include "../../../../Defines.h"

#include "../IXmlNamespaceResolver.h"
#include "../../ICloneable.h"

namespace CppNet
{
	namespace System
	{
		namespace Xml
		{
			namespace XPath
			{
				class XPathNavigator : public ICloneable, public IXPathNavigable, public XPathItem, public IXmlNamespaceResolver
				{

				};
			}
		}
	}
}

#endif