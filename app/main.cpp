#include <iostream>
#include <myclass.h>
#include <nodes/node.h>
#include <QApplication>

#include "mainwindow.h"
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyClass adder;
    Node x(Node::Text);
    cout << x.toString();
    cout << adder.addition(10, 20) << endl;
    MainWindow w;
    w.show();

    return a.exec();
}
