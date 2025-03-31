#include <QCoreApplication>
#include "carreraclient.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    CArreraClient client;
    client.connectToServeur("ws://127.0.0.1:12345");
    QString message;

    bool connect = QObject::connect(&client, &CArreraClient::messageReceived, [](const QString &message){
        cout << "Message :" << message.toStdString();
        cout.flush();
    });

    //cout << "Envoyer un message au serveur :" << endl;
    //cin >> message ;

    //client.

    return a.exec();
}
