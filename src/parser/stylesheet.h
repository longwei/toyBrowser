#ifndef STYLESHEET_H
#define STYLESHEET_H
#include <QString>
#include <QSharedPointer>
#include <QVector>
#include "cssrule.h"
#include "nodes/node.h"

class Stylesheet
{
public:
    Stylesheet(QVector<Rule> rules);
    ~Stylesheet();
    QString toString();

private:
    QVector<Rule> m_rules;
    QSharedPointer<Node> domRoot;
};



#endif // STYLESHEET_H
