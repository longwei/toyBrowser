#include "elementnode.h"


ElementNode::ElementNode(const QString tagName,
                         const AttributesMap attrs,
                         const NodeVector children):
    Node(Element, children),
    m_tagName(tagName),
    m_attrs(attrs)
{


}

ElementNode::~ElementNode()
{

}

QString ElementNode::toString(){
    return m_tagName;
}
