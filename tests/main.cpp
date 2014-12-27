#include <QTest>


#include "testa.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    TestQString test1;
    QTest::qExec(&test1,argc,argv);


    return 0;
}
