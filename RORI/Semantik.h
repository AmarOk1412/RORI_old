#ifndef SEMANTIK_H
#define SEMANTIK_H

#include <QObject>
#include <QStringList>

#include "Profiler.h"
#include "MemoryInterface.h"

class Semantik : public QObject
{
    Q_OBJECT

public:
    Semantik();
    void workData(QString message);
    QStringList cutSentence(QString sentences);
    QStringList getWords(QString sentence);
    QStringList setCategoriesWords(QStringList words);
    QStringList setTypesWords(QStringList words);
    void addNewFilePath(QString newPath);
    void delFilePath(QString path);

signals:
    void saySomething(QString toSay);

private slots:
    void saySomethingSlot(QString toSay);

private:
    QStringList activePaths;
    QStringList classicPaths;

    Profiler *profiler;
    MemoryInterface *memInt;
};

#endif // SEMANTIK_H
