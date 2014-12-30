#ifndef DOCUMENT_H
#define DOCUMENT_H
#include "parser/stylesheet.h"
#include "nodes/node.h"
#include "nodes/elementnode.h"

class Document
{
public:
    Document(QSharedPointer<Node> dom,QSharedPointer<Stylesheet> css);
    ~Document();
    QSharedPointer<ElementNode> getElementById(QString id);
    QList<ElementNode> getElementsByClassName(QString className);

private:
    QSharedPointer<Node> m_dom;
    QSharedPointer<Stylesheet> m_css;
};

#endif // DOCUMENT_H
