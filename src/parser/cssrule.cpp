#include "cssrule.h"

QString SimpleSelector::toString(){
    QString classes;
//    ret.append(tagName).append()
    for(auto& oneclass: classes){
        classes.append(oneclass).append(".");
    }
    QString ret;
//    ret.append(tagName).append(id).append(classes);
    ret = QString("%1 %2 %3").arg(tagName).arg(id).arg(classes);
    return ret;
}

QString Rule::toString(){
    QString result;
    for(auto& selector: selectors){
        result.append(selector.toString());
    }
    result.append(" -- ");
    for(auto& declaration: declarations){
        result.append(declaration.toString());
    }
    return result;
}


QString Declaration::toString(){
    return QString("%1 : %2 ").arg(name).arg(value->toString());
}

KeywordValue::KeywordValue(QString keyword):
    m_keyword(keyword)
{
}

QString KeywordValue::toString(){
    return m_keyword;
}

LengthValue::LengthValue(Unit u, float f):
    m_unit(u), m_length(f)
{
}



QString LengthValue::toString(){
    return QString("Px %1").arg(m_length);
}

ColorValue::ColorValue(int r, int g, int b, int a):
    r(r),g(g),b(b),a(a)
{
}

QString ColorValue::toString(){
    return QString("# %1 %2 %3 %4").arg(r).arg(g).arg(b).arg(a);
}

