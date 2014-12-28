#include "domparser.h"

DOMParser::DOMParser(QString input, QObject *parent) : Parser(input, parent)
{

}

DOMParser::~DOMParser()
{

}


QString DOMParser::parseTagName(){
    return consumeWhile([] (QChar input) -> bool { return input.isLetterOrNumber(); });
}

TextNode *DOMParser::parseText(){
    QString textcontent = consumeWhile([] (QChar input) -> bool { return input != '<'; });
    return new TextNode(textcontent);
}

Node* DOMParser::parseNode(){
    if (startsWith("<")){
        return parseElem();
    } else {
        return parseText();
    }
}

QList<Node*> DOMParser::parseNodes(){
    QList<Node*> nodes;
    while( !eof() && !startsWith("</")){
        consumeWhitespaceOrNewline();
        nodes.append(parseNode());
        consumeWhitespaceOrNewline();
    }
    return nodes;
}

ElementNode* DOMParser::parseElem(){
    //open tag
    consumeChar('<');
    QString tagName = parseTagName();
    QMap<QString, QString> attrs = parseAttrs();
    consumeChar('>');
    //contents
    QList<Node*> children = parseNodes();

    //closing tag
    consumeChar('<');
    consumeChar('/');
    QString closeTagName = parseTagName();;
    Q_ASSERT(closeTagName == tagName);

    consumeChar('>');
    ElementNode* ret= new ElementNode(tagName, attrs, children);
    return ret;
}

QMap<QString, QString> DOMParser::parseAttrs(){
    QMap<QString, QString> attrs;
    while (peekChar() != '>') {
        consumeWhitespaceOrNewline();
        QPair<QString, QString> a = parseAttr();
        attrs.insertMulti(a.first, a.second);
        consumeWhitespaceOrNewline();
    }
    return attrs;
}
QPair<QString,QString> DOMParser::parseAttr(){
    //foo = "bar"
    QString name = parseTagName();
    consumeWhitespaceOrNewline();
    consumeChar('=');
    consumeWhitespaceOrNewline();
    //attribute value
    QString value = parseAttrValue();
    QPair<QString, QString> ret(name, value);
    return ret;
}

QString DOMParser::parseAttrValue() {
    QVector<QChar> openquotes(2);
    openquotes.append('\'');
    openquotes.append('"');
    QChar openQuote = consumeCharAny(openquotes);
    auto test = [openQuote] (QChar c) -> bool { return c != openQuote;};
    QString value = consumeWhile(test);
    consumeChar(openQuote);
    return value;
}


Node* DOMParser::parse(){
    QList<Node*> nodes = parseNodes();

    if (nodes.size() == 1) {
        return nodes.at(0);
    } else {
        return new ElementNode("html", QMap<QString, QString>(), nodes);
    }

}

