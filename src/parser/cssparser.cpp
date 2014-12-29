#include "cssparser.h"
#include <QDebug>

CSSParser::CSSParser(QString input):
    Parser(input)
{

}

CSSParser::~CSSParser()
{

}

QSharedPointer<Stylesheet> CSSParser::parse(){
    QSharedPointer<Stylesheet> stylesheet(new Stylesheet(parseRules()));
    return stylesheet;
}

QVector<Rule> CSSParser::parseRules(){
    QVector<Rule> rules;
    while(!eof()){
        consumeWhitespaceOrNewline();
        rules.append(parseRule());
    }
    //QVector is implicit sharing
    return rules;
}

//h1, div.note, #hahah { margin: auto; color: #cc0000; }
Rule CSSParser::parseRule(){
    Rule rule{parseSimpleSelectors(), parseDeclarations()};
    return rule;
}

QVector<SimpleSelector> CSSParser::parseSimpleSelectors(){
    QVector<SimpleSelector> selectors;
    while(peekChar() != '{'){
        consumeWhitespaceOrNewline();
        selectors.append(parseSimpleSelector());
        consumeWhitespaceOrNewline();
        consumeChar(',');
    }
    return selectors;

}

//h1, #hahah, *, .div
SimpleSelector CSSParser::parseSimpleSelector(){
    QString tagName;
    QString id;
    QVector<QString> classes;
    while(!eof()){
        QChar c = peekChar();
        if(c == '#'){
            consumeChar();
            id = parseIdentifier();
        } else if(c == '.') {
            consumeChar();
            classes.append(parseIdentifier());
        } else if(c == '*'){
            consumeChar();//TODO
        } else if(isVaidIdentifier(c)){
            //h1 div.note
            tagName = parseIdentifier();
        }
    }
    SimpleSelector ret{tagName, id, classes};
    return ret;

}

//{ margin: auto; color: #cc0000; }
QVector<Declaration> CSSParser::parseDeclarations(){
    consumeChar('{');
    QVector<Declaration> declarations;
    while(peekChar() != '}'){
        declarations.append(parseDeclaration());
    }
    consumeChar('}');
    return declarations;
}
//margin: auto;
Declaration CSSParser::parseDeclaration(){
    QString propertyName = parseIdentifier();
    consumeWhitespaceOrNewline();
    consumeChar(':');
    consumeWhitespaceOrNewline();
    Value value = parseValue();
    consumeWhitespaceOrNewline();
    consumeChar(';');
    Declaration ret{propertyName, value};
    return ret;
}

//auto, #cc0000, 78px
Value CSSParser::parseValue(){
    QChar c = peekChar();
    if (c.isDigit()) {
        return parseLength();
    } else if (c == '#') {
        return parseColor();
    } else {
        KeywordValue keyword;
        keyword.keyword = parseIdentifier();
        return keyword;
    }
    qDebug() << Q_FUNC_INFO;

}

//123px
LengthValue CSSParser::parseLength(){
    float x = parserFloat();
    Unit u = parseUnit();
    LengthValue ret;
    ret.length = x;
    ret.unit = u;
    return ret;
}

//#aabbcc
ColorValue CSSParser::parseColor(){
    consumeChar('#');
    ColorValue ret;
    int r = parseHexPair();
    int g = parseHexPair();
    int b = parseHexPair();
    ret.r = r;
    ret.g = g;
    ret.b = b;
    ret.a = 255;
    return ret;
}

//11
int CSSParser::parseHexPair(){
    QString doubledigit = consumeString(2);
    bool isdigit;
    int hexpair = doubledigit.toInt(&isdigit, 10);
    if(isdigit){
        return hexpair;
    } else {
        qDebug() << "not a valid double digit" << doubledigit;
        return -1;
    }

}

Unit CSSParser::parseUnit(){
    QString u = parseIdentifier().toLower();
    if (u == "px") {
        return Unit::Px;
    } else {
        qDebug() << "Unrecognized unit";
        return Unit::Undefined;
    }
}


float CSSParser::parserFloat(){
    auto isfloatTest = [] (QChar c) -> bool { return c.isDigit() || c== '.';};
    QString floatstring = consumeWhile(isfloatTest);
    bool isFloat;
    float ret = floatstring.toFloat(&isFloat);
    return ret;
}

bool CSSParser::isVaidIdentifier(QChar c){
    return (c.isLetterOrNumber() || c == '-' || c== '_');
}

QString CSSParser::parseIdentifier(){
    QString ret = consumeWhile(isVaidIdentifier);
    return ret;
}

