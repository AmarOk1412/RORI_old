#ifndef CONNECTOPTIONWIDGET_H
#define CONNECTOPTIONWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QFormLayout>

/**
 * @brief The ConnectOptionWidget class
 */
class ConnectOptionWidget : public QWidget
{
    Q_OBJECT
public:
    ConnectOptionWidget(QWidget *parent = 0);

public slots:
    void setupUi();
    void setupVars();
    void saveOptions();
    void setColor2(QString color);
    inline QString getColor1() { return color1; }
    inline QString getColor2() { return color2; }

private:
    QFormLayout *principalLayout;
    QLabel *principalServer;
    QLineEdit *ipServer;
    QLineEdit *portServer;
    QLabel *Android;
    QLineEdit *ftpAdress;
    QLineEdit *ftpUser;
    QLineEdit *ftpPass;
    QLineEdit *androidReqIn;
    QPushButton *saveAct;


    QString color1;
    QString color2;
};

#endif // CONNECTOPTIONWIDGET_H
