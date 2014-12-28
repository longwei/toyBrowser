#ifndef ELEMENTNODE_H
#define ELEMENTNODE_H

#include <QObject>

#include "nodetypes.h"
#include "node.h"

class ElementNode : public Node
{
public:  
    ElementNode(const QString tagName,
                const AttributesMap attrs = AttributesMap(),
                const NodeVector children = NodeVector(),
                QObject *parent = 0);
    ~ElementNode();
    virtual QString toString();



private:
    QString m_tagName;
    QMap<QString, QString> m_attrs;
};

#endif // ELEMENTNODE_H
