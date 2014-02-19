#ifndef PROFILER_H
#define PROFILER_H

#include <QObject>
#include <QtNetwork>

#include "RoriProfil.h"
#include "UserProfil.h"
#include "enumeration.h"

class Profiler : public QObject
{
    Q_OBJECT

public:
    Profiler();

public slots:
    void workData(QString message);
    void execFunction(QString pathToFunction);
    bool condAccept(QStringList conds);
    void readEnd();

signals:
    void endOfTreatment(QString message);
    void newPath(QString newPath);
    void delPro(QString path);
    void newWord(QString newWord);
    void newFunc();

private:
    QTimer *timer;
    //Profiler
    RoriProfil *roriProfil;
    UserProfil *userProfil;

    QStringList params;
    QList<QProcess *> listeProgramms;
    bool saluer;
};

#endif // PROFILER_H
