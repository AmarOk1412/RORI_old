#ifndef OPTIONWIDGET_H
#define OPTIONWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include "AppearanceOptionWidget.h"
#include "ConnectOptionWidget.h"

/**
 * @brief The OptionWidget class is the interface to modify this programm
 */
class OptionWidget : public QWidget
{
    Q_OBJECT
public:
    OptionWidget(QWidget *parent = 0);
    void setupUI();
    inline AppearanceOptionWidget* getAppearanceRORI() { return appearanceRORI; }

public slots:
    void changeBackgroundImage(QString image);
    void changeColor1(QString color1);
    void changeColor2(QString color2);

    void appearanceClicked();
    void connectClicked();

signals:
    void backgroundImageChanged(QString image);
    void color1Change(QString color1);
    void color2Change(QString color2);

protected:
    void resizeEvent(QResizeEvent *);

private:
    QHBoxLayout *principalLayout;
    QWidget *toolbar;
    QVBoxLayout *toolbarLayout;
    QLabel *word;
    QPushButton *personnalise;
    QPushButton *modesRORI;
    QPushButton *connectivityRORI;
    AppearanceOptionWidget *appearanceRORI;
    ConnectOptionWidget *connectRORI;
};

#endif // OPTIONWIDGET_H
