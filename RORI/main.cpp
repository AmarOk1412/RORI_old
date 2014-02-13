#include <QCoreApplication>

#include "RORI.h"

#include "UserProfil.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    RORI Rori;

    UserProfil *profil = new UserProfil();
    return a.exec();
}
