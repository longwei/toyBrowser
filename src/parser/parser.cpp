#include "parser.h"
#include <QDebug>
#include <QStringRef>

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

QString Parser::consumeString(int offset){
    QStringRef subString(&m_dom, m_pos, offset);
    m_pos += offset;
    return subString.toString();
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

void Parser::consumeWhitespaceOrNewline(){
    auto test = [] (QChar c) -> bool { return c.isSpace() || c == QChar('\n') || c == QChar('\r') ;};
    consumeWhile(test);
}


QChar Parser::consumeChar(QChar expected) {
    QChar actual = consumeChar();

    if (actual != expected) {
        qDebug() << QString("Got %1, expected %2.").arg(actual).arg(expected);
    }
    return actual;
}

QString Parser::consumeString(QString expected) {
    QString actual = "";

    for (int i = 0; i < expected.length(); i++) {
        actual += consumeChar(expected.at(i));

    }

    return actual;
}
