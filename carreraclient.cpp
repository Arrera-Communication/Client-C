#include "carreraclient.h"

CArreraClient::CArreraClient(QObject *parent,QString pnameSoft)
    : QObject{parent} , nameSoft{pnameSoft}
{}

CArreraClient::~CArreraClient(){}

void CArreraClient::connectToServeur(const QString &url)
{
    connect(&socketClient, &QWebSocket::connected, this, &CArreraClient::onServeurConnected);
    connect(&socketClient, &QWebSocket::disconnected, this, []() {
        qDebug() << "La connexion au serveur a été interrompue.";
    });
    connect(&socketClient, &QWebSocket::textMessageReceived, this, &CArreraClient::onMessageResevied);

    // Ouvrir la connexion avec l'URL spécifiée
    qDebug() << "Connexion en cours au serveur WebSocket : " << url;
    socketClient.open(QUrl(url));
}

bool CArreraClient::sendMessage(QString message){
    if (message.isEmpty()){
        return false;
    }

    if (socketClient.state() != QAbstractSocket::ConnectedState) {
        cout << "Le socket n'est pas connecté." << endl;
        return false;
    }

    cout << message.toStdString() << endl;
    socketClient.sendTextMessage(message+"\n");
    return true;

}

void CArreraClient::onServeurConnected(){
    socketClient.sendTextMessage(nameSoft+"\n");
}

void CArreraClient::onMessageResevied(const QString &message)
{
    signalEmitted = true;
    // Émettre un signal lorsqu'un message est reçu
    emit messageReceived(message);

    if (message != "Message Received"){
        socketClient.sendTextMessage("Message Received");
    }
}
