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
    void sendAt(QString ip, QString port, QString messageToSend);
    void sendMessage(QTcpSocket *target, QString message);
    void saySomething(QString message);
    void SocketError(QAbstractSocket::SocketError error);
    int timeBeforeQuestion();
    void ask();
    void workData(QString message);

private:
    QTcpServer *server;
    QList<QTcpSocket *> clients;

    QTcpSocket *socketAnswer;
    int time;
    QTimer *timer;
};

#endif // RORI_H
