#ifndef PROFILER_H
#define PROFILER_H

#include <QObject>
#include <QtNetwork>

#include "RoriProfil.h"
#include "UserProfil.h"

class Profiler : public QObject
{
    Q_OBJECT

public:
    Profiler();

public slots:
    void workData(QString message);

signals:

private:
    QTimer *timer;
    //Profiler
    RoriProfil *roriProfil;
    UserProfil *userProfil;
};

#endif // PROFILER_H
