#ifndef TESTA_H
#define TESTA_H

#include "AutoTest.h"


class TestQString: public QObject
{
    Q_OBJECT
private slots:
    void toUpper();
};

DECLARE_TEST(TestQString)

#endif // TESTA_H
