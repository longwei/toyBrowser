#include "textnode.h"

TextNode::TextNode(const QString& text, const NodeVector &children):
    Node(Text, children),
    m_text(text)
{

}

TextNode::~TextNode()
{
}

void TextNode::setText(QString text){
    m_text = text;
}

QString TextNode::getText(){
    return m_text;
}


QString TextNode::toString(){
    return m_text;
}
