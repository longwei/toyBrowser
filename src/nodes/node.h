#ifndef NODE_H
#define NODE_H

//#include <QObject>
#include <QEnableSharedFromThis>
#include "nodetypes.h"

class Node : public QEnableSharedFromThis<Node>
{
public:
    enum NodeType{
        Text = 1,
        Element = 2,
    };
    explicit Node(NodeType type,
                  const NodeVector children = NodeVector());
    virtual ~Node();
    virtual void addChildNode(QSharedPointer<Node> child);
    virtual void prettyPrint(QString prefix = QString());
    virtual QString toString();
    QSharedPointer<Node> self(){ return sharedFromThis(); }

protected:
    NodeVector m_children;
    NodeType m_nodetype;

};

#endif // NODE_H
