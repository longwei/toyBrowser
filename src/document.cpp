#include "document.h"

Document::Document(QSharedPointer<Node> dom, QSharedPointer<Stylesheet> css):
    m_dom(dom),m_css(css)
{

}

Document::~Document()
{

}



QSharedPointer<ElementNode> Document::getElementById(QString id){

}

QList<ElementNode> Document::getElementsByClassName(QString className){

}
