#ifndef RENDERNODE_H
#define RENDERNODE_H

#include <vector>
#include <string>
#include <iostream>

//this is the basic DOM node type,
class Node;
typedef std::vector<Node> NodeVector;

class Node
{
public:
    enum NodeType{
        Text = 1,
        Element = 2,
    };
    Node(NodeType type, const NodeVector& children = NodeVector() );
    virtual ~Node();
    std::string toString();



protected:
    NodeVector m_children;
    NodeType m_nodetype;
};

#endif // RENDERNODE_H
