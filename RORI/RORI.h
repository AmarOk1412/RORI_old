#ifndef RORI_H
#define RORI_H

#include <QtNetwork>

class RORI : public QObject
{
    Q_OBJECT
public:
    RORI();
    void welcomeMessage();
    void startServer();

private slots:
    void newConnection();
    void receiveData();
    void disconnectClient();
    void workData(QString message);
    void sendAt(QString ip, QString port, QString messageToSend);

private:
    QTcpServer *server;
    QList<QTcpSocket *> clients;
};

#endif // RORI_H
