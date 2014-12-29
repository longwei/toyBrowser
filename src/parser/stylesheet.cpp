#include "stylesheet.h"
#include <QString>
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


QString SimpleSelector::toString(){
    QString classes;
//    ret.append(tagName).append()
    for(auto& oneclass: classes){
        classes.append(oneclass).append(".");
    }
    return QString("%1 %2 %3").arg(tagName).arg(id).arg(classes);
}

QString Rule::toString(){
    QString result;
    for(auto& selector: selectors){
        result.append(selector.toString());
    }
    return result;
}

QString Value::toString(){
    return m_value;
}

QString KeywordValue::toString(){
    return keyword;
}

QString LengthValue::toString(){
    return QString("Px %1").arg(length);
}

QString ColorValue::toString(){
    return QString("# %1 %2 %3 %4").arg(r).arg(g).arg(b).arg(a);
}
