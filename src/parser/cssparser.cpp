#include "cssparser.h"
#include <QDebug>

#define CSS_DEBUG

CSSParser::CSSParser(QString input):
    Parser(input)
{

}

CSSParser::~CSSParser()
{

}

QSharedPointer<Stylesheet> CSSParser::parse(){
//    Stylesheet stylesheet(parseRules());
    return QSharedPointer<Stylesheet>(new Stylesheet(parseRules()));
}

QVector<Rule> CSSParser::parseRules(){
#ifdef CSS_DEBUG
    qDebug() << Q_FUNC_INFO;
#endif /* CSS_DEBUG */
    QVector<Rule> rules;
    while(!eof()){
        consumeWhitespaceOrNewline();
        rules.append(parseRule());
        consumeWhitespaceOrNewline();
    }
    //QVector is implicit sharing
    return rules;
}

//h1, div.note, #hahah { margin: auto; color: #cc0000; }
Rule CSSParser::parseRule(){
#ifdef CSS_DEBUG
    qDebug() << Q_FUNC_INFO;
#endif /* CSS_DEBUG */
    Rule rule{parseSimpleSelectors(), parseDeclarations()};
    return rule;
}

QVector<SimpleSelector> CSSParser::parseSimpleSelectors(){
    QVector<SimpleSelector> selectors;
    while (true) {
        consumeWhitespaceOrNewline();
        selectors.append(parseSimpleSelector());
        consumeWhitespaceOrNewline();
        QChar c = peekChar();
        if (c == ',') {
            consumeChar();
        } else if (c == '{') {
            break;
        } else {
            qDebug() << "Illegal character in selector list";
        }
    }
    return selectors;

}

// Parse one simple selector, e.g.: `type#id.class1.class2.class3`
SimpleSelector CSSParser::parseSimpleSelector(){
    QString tagName;
    QString id;
    QVector<QString> classes;
    if(!eof()){
        QChar c = peekChar();
        if(c == '#'){
            consumeChar('#');
            id = parseIdentifier();
            qDebug() << "#";
        } else if(c == '.') {
            consumeChar('.');
            classes.append(parseIdentifier());
            qDebug() << ".";
        } else if(c == '*'){
            consumeChar('*');//TODO
            qDebug() << "*";
        } else if(isVaidIdentifier(c)){
            //h1 div.note
            tagName = parseIdentifier();
        }
    }
    SimpleSelector ret{tagName, id, classes};
#ifdef CSS_DEBUG
    qDebug() << Q_FUNC_INFO;
#endif /* CSS_DEBUG */
    return ret;

}

//{ margin: auto; color: #cc0000; }
QVector<Declaration> CSSParser::parseDeclarations(){
    consumeChar('{');
    QVector<Declaration> declarations;
    //    while(peekChar() != '}'){
    //        declarations.append(parseDeclaration());
    //    }

    while (true) {
        consumeWhitespaceOrNewline();
        if (peekChar() == '}') {
            consumeChar();
            break;
        }
        declarations.append(parseDeclaration());
    }
    return declarations;
}
//margin: auto;
Declaration CSSParser::parseDeclaration(){
#ifdef CSS_DEBUG
    qDebug() << Q_FUNC_INFO;
#endif /* CSS_DEBUG */
    QString propertyName = parseIdentifier();
    consumeWhitespaceOrNewline();
    consumeChar(':');
    consumeWhitespaceOrNewline();
    QSharedPointer<Value> value = parseValue();
    consumeWhitespaceOrNewline();
    consumeChar(';');
    Declaration ret{propertyName, value};
    return ret;
}

//auto, #000000, 78px
QSharedPointer<Value> CSSParser::parseValue(){
#ifdef CSS_DEBUG
    qDebug() << Q_FUNC_INFO;
#endif /* CSS_DEBUG */
    QChar c = peekChar();
    if (c.isDigit()) {
        return parseLength();
    } else if (c == '#') {
        return parseColor();
    } else {
//        QSharedPointer<KeywordValue> ret = QSharedPointer<KeywordValue>(new KeywordValue(parseIdentifier()));
        return QSharedPointer<KeywordValue>(new KeywordValue(parseIdentifier()));
    }
    qDebug() << Q_FUNC_INFO << "enter a dead end";

}

//123px
QSharedPointer<LengthValue> CSSParser::parseLength(){
#ifdef CSS_DEBUG
    qDebug() << Q_FUNC_INFO;
#endif /* CSS_DEBUG */
    return QSharedPointer<LengthValue>(new LengthValue(parseUnit(), parserFloat()));
}

//#aabbcc
QSharedPointer<ColorValue> CSSParser::parseColor(){
#ifdef CSS_DEBUG
    qDebug() << Q_FUNC_INFO;
#endif /* CSS_DEBUG */
    consumeChar('#');
    int r = parseHexPair();
    int g = parseHexPair();
    int b = parseHexPair();
    return QSharedPointer<ColorValue>(new ColorValue(r,g,b, 255));
}

//11
int CSSParser::parseHexPair(){
#ifdef CSS_DEBUG
    qDebug() << Q_FUNC_INFO;
#endif /* CSS_DEBUG */
    QString doubledigit = consumeString(2);

    bool isdigit;
    int hexpair = doubledigit.toInt(&isdigit, 10);
    if( isdigit ){
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

