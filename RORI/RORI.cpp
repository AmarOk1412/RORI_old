#include <iostream>
#include <string>

#include <qdebug.h>

#include "RORI.h"


RORI::RORI()
{
    welcomeMessage();
    startServer();

    socketAnswer = new QTcpSocket;
    connect(socketAnswer, SIGNAL(readyRead()), this, SLOT(receiveData()));
    connect(socketAnswer, SIGNAL(disconnected()), this, SLOT(disconnectClient()));
    connect(socketAnswer, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(SocketError(QAbstractSocket::SocketError)));
}

/**
 * @brief RORI::welcomeMessage say hello :)
 */
void RORI::welcomeMessage()
{
    QTextStream qout(stdout);
    qout << "8888888b.       .d88888b.      8888888b.      8888888     \n"
            "888   Y88b     d88P\" \"Y88b     888   Y88b       888       \n"
            "888    888     888     888     888    888       888       \n"
            "888   d88P     888     888     888   d88P       888       \n"
            "8888888P\"      888     888     8888888P\"        888       \n"
            "888 T88b       888     888     888 T88b         888       \n"
            "888  T88b  d8b Y88b. .d88P d8b 888  T88b  d8b   888   d8b \n"
            "888   T88b Y8P  \"Y88888P\"  Y8P 888   T88b Y8P 8888888 Y8P\n"
            "\n"
            "=========================================================\n"
            "RORI v2.0.1 by AmarOk1412 (http://enconn.fr/)\n"
            "A free, flexible & open-source chatterbot\n"
            "wtfpl : http://www.wtfpl.net/\n"
            "<3 making free projects\n"
            "=========================================================\n\n"
            "RORI is starting...\n";
}


/**
 * @brief RORI::startServer begin the server.
 */
void RORI::startServer()
{
    server = new QTcpServer(0);
    bool fail = false;
    if (!server->listen(QHostAddress::Any, 1412))
    {
        QTextStream qout(stdout);
        qout << "Server can't run\nExit\n";
        fail = true;
    }
    else
    {
        QTextStream qout(stdout);
        qout << "Server is running\n";
        connect(server, SIGNAL(newConnection()), this, SLOT(newConnection()));
    }

    if(fail)
        exit(0);
}

/**
 * @brief RORI::newConnection when a new client is connected
 */
void RORI::newConnection()
{
    QTcpSocket *newClient = server->nextPendingConnection();
    clients << newClient;
    connect(newClient, SIGNAL(readyRead()), this,SLOT(receiveData()));
    connect(newClient, SIGNAL(disconnected()), this, SLOT(disconnectClient()));
}

/**
 * @brief RORI::receiveData When the server receive data
 */
void RORI::receiveData()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    if (socket == 0)
        return;
    QDataStream in(socket);
    QString message;
    in >> message;
    workData(message.trimmed());
}

/**
 * @brief Server::disconnectClient When a client close the connection
 */
void RORI::disconnectClient()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());

    if (socket == 0)
        return;

    clients.removeOne(socket);
    socket->deleteLater();
}

/**
 * @brief RORI::sendAt
 * @param ip
 * @param port
 * @param messageToSend
 */
void RORI::sendAt(QString ip, QString port, QString messageToSend)
{
    QTcpSocket *newSocket = new QTcpSocket;
    newSocket->connectToHost(ip, port.toInt());
    while(!newSocket->isOpen() && !newSocket->isValid() && !newSocket->isWritable())
    {

    }

    QByteArray paquet;
    QDataStream out(&paquet, QIODevice::WriteOnly);
    out << messageToSend.trimmed();
    newSocket->write(paquet);
}

/**
 * @brief RORI::sendMessage send message to target
 * @param target
 * @param message
 */
void RORI::sendMessage(QTcpSocket *target, QString message)
{
    QByteArray packet;
    QDataStream out(&packet, QIODevice::WriteOnly);
    out << message.trimmed();//Add the message
    //Send the message
    target->write(packet);
}

/**
 * @brief RORI::saySomething send message with socketAnswer
 * @param message
 */
void RORI::saySomething(QString message)
{
    sendMessage(socketAnswer, message);
}

/**
 * @brief RORI::SocketError if an error occurs
 * @param error
 */
void RORI::SocketError(QAbstractSocket::SocketError error)
{
    switch(error)
    {
        case QAbstractSocket::HostNotFoundError:
        qDebug("ERROR : No server found. Check IP and gate.");
        break;
        case QAbstractSocket::ConnectionRefusedError:
        qDebug("ERROR : Server don't want to be connected with you. Check if the server is up, ip adress and gates.");
        break;
        case QAbstractSocket::RemoteHostClosedError:
        qDebug("ERROR : Server disconnect.");
        break;
        default:
        qDebug("ERROR : Unknown error");
    }
}

/**
 * @brief RORI::timeBeforeQuestion
 * @return the time in ms before the new question
 */
int RORI::timeBeforeQuestion()
{
    return 5000*3600*exp(0-rand()%10);
}

/**
 * @brief RORI::ask
 */
void RORI::ask()
{
    time = timeBeforeQuestion();
    timer = new QTimer (this);
    connect(timer, SIGNAL(timeout()), this, SLOT(ask()));
        timer->start(time);
}

/**
 * @brief RORI::workData Treat the message
 * @param message send by the client
 */
void RORI::workData(QString message)
{
    Q_UNUSED(message)
    //TODO: Connect with Client (init socketAnswer) + send to Semantik Class
}

