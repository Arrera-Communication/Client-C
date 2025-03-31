#include "carreraclient.h"

CArreraClient::CArreraClient(QObject *parent,QString pnameSoft)
    : QObject{parent} , nameSoft{pnameSoft}
{}

CArreraClient::~CArreraClient(){}

void CArreraClient::connectToServeur(const QString &url)
{
    connect(&socketClient, &QWebSocket::connected, this,&CArreraClient::onServeurConnected);
    connect(&socketClient,&QWebSocket::textMessageReceived, this, &CArreraClient::onMessageResevied);

    socketClient.open(QUrl(url));
}

void CArreraClient::onServeurConnected(){
    socketClient.sendTextMessage(nameSoft);
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
