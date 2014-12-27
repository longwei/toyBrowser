#include "textnode.h"

TextNode::TextNode(const std::string& text, const NodeVector &children):
    Node(Text, children),
    m_text(text)
{

}

TextNode::~TextNode()
{
    //todo

}

void TextNode::setText(std::string text){
    m_text = text;
}

std::string TextNode::getText(){
    return m_text;
}


std::string TextNode::toString(){
    return m_text;
}
