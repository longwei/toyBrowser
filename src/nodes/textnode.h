#ifndef TEXTNODE_H
#define TEXTNODE_H
#include <QObject>
#include "node.h"

class TextNode : public Node
{
public:
    TextNode(const QString text = QString(),
             const NodeVector children = NodeVector());
    ~TextNode();
    virtual void setText(QString text);
    QString getText();
    virtual QString toString();

private:
    QString m_text;
};

#endif // TEXTNODE_H
