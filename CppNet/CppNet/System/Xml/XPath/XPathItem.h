#ifndef SYSTEM_XML_XPATH_XPATHITEM_H
#define SYSTEM_XML_XPATH_XPATHITEM_H

namespace System::Xml::XPath
{
	class XPathItem : public Object
	{
	public:
		virtual Boolean IsNode() const = 0;
	};
}

#endif