#include <QCoreApplication>
#include "carreraclient.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    CArreraClient client = CArreraClient(nullptr,"Socket client");
    client.connectToServeur("ws://127.0.0.1:12345");

    QString message;
    string smessage;

    cout << "Envoyer un message au serveur :" << endl;
    cin >> smessage;
    message = QString::fromStdString(smessage);
    cout << endl;

    if (client.sendMessage("Ma bite"))
        cout << "Message envoyer" << endl;

    return a.exec();
}
