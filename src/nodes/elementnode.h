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
                const NodeVector children = NodeVector());
    ~ElementNode();
    virtual QString toString();
    QSharedPointer<ElementNode> getElementById(QString id);
    QList<ElementNode> getElementsByClassName(QStringList className);



private:
    QString m_tagName;
    QMap<QString, QString> m_attrs;
};

#endif // ELEMENTNODE_H
