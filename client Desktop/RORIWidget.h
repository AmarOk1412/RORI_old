#ifndef RORIWIDGET_H
#define RORIWIDGET_H

#include <QWidget>
#include <QTextEdit>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

/**
 * @brief The RORIWidget class is the interface to speak with RORI
 */
class RORIWidget : public QWidget
{
    Q_OBJECT
public:
    RORIWidget(QWidget *parent = 0);

public slots:
    void RORISay(QString toSay);
    void UserSay(QString toSay);
    inline void setSayText(QString toSay) { say->setText(toSay); }
    inline QLineEdit *getSay() { return say; }
    inline void sendClickedSlot() { emit sendClicked(); }
    void setColor1(QString color);
    void setColor2(QString color);

signals:
    void sendClicked();

private:
    QVBoxLayout *principalLayout;
    QTextEdit *lyrics;
    QHBoxLayout *buttons;
    QLineEdit *say;
    QPushButton *send;

    QString color1;
    QString color2;
};

#endif // RORIWIDGET_H
