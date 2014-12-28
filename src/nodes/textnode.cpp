#include "textnode.h"

TextNode::TextNode(const QString text, const NodeVector children, QObject *parent):
    Node(Text, children, parent),
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
