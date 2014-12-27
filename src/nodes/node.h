#ifndef RENDERNODE_H
#define RENDERNODE_H

#include <vector>
#include <string>
#include <iostream>

class Node;
//use pointer as I need virtual behavior;
typedef std::vector<Node*> NodeVector;

class Node
{
public:
    enum NodeType{
        Text = 1,
        Element = 2,
    };
    Node(NodeType type, const NodeVector& children = NodeVector() );
    virtual ~Node();
    virtual void addChildNode(Node& child);
    virtual void prettyPrint(std::string prefix = std::string());
    virtual std::string toString();



protected:
    NodeVector m_children;
    NodeType m_nodetype;
};

#endif // RENDERNODE_H
