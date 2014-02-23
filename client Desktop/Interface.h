#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>
#include <QPixmap>
#include <QLabel>
#include <QHBoxLayout>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTimer>

#include "Toolbar.h"
#include "RORIWidget.h"
#include "OptionWidget.h"
#include "AgendaWidget.h"

/**
 * @brief The Interface class is the UX of RORI
 */
class Interface : public QWidget
{
    Q_OBJECT

public:
    Interface();
    void setupUi();
    void setupConnexions();
    void upServer();
    void workData(QString message);
    void connectToPrincipalServer();

public slots:
    void goToRoriMode();
    void goToOptionMode();
    void goToAgendaMode();
    void changeBGImage(QString image);
    void changeColor1(QString color);
    void changeColor2(QString color);
    void onTimerFinish();
    void sendClicked();
    void sendMessage(QTcpSocket *cible, QString message);
    void newConnection();
    void dataReceive();
    void serverReceiveData();
    void SocketError(QAbstractSocket::SocketError error);


protected:
    void resizeEvent(QResizeEvent *);

private:
    QLabel *background;
    QHBoxLayout *layoutPrincipal;

    Toolbar *toolbarLeft;
    RORIWidget *roriWidget;
    OptionWidget *optionWidget;
    AgendaWidget *agendaWidget;

    QTcpServer *server;
    QTcpSocket *socket;
    QTimer *timer;

    int mode;

    QString color1;
    QString color2;
};

#endif // INTERFACE_H
