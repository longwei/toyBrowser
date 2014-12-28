#ifndef DOMPARSER_H
#define DOMPARSER_H

#include <QObject>
#include <QMap>
#include <QList>
#include "parser.h"
#include "nodes/node.h"
#include "nodes/textnode.h"
#include "nodes/elementnode.h"

class DOMParser : public Parser
{
    Q_OBJECT
public:
    explicit DOMParser(QString input, QObject *parent = 0);
    ~DOMParser();
    Node* parse();


private:
    QString parseTagName();
    TextNode* parseText();
    Node *parseNode();
    QList<Node*> parseNodes();
    ElementNode* parseElem();
    QMap<QString, QString> parseAttrs();
    QPair<QString,QString> parseAttr();
    QString parseAttrValue();





signals:

public slots:
};

#endif // DOMPARSER_H
