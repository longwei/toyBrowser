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
    QSharedPointer<Node> parse();


private:
    QString parseTagName();
    QSharedPointer<TextNode> parseText();
    QSharedPointer<Node> parseNode();
    QList<QSharedPointer<Node> > parseNodes();
    QSharedPointer<ElementNode> parseElem();
    QMap<QString, QString> parseAttrs();
    QPair<QString,QString> parseAttr();
    QString parseAttrValue();





signals:

public slots:
};

#endif // DOMPARSER_H
