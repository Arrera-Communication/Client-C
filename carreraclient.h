#ifndef CARRERACLIENT_H
#define CARRERACLIENT_H

#include <QObject>
#include <QWebSocket>
#include <iostream>
#include <QJsonDocument>
#include <QJsonObject>

using namespace std;

class CArreraClient : public QObject
{
    Q_OBJECT
private :
    QWebSocket socketClient;
    volatile bool signalEmitted = false;
public:
    explicit CArreraClient(QObject *parent = nullptr);
    ~CArreraClient();

    void connectToServeur(const QString &url);

private slots:
    void onServeurConnected();
    void onMessageResevied(const QString &message);
signals:
    void messageReceived(const QString &message);
};

#endif // CARRERACLIENT_H
