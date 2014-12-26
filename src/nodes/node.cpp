#include "node.h"


Node::Node(NodeType type):
    m_nodetype(type)
{
    m_children = new NodeVector();
}

Node::Node(NodeType type, NodeVector* children):
    m_nodetype(type),
    m_children(children)
{
}

Node::~Node()
{
}

std::string Node::toString(){
    return "hello";
}

