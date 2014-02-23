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
    void delFilePath(QString path);

signals:
    void saySomething(QString toSay);

private slots:
    void saySomethingSlot(QString toSay);
    void sayEverything(QString message);
    void addNewFilePath(QString newPath);

private:
    QStringList activePaths;
    QStringList classicPaths;

    Profiler *profiler;
    MemoryInterface *memInt;
};

#endif // SEMANTIK_H
