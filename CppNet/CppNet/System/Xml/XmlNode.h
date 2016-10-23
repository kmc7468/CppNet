#ifndef SYSTEM_XML_XMLNODE_H
#define SYSTEM_XML_XMLNODE_H

#include "../../Defines.h"

#include "../Object.h"
#include "../ICloneable.h"
#include "../Collections/IEnumerable.h"
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