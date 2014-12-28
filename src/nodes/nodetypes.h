#ifndef NODETYPES_H
#define NODETYPES_H
#include <QMap>
#include <QString>
#include <QList>
#include <QSharedPointer>
//all types goes here
class Node;
typedef QMap<QString, QString> AttributesMap;
typedef QList<QSharedPointer<Node> > NodeVector;
typedef QPair<QString,QString> AttrPair;

#endif // NODETYPES_H

