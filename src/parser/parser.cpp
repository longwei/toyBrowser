#include "parser.h"
#include <QDebug>

Parser::Parser(QString input, QObject *parent):
    QObject(parent),
    m_dom(input),
    m_pos(0)
{
    m_length = m_dom.size();
}

Parser::~Parser()
{

}


QChar Parser::peekChar(){
    return m_dom.at(m_pos);
}

QChar Parser::consumeChar(){
    return m_dom.at(m_pos++);
}

QChar Parser::consumeCharAny(QVector<QChar> expected){
    QChar actual = consumeChar();
    for(QChar c: expected) {
        if(actual == c){
            return actual;
        }
    }
    qDebug() << actual << " is not expected";
    return QChar();
}

bool Parser::startsWith(const QString str){
    QStringRef subString(&m_dom, m_pos, m_length-m_pos);
    return subString.startsWith(str);
}

bool Parser::eof(){
    return m_pos >= m_length;
}

//QString Parser::consumeWhile(Func fun){
//    return "test";
//}
