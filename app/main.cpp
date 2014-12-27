#include <iostream>
#include <myclass.h>
#include <nodes/node.h>
#include <nodes/elementnode.h>
#include <nodes/textnode.h>
#include <QApplication>

#include "mainwindow.h"
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //todo real parsing
    ElementNode root("html");
    ElementNode body("body");
    TextNode text("Hello World");
    TextNode text2("foo bar");
    body.addChildNode(text);
    body.addChildNode(text2);
    root.addChildNode(body);

    root.prettyPrint();
//    cout << adder.addition(10, 20) << endl;
    MainWindow w;
    w.show();

    return a.exec();
}
