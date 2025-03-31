#include <QCoreApplication>
#include "carreraclient.h"
#include <QObject>
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Créer un client avec allocation dynamique pour pouvoir le connecter aux signaux
    CArreraClient* client = new CArreraClient(nullptr, "Socket client");

    // Connecter le signal connectionEstablished pour savoir quand on peut envoyer des messages
    QObject::connect(client, &CArreraClient::connectionEstablished, [client]() {
        if (client->sendMessage("message"))
            cout << "Message envoyé" << endl;
        else
            cout << "Erreur: Impossible d'envoyer le message" << endl;
    });

    // Connecter les signaux de réception de messages
    QObject::connect(client, &CArreraClient::messageReceived, [](const QString& message) {
        cout << "Message reçu du serveur: " << message.toStdString() << endl;
    });

    // Se connecter au serveur
    client->connectToServeur("ws://127.0.0.1:12345");

    // Assurer la libération de la mémoire quand l'application se termine
    QObject::connect(&a, &QCoreApplication::aboutToQuit, [client]() {
        client->disconnectFromServer();
        delete client;
    });

    return a.exec();
}
