#ifndef ELEMENTNODE_H
#define ELEMENTNODE_H

#include <string>
#include <map>

#include "node.h"

class ElementNode : public Node
{
public:
    typedef std::map<std::string, std::string> AttributesMap;
    ElementNode(const std::string& tagName,
                const AttributesMap& attrs = AttributesMap(),
                const NodeVector& children = NodeVector() );
    ~ElementNode();
    virtual std::string toString();



private:
    std::string m_tagName;
    AttributesMap m_attrs;
};

#endif // ELEMENTNODE_H
