#ifndef STYLESHEET_H
#define STYLESHEET_H
#include <QList>
#include <QString>
#include <QSharedPointer>
#include <QVector>


enum Unit{
    Px,
    Undefined,
};

class Value {
public:
    virtual QString toString() = 0;
};


class KeywordValue: public Value{
public:
    KeywordValue(QString keyword);
    QString m_keyword;
    QString toString();
};

class LengthValue: public Value{
public:
    LengthValue(Unit u, float f);
    Unit m_unit;
    float m_length;
    QString toString();
};

class ColorValue: public Value{
public:
    ColorValue(int r, int g, int b, int a);
    int r;
    int g;
    int b;
    int a;
    QString toString();
};

class SimpleSelector{
public:
    QString tagName;
    QString id;
    QVector<QString> classes;
    QString toString();
};

class Declaration{
public:
    QString name;
    QSharedPointer<Value> value;
    QString toString();
};

class Rule {
public:
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
