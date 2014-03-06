#include "RORIWidget.h"
#include <QScrollBar>
#include <QProcess>
#include <QMessageBox>

RORIWidget::RORIWidget(QWidget *parent) : QWidget(parent)
{
    principalLayout = new QVBoxLayout(this);
    lyrics = new QTextEdit(this);
    lyrics->setStyleSheet("background:transparent; border:0;");

    buttons = new QHBoxLayout(this);
    say = new QLineEdit(this);
    say->setStyleSheet("font-size:20px; height:40px;border:0;");
    send = new QPushButton(tr("Send"), this);
    send->setStyleSheet("align:center; color:white; font-size:20px; border:0; background-color: #1a7c88; width: 250px; height:40px;border-radius: 10px;");
    buttons->addWidget(say);
    buttons->addWidget(send);

    principalLayout->addWidget(lyrics);
    principalLayout->addLayout(buttons);
    this->setLayout(principalLayout);

    connect(send, SIGNAL(clicked()), this, SLOT(sendClickedSlot()));
}

/**
 * @brief RORIWidget::RORISay write into lyrics what RORI say
 * @param toSay what RORI say
 */
void RORIWidget::RORISay(QString toSay)
{
    QString texte = lyrics->toHtml();
    toSay = toSay.replace("<p>", "");
    texte += "<p style=\"color:#FFF; background-color:" + color2 + "; width:100%; font-size:20px;margin-bottom:10px;\"><center>"+ toSay +"</center></p>";
    lyrics->setText(texte);
    lyrics->verticalScrollBar()->setValue(lyrics->verticalScrollBar()->maximum());
    QProcess::startDetached("python tts/tts.py " + toSay);
}

/**
 * @brief RORIWidget::UserSay write into lyrics what User say
 * @param toSay what User say
 */
void RORIWidget::UserSay(QString toSay)
{
    QString texte = lyrics->toHtml();
    texte += "<p style=\"color:#fff; background-color:" + color1 + "; width:100%; font-size:20px;margin-bottom:10px;\"><center>"+ toSay +"</center></p>";
    lyrics->setText(texte);
    lyrics->verticalScrollBar()->setValue(lyrics->verticalScrollBar()->maximum());
}

/**
 * @brief RORIWidget::setColor1
 * @param color
 */
void RORIWidget::setColor1(QString color)
{
    color1 = color;
}

/**
 * @brief RORIWidget::setColor2
 * @param color
 */
void RORIWidget::setColor2(QString color)
{
    color2 = color;
    send->setStyleSheet("align:center; color:white; font-size:20px; border:0; background-color: "+ color2 +"; width: 250px; height:40px;border-radius: 10px;");
}
