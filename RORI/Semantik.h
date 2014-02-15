#ifndef SEMANTIK_H
#define SEMANTIK_H

#include <QObject>
#include <QStringList>

class Semantik : public QObject
{
    Q_OBJECT

public:
    Semantik();
    void workData(QString message);
    QStringList getWords(QString sentence);

signals:
    void saySomething(QString toSay);

private slots:
    void saySomethingSlot(QString toSay);
};

#endif // SEMANTIK_H
