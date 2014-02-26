#include "ConnectOptionWidget.h"
#include <QFile>
#include <QTextStream>

ConnectOptionWidget::ConnectOptionWidget(QWidget *parent) : QWidget(parent)
{
    setupUi();

}

/**
 * @brief ConnectOptionWidget::setupUi create the UX
 */
void ConnectOptionWidget::setupUi()
{
    principalLayout = new QFormLayout(this);
    principalServer = new QLabel(tr("RORI's' Server :"));
    ipServer = new QLineEdit;
    portServer = new QLineEdit;
    Android = new QLabel(tr("Web interface"));
    ftpAdress = new QLineEdit;
    ftpUser = new QLineEdit;
    ftpPass = new QLineEdit;
    ftpPass->setEchoMode(QLineEdit::Password);
    androidReqIn = new QLineEdit;
    saveAct = new QPushButton(tr("Save"));
    saveAct->setStyleSheet("align:center; color:white; font-size:20px; border:0; background-color: #1a7c88; width: 250px; height:40px;");

    principalLayout->setSpacing(40);
    principalLayout->addWidget(principalServer);
    principalLayout->addRow("IP :", ipServer);
    principalLayout->addRow("Port :", portServer);
    principalLayout->addWidget(Android);
    principalLayout->addRow(tr("FTP server :"), ftpAdress);
    principalLayout->addRow(tr("Login :"), ftpUser);
    principalLayout->addRow(tr("Password :"), ftpPass);
    principalLayout->addRow(tr("Android url in :"), androidReqIn);
    principalLayout->addWidget(saveAct);

    setupVars();

    this->setLayout(principalLayout);
    this->setStyleSheet("QLineEdit {background-color : white; border:0;}; ");

    connect(saveAct, SIGNAL(clicked()), this, SLOT(saveOptions()));
}

/**
 * @brief ConnectOptionWidget::setColor2 change color2
 * @param color new color2
 */
void ConnectOptionWidget::setColor2(QString color)
{
    color2 = color;
    saveAct->setStyleSheet("align:center; color:white; font-size:20px; border:0; background-color: " + color +"; width: 250px; height:40px;");
}

/**
 * @brief ConnectOptionWidget::setupVars get settings
 */
void ConnectOptionWidget::setupVars()
{
    QFile optionConnectF("config/connectOption");
    if(optionConnectF.exists())
    {
        optionConnectF.open(QIODevice::ReadOnly);
        ipServer->setText(optionConnectF.readLine().trimmed());
        portServer->setText(optionConnectF.readLine().trimmed());
        ftpAdress->setText(optionConnectF.readLine().trimmed());
        ftpUser->setText(optionConnectF.readLine().trimmed());
        ftpPass->setText(optionConnectF.readLine().trimmed());
        androidReqIn->setText(optionConnectF.readLine().trimmed());
    }
    else
    {
        optionConnectF.open(QIODevice::WriteOnly);
        QTextStream out(&optionConnectF);
        out << "127.0.0.1\n1412\nserveurAndroid\nuser\nPass\nhttp://androidIn.txt";
        ipServer->setText("127.0.0.1");
        portServer->setText("1412");
        ftpAdress->setText("serveurAndroid");
        ftpUser->setText("user");
        ftpPass->setText("Pass");
        androidReqIn->setText("http://androidIn.txt");
    }
}

/**
 * @brief ConnectOptionWidget::saveOptions save
 */
void ConnectOptionWidget::saveOptions()
{
    QFile optionConnectF("config/connectOption");
    optionConnectF.open(QIODevice::WriteOnly);
    QTextStream out(&optionConnectF);
    out << ipServer->text().trimmed() + '\n';
    out << portServer->text().trimmed() + '\n';
    out << ftpAdress->text().trimmed() + '\n';
    out << ftpUser->text().trimmed() + '\n';
    out << ftpPass->text().trimmed() + '\n';
    out << androidReqIn->text().trimmed() + '\n';
}
