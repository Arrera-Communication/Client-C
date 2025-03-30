#include <QCoreApplication>
#include "carreraclient.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    CArreraClient client;
    client.connectToServeur("ws://127.0.0.1:12345");

    return a.exec();
}
