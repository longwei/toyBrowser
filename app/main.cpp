#include <QApplication>
#include <iostream>
#include <nodes/node.h>
#include <nodes/elementnode.h>
#include <nodes/textnode.h>
#include <parser/domparser.h>
#include <parser/cssparser.h>
#include <QDebug>
#include "mainwindow.h"
//using namespace std;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    DOMParser dom("<html><body>hello world</body></html>");
//    QSharedPointer<Node> root = dom.parse();
//    root->prettyPrint();


//    QString input = "h1, h2, h3, { margin: auto; color: #123456; }";
//    CSSParser cssdom(input);
//    Stylesheet x = cssdom.parse();
//    qDebug() << x.toString();

    MainWindow w;
    w.show();

    return a.exec();
}

