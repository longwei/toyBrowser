#ifndef CSSPARSER_H
#define CSSPARSER_H
#include "parser.h"
#include "stylesheet.h"
#include <QSharedPointer>

class CSSParser : public Parser
{
public:
    CSSParser(QString input);
    ~CSSParser();


    QSharedPointer<Stylesheet> parse();
    QVector<Rule> parseRules();
    Rule parseRule();
    QVector<SimpleSelector> parseSimpleSelectors();
    SimpleSelector parseSimpleSelector();
    QVector<Declaration> parseDeclarations();
    Declaration parseDeclaration();
    Value parseValue();
    LengthValue parseLength();
    ColorValue parseColor();
    int parseHexPair();
    Unit parseUnit();
    float parserFloat();

    static bool isVaidIdentifier(QChar c);
    QString parseIdentifier();




};

#endif // CSSPARSER_H
