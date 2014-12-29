#ifndef STYLESHEET_H
#define STYLESHEET_H
#include <QList>
#include <QString>

#include <QVector>


enum Unit{
    Px,
    Undefined,
};

struct Value {
//    virtual QString toString();
};


struct KeywordValue: Value{
    QString keyword;
//    QString toString();
};

struct LengthValue: Value{
    Unit unit;
    float length;
//    QString toString();
};

struct ColorValue: Value{
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
};

struct Declaration{
    QString name;
    Value value;
};

struct Rule {
    QVector<SimpleSelector> selector;
    QVector<Declaration> declaration;
};

class Stylesheet
{
public:
    Stylesheet(QVector<Rule> rules);
    ~Stylesheet();

private:
    QVector<Rule> m_rules;
};



#endif // STYLESHEET_H
