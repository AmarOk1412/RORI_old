#include "AppearanceOptionWidget.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QApplication>
#include <QDesktopWidget>
#include <QFileDialog>
#include <QColor>
#include <QColorDialog>

AppearanceOptionWidget::AppearanceOptionWidget(QWidget *parent) : QWidget(parent)
{
    setupUi();
}

/**
 * @brief AppearanceOptionWidget::setupUi create the UX
 */
void AppearanceOptionWidget::setupUi()
{
    principalLayout = new QVBoxLayout(this);
    principalLayout->setAlignment(Qt::AlignTop);
    bgImage = new QLabel(this);
    QFile option("config/option");
    if(option.exists())
    {
        option.open(QIODevice::ReadWrite);
        backgroundImage = option.readLine().trimmed();
        bgImage->setPixmap(QPixmap(backgroundImage));
        color1 = option.readLine().trimmed();
        color2 = option.readLine().trimmed();
    }
    else
    {
        option.open(QIODevice::ReadWrite);
        QTextStream out(&option);
        out << "images/background.png\n#f19b1e\n#252525 ";
        backgroundImage = "images/background.png";
        color1 = "#f19b1e";
        color2 = "#252525";
    }
    bgImage->setMaximumSize(this->width()/2, this->height());
    bgImage->setScaledContents(true);
    bgImage->setStyleSheet("border: 1px solid #B4B4B4;");
    buttons = new QHBoxLayout(this);
    changeBg = new QPushButton("Change Background", this);
    reinitialiser = new QPushButton("Reset Background", this);
    buttons->addWidget(changeBg);
    buttons->addWidget(reinitialiser);

    buttonsColor = new QHBoxLayout;
    changeColor1 = new QPushButton("Change Color 1", this);
    changeColor2 = new QPushButton("Change Color 2", this);
    buttonsColor->addWidget(changeColor1);
    buttonsColor->addWidget(changeColor2);

    principalLayout->addSpacing(40);
    principalLayout->addWidget(bgImage);
    principalLayout->addLayout(buttons);
    principalLayout->addLayout(buttonsColor);
    this->setLayout(principalLayout);

    this->setStyleSheet("QPushButton { align:center; color:white; font-size:20px; border:0; background-color: "+ color2 +"; width: 250px; height:40px;}");
    changeColor1->setStyleSheet("background-color:" + color1);

    connect(reinitialiser, SIGNAL(clicked()), this, SLOT(resetClicked()));
    connect(changeBg, SIGNAL(clicked()), this, SLOT(changeBackgroundImage()));
    connect(changeColor1, SIGNAL(clicked()), this, SLOT(setColor1()));
    connect(changeColor2, SIGNAL(clicked()), this, SLOT(setColor2()));
}

/**
 * @brief AppearanceOptionWidget::resizeEvent when we resize the window
 */
void AppearanceOptionWidget::resizeEvent(QResizeEvent *)
{
    bgImage->setFixedSize(this->width()-20, this->width()*600/1600);
    bgImage->setScaledContents(true);
}

/**
 * @brief AppearanceOptionWidget::resetClicked when we click on reinisialiser
 */
void AppearanceOptionWidget::resetClicked()
{
    QFile option("config/option");
    option.remove();
    option.open(QIODevice::ReadWrite);
    QTextStream out(&option);
    out << "images/background.png" + '\n' + color1 + '\n' + color2;
    bgImage->setPixmap(QPixmap("images/background.png"));
}

/**
 * @brief AppearanceOptionWidget::changeBackgroundImage change the Background of the App
 */
void AppearanceOptionWidget::changeBackgroundImage()
{
    QString image = QFileDialog::getOpenFileName(0, "Choose Background Image", QString(), "Images (*.png)");
    if(!image.isEmpty())
    {
        QFile option("config/option");
        option.remove();
        option.open(QIODevice::ReadWrite);
        QTextStream out(&option);
        out << image + '\n' + color1 + '\n' + color2;
        backgroundImage = image;
        bgImage->setPixmap(QPixmap(image));
        emit backgroundImageChanged(image);
    }
}

/**
 * @brief AppearanceOptionWidget::setColor1 change color1
 */
void AppearanceOptionWidget::setColor1()
{
    QColor color = QColorDialog::getColor();
    color1 = color.name();
    if(!color1.isEmpty())
    {
        QFile option("config/option");
        option.remove();
        option.open(QIODevice::ReadWrite);
        QTextStream out(&option);
        out << backgroundImage + '\n' + color1 + '\n' + color2;
        changeColor1->setStyleSheet("background-color:" + color1);
        emit color1Changed(color1);
    }
}

/**
 * @brief AppearanceOptionWidget::setColor2 change color2
 */
void AppearanceOptionWidget::setColor2()
{
    QColor color = QColorDialog::getColor();
    color2 = color.name();
    if(!color2.isEmpty())
    {
        QFile option("config/option");
        option.remove();
        option.open(QIODevice::ReadWrite);
        QTextStream out(&option);
        out << backgroundImage + '\n' + color1 + '\n' + color2;
        this->setStyleSheet("QPushButton { align:center; color:white; font-size:20px; border:0; background-color: "+ color2 +"; width: 250px; height:40px;}");
        emit color2Changed(color2);
    }
}

