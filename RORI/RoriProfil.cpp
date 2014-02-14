#include "RoriProfil.h"

#include <QFile>
#include <QTextStream>

RoriProfil::RoriProfil()
{
    roriHumor    = 0;
    roriPolite   = 0;
    roriJokes    = 0;
    roriIsABadIA = 0;
    age = 0;

    name = "GUILMORE";
    firstName = "RORI";

    QFile profil("config/RORIProfil.inf");
    if(!profil.exists())
        saveProfil();
    profil.open(QIODevice::ReadOnly);
    if(profil.isOpen())
    {
        setRoriHumor(profil.readLine().toInt());
        setRoriIsABadIA(profil.readLine().toInt());
        setRoriJokes(profil.readLine().toInt());
        setRoriMoral(profil.readLine().toInt());
        setRoriPolite(profil.readLine().toInt());
        setRoriScared(profil.readLine().toInt());
        setAge(profil.readLine().toInt());
        setName(profil.readLine().trimmed());
        setFirstName(profil.readLine().trimmed());
    }
}

/**
 * @brief RoriProfil::saveProfil save the profil into the file config/userProfil.inf
 */
void RoriProfil::saveProfil()
{
    QFile profil("config/RORIProfil.inf");
    profil.open(QIODevice::WriteOnly);
    if(profil.isOpen())
    {
        QString toWrite;
        toWrite += QString::number(getRoriHumor());
        toWrite += '\n';
        toWrite += QString::number(getRoriIsABadIA());
        toWrite += '\n';
        toWrite += QString::number(getRoriJokes());
        toWrite += '\n';
        toWrite += QString::number(getRoriMoral());
        toWrite += '\n';
        toWrite += QString::number(getRoriPolite());
        toWrite += '\n';
        toWrite += QString::number(getRoriScared());
        toWrite += '\n';
        toWrite += QString::number(getAge());
        toWrite += '\n';
        toWrite += getName();
        toWrite += '\n';
        toWrite += getFirstName();
        QTextStream out(&profil);
        out << toWrite.trimmed();
    }
}
