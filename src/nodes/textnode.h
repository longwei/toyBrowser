#ifndef TEXTNODE_H
#define TEXTNODE_H
#include <string>
#include "node.h"

class TextNode : public Node
{
public:
    TextNode(const std::string& text = std::string(), const NodeVector& children = NodeVector());
    ~TextNode();
    virtual void setText(std::string text);
    std::string getText();
    virtual std::string toString();

private:
    std::string m_text;
};

#endif // TEXTNODE_H
