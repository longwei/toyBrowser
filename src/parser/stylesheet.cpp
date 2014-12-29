#include "stylesheet.h"
#include <QString>
Stylesheet::Stylesheet(QVector<Rule> rules):
    m_rules(rules)
{

}

Stylesheet::~Stylesheet()
{

}

//QString KeywordValue::toString(){
//    return keyword;
//}

//QString LengthValue::toString(){
//    return QString("Px %1").arg(length);
//}

QString ColorValue::toString(){
    return QString("# %1 %2 %3 %4").arg(r).arg(g).arg(b).arg(a);
}
