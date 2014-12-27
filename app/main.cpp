#include <QApplication>
#include <iostream>
#include <myclass.h>
#include <nodes/node.h>
#include <nodes/elementnode.h>
#include <nodes/textnode.h>

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

    Node* doc = (Node*)&root;
    doc->prettyPrint();

    MainWindow w;
    w.show();

    return a.exec();
}

