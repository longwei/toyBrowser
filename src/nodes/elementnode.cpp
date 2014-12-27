#include "elementnode.h"


ElementNode::ElementNode(const std::string& tagName,
                         const AttributesMap &attrs,
                         const NodeVector &children):
    Node(Element, children),
    m_tagName(tagName),
    m_attrs(attrs)
{


}

ElementNode::~ElementNode()
{
    //todo

}

std::string ElementNode::toString(){
    return m_tagName;
}
