#ifndef SYSTEM_XML_XMLNODE_H
#define SYSTEM_XML_XMLNODE_H

#include "XPath/IXPathNavigable.h"

namespace System
{
	namespace Xml
	{
		class XmlNode : public Object, public ICloneable, public Collections::IEnumerable, public XPath::IXPathNavigable
		{

		};
	}
}

#endif