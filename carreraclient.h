#ifndef CARRERACLIENT_H
#define CARRERACLIENT_H

#include <QObject>
#include <QWebSocket>
#include <iostream>

using namespace std;

class CArreraClient : public QObject
{
    Q_OBJECT
private :
    QWebSocket socketClient;
public:
    explicit CArreraClient(QObject *parent = nullptr);
    ~CArreraClient();

    void connectToServeur(const QString &url);

private slots:
    void onServeurConnected();
    void onMessageResevied(const QString &message);
signals:
};

#endif // CARRERACLIENT_H
