#ifndef ELEMENTNODE_H
#define ELEMENTNODE_H

#include <QObject>

#include "node.h"

class ElementNode : public Node
{
public:
    typedef std::map<QString, QString> AttributesMap;
    ElementNode(const QString& tagName,
                const AttributesMap& attrs = AttributesMap(),
                const NodeVector& children = NodeVector() );
    ~ElementNode();
    virtual QString toString();



private:
    QString m_tagName;
    AttributesMap m_attrs;
};

#endif // ELEMENTNODE_H
