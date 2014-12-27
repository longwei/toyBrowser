#ifndef PARSER_H
#define PARSER_H

#include <QObject>
#include <QVector>


class Parser : public QObject
{
    Q_OBJECT
public:
    explicit Parser(QString input, QObject *parent = 0);
    ~Parser();

    QChar peekChar();
    QChar consumeChar();
    QChar consumeCharAny(QVector<QChar> expected);
    bool startsWith(const QString str);
    bool eof();

    //consume char until test if false;
    template<typename Func>
    QString consumeWhile(Func test){
        QString result = "";
        while (!eof() && test( peekChar()) ) {
            result += consumeChar();
        }
        return result;
    }

    void consumeWhitespaceOrNewline() {
//        consumeWhile(c -> c == '\n' || c == '\r');
        auto test = [] (QChar c) -> int { return c.isSpace() || c == QChar('\n') || c == QChar('\r') ;};
        consumeWhile(test);
    }

protected:
    int m_pos;
    int m_length;
    QString m_dom;
};

#endif // PARSER_H
