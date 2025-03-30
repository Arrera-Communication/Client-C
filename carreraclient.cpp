#include "carreraclient.h"

CArreraClient::CArreraClient(QObject *parent)
    : QObject{parent}
{}

CArreraClient::~CArreraClient(){}

void CArreraClient::connectToServeur(const QString &url)
{
    connect(&socketClient, &QWebSocket::connected, this,&CArreraClient::onServeurConnected);
    connect(&socketClient,&QWebSocket::textMessageReceived, this, &CArreraClient::onMessageResevied);

    socketClient.open(QUrl(url));
}

void CArreraClient::onServeurConnected(){
    socketClient.sendTextMessage("A");
}

void CArreraClient::onMessageResevied(const QString &message)
{
    cout << "WebSocket Response:" << message.toStdString() << endl;
}
