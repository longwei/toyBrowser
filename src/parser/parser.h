#ifndef PARSER_H
#define PARSER_H

#include <QObject>

class Parser : public QObject
{
    Q_OBJECT
public:
    explicit Parser(QString input, QObject *parent = 0);
    ~Parser();

    QChar peekChar();
    QChar comsumeChar();
    bool startsWith(const QString str);
    bool eof();

protected:
    int m_pos;
    int m_length;
    QString m_dom;
};

#endif // PARSER_H
