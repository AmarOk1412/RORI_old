#include "OptionWidget.h"

OptionWidget::OptionWidget(QWidget *parent) : QWidget(parent)
{
    setupUI();
}

/**
 * @brief OptionWidget::setupUI create the UX of this widget
 */
void OptionWidget::setupUI()
{
    appearanceRORI = new AppearanceOptionWidget(this);
    connectRORI = new ConnectOptionWidget(this);
    connectRORI->setColor2(appearanceRORI->getColor2());
    connectRORI->hide();

    principalLayout = new QHBoxLayout(this);
    principalLayout->setMargin(0);

    toolbar = new QWidget(this);
    toolbar->setStyleSheet("background-color:#f4f4f4;");
    toolbarLayout = new QVBoxLayout(this);
    word = new QLabel(" Options", toolbar);
    word->setStyleSheet("color: " + appearanceRORI->getColor2() + "; font-size:60px;");
    personnalise = new QPushButton(tr("\nAppearance\n"), toolbar);
    personnalise->setStyleSheet("QPushButton { border:0; margin:0; width:100%; font-size:20px;} \
                                 QPushButton::hover { background-color: " + appearanceRORI->getColor2() + "; color:#f4f4f4;}");
    modesRORI = new QPushButton("\nModules\n", toolbar);
    modesRORI->setStyleSheet("QPushButton { border:0; margin:0; width:100%; font-size:20px;} \
                              QPushButton::hover { background-color: " + appearanceRORI->getColor2() + "; color:#f4f4f4;}");

    connectivityRORI = new QPushButton(tr("\nConnectivity\n"), toolbar);
    connectivityRORI->setStyleSheet("QPushButton { border:0; margin:0; width:100%; font-size:20px;} \
                                     QPushButton::hover { background-color: " + appearanceRORI->getColor2() + "; color:#f4f4f4;}");
    toolbarLayout->addSpacing(40);
    toolbarLayout->addWidget(word);
    toolbarLayout->addSpacing(20);
    toolbarLayout->addWidget(personnalise);
    toolbarLayout->addWidget(modesRORI);
    toolbarLayout->addWidget(connectivityRORI);
    toolbarLayout->setAlignment(Qt::AlignTop);
    toolbarLayout->setMargin(0);
    toolbar->setLayout(toolbarLayout);

    principalLayout->addWidget(toolbar);
    principalLayout->addWidget(appearanceRORI);
    principalLayout->setAlignment(Qt::AlignLeft);
    this->setLayout(principalLayout);

    connect(appearanceRORI, SIGNAL(backgroundImageChanged(QString)), this, SLOT(changeBackgroundImage(QString)));
    connect(appearanceRORI, SIGNAL(color1Changed(QString)), this, SLOT(changeColor1(QString)));
    connect(appearanceRORI, SIGNAL(color2Changed(QString)), this, SLOT(changeColor2(QString)));
    connect(personnalise, SIGNAL(clicked()), this, SLOT(appearanceClicked()));
    connect(connectivityRORI, SIGNAL(clicked()), this, SLOT(connectClicked()));
}

/**
 * @brief OptionWidget::resizeEvent when we resize the widget
 */
void OptionWidget::resizeEvent(QResizeEvent *)
{
    toolbar->setFixedSize(this->width()/4, this->height());
    appearanceRORI->setFixedSize(this->width()*3/4-80, this->height());
}

/**
 * @brief OptionWidget::changeBackgroundImage when we change the background
 * @param image the path of the picture
 */
void OptionWidget::changeBackgroundImage(QString image)
{
    emit backgroundImageChanged(image);
}

/**
 * @brief OptionWidget::changeColor1 when we change color1
 * @param color1 the color which change
 */
void OptionWidget::changeColor1(QString color1)
{
    emit color1Change(color1);
}


/**
 * @brief OptionWidget::changeColor2 when we change color2
 * @param color2 the color which change
 */
void OptionWidget::changeColor2(QString color2)
{
    emit color2Change(color2);
    word->setStyleSheet("color: " + appearanceRORI->getColor2() + "; font-size:60px;");
    personnalise->setStyleSheet("QPushButton { border:0; margin:0; width:100%; font-size:20px;} \
                                 QPushButton::hover { background-color: " + appearanceRORI->getColor2() + "; color:#f4f4f4;}");
    modesRORI->setStyleSheet("QPushButton { border:0; margin:0; width:100%; font-size:20px;} \
                              QPushButton::hover { background-color: " + appearanceRORI->getColor2() + "; color:#f4f4f4;}");
    connectivityRORI->setStyleSheet("QPushButton { border:0; margin:0; width:100%; font-size:20px;} \
                                     QPushButton::hover { background-color: " + appearanceRORI->getColor2() + "; color:#f4f4f4;}");
    connectRORI->setColor2(color2);
}

/**
 * @brief OptionWidget::connectClicked show connect menu
 */
void OptionWidget::connectClicked()
{
    for(int i = 0; i < principalLayout->count(); ++i)
    {
        principalLayout->removeItem(principalLayout->itemAt(i));
    }
    connectRORI->show();
    appearanceRORI->hide();
    principalLayout->addWidget(toolbar);
    principalLayout->addWidget(connectRORI);
    principalLayout->setAlignment(Qt::AlignLeft);
    this->setLayout(principalLayout);
}

/**
 * @brief OptionWidget::appearanceClicked show appearance menu
 */
void OptionWidget::appearanceClicked()
{
    for(int i = 0; i < principalLayout->count(); ++i)
    {
        principalLayout->removeItem(principalLayout->itemAt(i));
    }
    connectRORI->hide();
    appearanceRORI->show();
    principalLayout->addWidget(toolbar);
    principalLayout->addWidget(appearanceRORI);
    principalLayout->setAlignment(Qt::AlignLeft);
    this->setLayout(principalLayout);
}
