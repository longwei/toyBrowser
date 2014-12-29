#include <QApplication>
#include <iostream>
#include <myclass.h>
#include <nodes/node.h>
#include <nodes/elementnode.h>
#include <nodes/textnode.h>
#include <parser/domparser.h>
#include "mainwindow.h"
//using namespace std;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    DOMParser dom("<html><body>hello world</body></html>");
//    QSharedPointer<Node> root = dom.parse();
//    root->prettyPrint();

    MainWindow w;
    w.show();

    return a.exec();
}

