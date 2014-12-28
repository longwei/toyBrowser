#ifndef NODE_H
#define NODE_H

#include <QObject>

#include "nodetypes.h"

class Node : public QObject
{
    Q_OBJECT
public:
    enum NodeType{
        Text = 1,
        Element = 2,
    };
    explicit Node(NodeType type,
                  const NodeVector children = NodeVector(),
                  QObject *parent = 0);
    virtual ~Node();
    virtual void addChildNode(QSharedPointer<Node> child);
    virtual void prettyPrint(QString prefix = QString());
    virtual QString toString();

protected:
    NodeVector m_children;
    NodeType m_nodetype;

};

#endif // NODE_H
