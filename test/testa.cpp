#include "testa.h"

void TestQString::toUpper() {
     QString str = "Hello";
     QVERIFY(str.toUpper() == "HELLO");
}
