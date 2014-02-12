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

private:
    QTcpServer *server;
    QList<QTcpSocket *> clients;
};

#endif // RORI_H
