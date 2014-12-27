#include "node.h"

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
    return "hello";
}

