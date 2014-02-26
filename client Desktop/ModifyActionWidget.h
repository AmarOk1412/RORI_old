#ifndef MODIFYACTIONWIDGET_H
#define MODIFYACTIONWIDGET_H

#include <QtWidgets/QWidget>
#include <QPushButton>
#include <QComboBox>
#include <QHBoxLayout>
#include <QLineEdit>

class ModActionWidget : public QWidget
{
    Q_OBJECT
public:
    ModActionWidget(QStringList events);

private:
    QVBoxLayout *principalLayout;
    QComboBox *eventsBox;
    QPushButton *btnMod;
    QLineEdit *roriSay;
    QLineEdit *rorifFile;
};


#endif // MODIFYACTIONWIDGET_H
