#ifndef STYLESHEET_H
#define STYLESHEET_H
#include <QList>
#include <QString>

#include <QVector>


enum Unit{
    Px,
    Undefined,
};

class Value {
public:
    virtual QString toString();
    QString m_value;
};


class KeywordValue: public Value{
public:
    QString keyword;
    QString toString();
};

class LengthValue: public Value{
public:
    Unit unit;
    float length;
    QString toString();
};

class ColorValue: public Value{
public:
    int r;
    int g;
    int b;
    int a;
    QString toString();
};

struct SimpleSelector{
    QString tagName;
    QString id;
    QVector<QString> classes;
    QString toString();
};

struct Declaration{
    QString name;
    Value value;
};

struct Rule {
    QVector<SimpleSelector> selectors;
    QVector<Declaration> declarations;
    QString toString();
};

class Stylesheet
{
public:
    Stylesheet(QVector<Rule> rules);
    ~Stylesheet();
    QString toString();

private:
    QVector<Rule> m_rules;
};



#endif // STYLESHEET_H
