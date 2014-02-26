#include "Interface.h"
#include <QPushButton>
#include <QTime>
#include <QPainter>
#include <QMessageBox>
#include <QFile>
#include <QDir>
#include <QApplication>

Interface::Interface()
{
    setupUi();
    setupConnexions();
    showFullScreen();

    //Communication
    upServer();
    connectToPrincipalServer();

    mode = 0;
    timer = new QTimer (this);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimerFinish()));
        timer->start(1000);

    goToRoriMode();
}

/**
 * @brief Interface::setupUi creat the UX
 */
void Interface::setupUi()
{
    setWindowIcon(QIcon("images/logo.png"));
    setWindowTitle("RORI V2");
    setWindowIconText("RORI V2");

    background = new QLabel(this);
    QFile option("option");
    if(option.exists())
    {
        option.open(QIODevice::ReadWrite);
        background->setPixmap(QPixmap(option.readLine().trimmed()));
    }

    roriWidget = new RORIWidget(this);
    roriWidget->hide();

    agendaWidget = new AgendaWidget(this);
    agendaWidget->hide();

    optionWidget = new OptionWidget(this);
    optionWidget->hide();

    color1 = optionWidget->getAppearanceRORI()->getColor1();
    color2 = optionWidget->getAppearanceRORI()->getColor2();

    roriWidget->setColor1(color1);
    roriWidget->setColor2(color2);
    agendaWidget->setColor1(color1);
    agendaWidget->setColor2(color2);

    layoutPrincipal = new QHBoxLayout(0);
    toolbarLeft = new Toolbar(this);
    toolbarLeft->setColor1(color1);
    toolbarLeft->setColor2(color2);
    toolbarLeft->setMaximumWidth(80);

    layoutPrincipal->addWidget(toolbarLeft);
    layoutPrincipal->setMargin(0);
    setLayout(layoutPrincipal);
}

/**
 * @brief Interface::setupConnexions operate QObject::connect
 */
void Interface::setupConnexions()
{
    connect(toolbarLeft, SIGNAL(roriModeClickedS()), this, SLOT(goToRoriMode()));
    connect(toolbarLeft, SIGNAL(agendaModeClickedS()), this, SLOT(goToAgendaMode()));
    connect(toolbarLeft, SIGNAL(optionModeClickedS()), this, SLOT(goToOptionMode()));
    connect(optionWidget, SIGNAL(backgroundImageChanged(QString)), this, SLOT(changeBGImage(QString)));
    connect(optionWidget, SIGNAL(color1Change(QString)), this, SLOT(changeColor1(QString color1)));
    connect(optionWidget, SIGNAL(color2Change(QString)), this, SLOT(changeColor2(QString color2)));
    connect(roriWidget, SIGNAL(sendClicked()), this, SLOT(sendClicked()));
}

/**
 * @brief Interface::resizeEvent resize the UX
 */
void Interface::resizeEvent(QResizeEvent *)
{
    background->resize(this->width(), this->height());
    background->setScaledContents(true);
    toolbarLeft->resize(80, this->height());
    toolbarLeft->move(0,0);
}

/**
 * @brief Interface::goToRoriMode show RORIWidget
 */
void Interface::goToRoriMode()
{
    for(int i = 0; i < layoutPrincipal->count(); ++i)
    {
        layoutPrincipal->removeItem(layoutPrincipal->itemAt(i));
    }
    optionWidget->hide();
    agendaWidget->hide();
    layoutPrincipal->addWidget(toolbarLeft);
    layoutPrincipal->addWidget(roriWidget);
    roriWidget->show();
}

/**
 * @brief Interface::goToOptionMode show OptionWidget
 */
void Interface::goToOptionMode()
{
    for(int i = 0; i < layoutPrincipal->count(); ++i)
    {
        layoutPrincipal->removeItem(layoutPrincipal->itemAt(i));
    }
    roriWidget->hide();
    agendaWidget->hide();
    layoutPrincipal->addWidget(toolbarLeft);
    layoutPrincipal->addSpacing(-10);
    layoutPrincipal->addWidget(optionWidget);
    optionWidget->show();
}

/**
 * @brief Interface::goToAgendaMode show agendaWidget
 */
void Interface::goToAgendaMode()
{
    for(int i = 0; i < layoutPrincipal->count(); ++i)
    {
        layoutPrincipal->removeItem(layoutPrincipal->itemAt(i));
    }
    roriWidget->hide();
    optionWidget->hide();
    layoutPrincipal->addWidget(toolbarLeft);
    layoutPrincipal->addSpacing(-10);
    layoutPrincipal->addWidget(agendaWidget);
    agendaWidget->show();
}

void Interface::changeBGImage(QString image)
{
    background->setPixmap(QPixmap(image));
}

/**
 * @brief Start the server
 */
