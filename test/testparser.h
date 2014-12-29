#ifndef TESTPARSER_H
#define TESTPARSER_H

#include "AutoTest.h"

class TestParser : public QObject
{
    Q_OBJECT

private slots:
    void toUpper();
    void lambda();
    void domParse();
    void cssParse();
};
DECLARE_TEST(TestParser)
#endif // TESTPARSER_H
