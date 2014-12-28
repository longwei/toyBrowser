#include <QDebug>

#include "node.h"

Node::Node(NodeType type, const NodeVector children, QObject *parent):
    QObject(parent),
    m_children(children),
    m_nodetype(type)
{

}


Node::~Node()
{
    //todo, replaced with shared pointer
    m_children.clear();
}

QString Node::toString(){
    if(m_nodetype == Element){
        return "ELEMENT";
    } else {
        return "TEXT";
    }
}

void Node::prettyPrint(QString prefix){
    qDebug() << toString().prepend(prefix);
    QString next_prefix = prefix.prepend("-");
    for(auto& children: m_children){
        children->prettyPrint(next_prefix);
    }
}

void Node::addChildNode(QSharedPointer<Node> child){
    m_children.push_back(child);
}
