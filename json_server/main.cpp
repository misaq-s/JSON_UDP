#include <QCoreApplication>
#include "jsonudp.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    JsonUdp server;

    return a.exec();
}
