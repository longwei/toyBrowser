#include "testparser.h"
#include <parser/parser.h>
#include <parser/domparser.h>
#include <parser/cssparser.h>
#include <parser/stylesheet.h>
#include <functional>
#include <QDebug>

void TestParser::toUpper() {
    Parser parser("<a>foo</a>");
    QVERIFY( parser.startsWith("<a>") == true);
    parser.consumeChar();
    QVERIFY( parser.consumeChar() == QChar('a'));
    QVERIFY( parser.peekChar() == QChar('>'));
    QVERIFY( parser.startsWith(">") == true);
}


bool isAorB(QChar input) {return input== 'a' || input== 'b';}
void TestParser::lambda(){
    auto ret1 = [] (int x, int y) -> int { return x+ y; };
    QVERIFY( ret1(1, 2) == 3);
    auto test = [] (char input) -> bool { return input=='a' || input=='b'; };
    QVERIFY( test('a') == true);
    QVERIFY( test('b') == true);
    QVERIFY( test('c') == false);

    //lambda
    Parser parser2("ababcab");
    auto lambda = [] (QChar input) -> bool { return input== 'a' || input== 'b'; };
    QVERIFY(parser2.consumeWhile(lambda) == "abab");

    //fuctor
    Parser parser3("ababcab");
    std::function<bool(QChar)> functor = isAorB;
    QVERIFY(parser3.consumeWhile(functor) == "abab");

    //function pointer
    Parser parser4("ababcab");
    QVERIFY(parser4.consumeWhile(&isAorB) == "abab");

    Parser parser5("\t\n\r     abcdefg");
    parser5.consumeWhitespaceOrNewline();
    QVERIFY( parser5.startsWith("abcdefg") == true);
}


void TestParser::domParse(){
    DOMParser dom("<html><body>hello world</body></html>");
    QSharedPointer<Node> root = dom.parse();
    root->prettyPrint();
}

void TestParser::cssParse(){
//    QString input = "h1, h2, h3 { margin: auto; color: #cc0000; }";
//    qDebug() << "***";
//    CSSParser cssdom(input);
//    qDebug() << "***";
//    Stylesheet x = cssdom.parse();
//    qDebug() << "parsefinished";
//    qDebug() << x.toString();

}