void Interface::upServer()
{
    int basicGate = 1413;
    bool ok = false;

    server = new QTcpServer(this);
    while(!ok)
    {
        ++basicGate;
        if (server->listen(QHostAddress::Any, basicGate))
        {
            ok = true;
            connect(server, SIGNAL(newConnection()), this, SLOT(newConnection()));
        }
    }
}


/**
 * @brief for speaking order
 */
void Interface::onTimerFinish()
{
    QFile file("stt/records.txt");
    if(file.exists())
    {
        file.open(QIODevice::ReadOnly);
        if(file.isOpen())
        {
            QString speech = file.readAll();
            if(!speech.trimmed().isEmpty())
            {
                file.close();
                file.remove();
                roriWidget->setSayText(speech);
                sendClicked();
            }
        }
    }
}

/**
 * @brief Interface::sendClicked when we click on send
 */
void Interface::sendClicked()
{
    if(!roriWidget->getSay()->text().isEmpty())
    {
        sendMessage(socket, roriWidget->getSay()->text());
        roriWidget->getSay()->clear();
    }
}

/**
 * @brief Interface::sendMessage
 * @param cible where we send the message
 * @param message the message
 */
void Interface::sendMessage(QTcpSocket *cible, QString message)
{
    QByteArray paquet;
    QDataStream out(&paquet, QIODevice::WriteOnly);
    out << "TCHAT:" + message.trimmed();//Add the message
    //Send the message
    cible->write(paquet);
    roriWidget->UserSay(roriWidget->getSay()->text());
}

/**
 * @brief Interface::workData
 * @param message receive via socket
 */
void Interface::workData(QString message)
{
    if(message.indexOf("RORISAY:") == 0)
    {
        QString say;
        for(int i = 8; i < message.length(); ++i)
            say += message[i];
        roriWidget->RORISay(say);
    }
}

/**
 * @brief Interface::connectToPrincipalServer
 */
void Interface::connectToPrincipalServer()
{
    socket = new QTcpSocket;
    socket->connectToHost("127.0.0.1", 1412);
    int i = 0;

    while(!(socket->state() == QAbstractSocket::ConnectedState) && i < 150)
    {
        QApplication::processEvents();
        ++i;
    }
    if(socket->state() == QAbstractSocket::ConnectedState)
    {
        QByteArray paquet;
        QDataStream out(&paquet, QIODevice::WriteOnly);
        out << "NewTchat:127.0.0.1-|-" + QString::number(server->serverPort());
        socket->write(paquet);
        sendMessage(socket, "salut");

        connect(socket, SIGNAL(readyRead()), this, SLOT(dataReceive()));
        connect(socket, SIGNAL(disconnected()), this, SLOT(disconnectClient()));
        connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(SocketError(QAbstractSocket::SocketError)));
    }
    else
    {
        QMessageBox::critical(0, tr("ERROR"), tr("The server is already out"));
    }
}

/**
 * @brief Interface::newConnection
 */
void Interface::newConnection()
{
    QTcpSocket *newClient = server->nextPendingConnection();
    connect(newClient, SIGNAL(readyRead()), this,SLOT(serverReceiveData()));
    connect(newClient, SIGNAL(disconnected()), this, SLOT(disconnectClient()));
}

/**
 * @brief Interface::dataReceive
 */
void Interface::dataReceive()
{
       QDataStream in(socket);

       QString ReceiveMessage;
       in >> ReceiveMessage;
       workData(ReceiveMessage);
}

/**
 * @brief Interface::serverReceiveData
 */
void Interface::serverReceiveData()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    QDataStream in(socket);
    QString messages;
    in >> messages;
    workData(messages);
}

/**
 * @brief Interface::SocketError If an error occurs
 * @param error
 */
void Interface::SocketError(QAbstractSocket::SocketError error)
{
    switch(error)
    {
        case QAbstractSocket::HostNotFoundError:
        QMessageBox::critical(0, tr("ERROR"), tr("<em>ERROR : No server found. Check IP and gate.</em>"));
        break;

        case QAbstractSocket::ConnectionRefusedError:
        QMessageBox::critical(0, tr("ERROR") ,tr("<em>ERROR : Server don't want to be connected with you. Check if the server is up, ip adress and gates.</em>"));
        break;
        case QAbstractSocket::RemoteHostClosedError:
        QMessageBox::critical(0, tr("ERROR") ,tr("<em>ERROR : Server disconnect.</em>"));
        break;
        default:
        QMessageBox::critical(0, tr("ERROR") ,tr("<em>ERROR : ")) + socket->errorString() + tr("</em>");
    }
}

/**
 * @brief Interface::changeColor1
 * @param color
 */
void Interface::changeColor1(QString color)
{
    color1 = color;
    toolbarLeft->setColor1(color);
    roriWidget->setColor1(color);
}

/**
 * @brief Interface::changeColor2
 * @param color
 */
void Interface::changeColor2(QString color)
{
    color2 = color;
    toolbarLeft->setColor2(color);
    roriWidget->setColor2(color);
}
