#ifndef TESTA_H
#define TESTA_H

#include <QObject>
#include <QtTest/QtTest>

class TestQString: public QObject
{
    Q_OBJECT
private slots:
    void toUpper();
};
#endif // TESTA_H
