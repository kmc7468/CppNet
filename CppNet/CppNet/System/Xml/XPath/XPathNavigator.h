#ifndef SYSTEM_XML_XPATH_XPATHNAVIGATOR_H
#define SYSTEM_XML_XPATH_XPATHNAVIGATOR_H

#include "../IXmlNamespaceResolver.h"

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

#endif