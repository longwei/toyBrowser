#include "stylesheet.h"
#include <QString>
#include <QDebug>
Stylesheet::Stylesheet(QVector<Rule> rules):
    m_rules(rules)
{

}

Stylesheet::~Stylesheet()
{

}

QString Stylesheet::toString(){
    QString result;
    result.append("css: \n");
    for(auto& rule: m_rules){
        result.append(rule.toString());
    }
    return result;
}
