#include "Profiler.h"

Profiler::Profiler()
{
    roriProfil = new RoriProfil();
    userProfil = new UserProfil();

    timer = new QTimer();
    //connect(timer, SIGNAL(timeout()), this, SLOT(lireEnd()));
    //timer->start(100);
}

void Profiler::workData(QString message)
{
    QTextStream qout(stdout);
    qout << tr("Profiler : ") + message + '\n';
}
