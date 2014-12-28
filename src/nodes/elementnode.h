#ifndef ELEMENTNODE_H
#define ELEMENTNODE_H

#include <QObject>
#include <QMap>
#include "nodetypes.h"

#include "node.h"

class ElementNode : public Node
{
public:
//    typedef QMap<QString, QString> AttributesMap;
    ElementNode(const QString& tagName,
                const QMap<QString, QString>& attrs = QMap<QString, QString>(),
                const NodeVector& children = NodeVector() );
    ~ElementNode();
    virtual QString toString();



private:
    QString m_tagName;
    QMap<QString, QString> m_attrs;
};

#endif // ELEMENTNODE_H
