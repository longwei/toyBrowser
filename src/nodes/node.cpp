#include "node.h"
#include <iostream>

Node::Node(NodeType type, const NodeVector& children):
    m_nodetype(type),
    m_children(children)
{
}

Node::~Node()
{
    m_children.clear();
}

std::string Node::toString(){
    if(m_nodetype == Element){
        return "ELEMENT";
    } else {
        return "TEXT";
    }
}

void Node::prettyPrint(std::string prefix){
    std::cout << prefix <<toString() << std::endl;
    prefix = "-" + prefix;
    for(auto& children: m_children){
        children->prettyPrint(prefix);
    }
}

void Node::addChildNode(Node& child){
    m_children.push_back(&child);
}
