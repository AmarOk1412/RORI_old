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

private:
    QTcpServer *server;
};

#endif // RORI_H
