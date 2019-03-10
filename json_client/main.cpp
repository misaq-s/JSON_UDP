#include <QCoreApplication>
#include "jsonudp.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
JsonUdp client;

    return a.exec();
}
