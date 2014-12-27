#include "elementnode.h"


ElementNode::ElementNode(const std::string& tagName,
                         const AttributesMap &attrs,
                         const NodeVector &children):
    m_tagName(tagName),
    m_attrs(attrs),
    Node(Element, children)
{


}

ElementNode::~ElementNode()
{

}

