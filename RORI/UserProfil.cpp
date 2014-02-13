#include <QFile>
#include <QTextStream>

#include "UserProfil.h"

/**
 * @brief UserProfil::UserProfil configure the profil of the user
 */
UserProfil::UserProfil()
{
    uHumor      = 0;
    uPolite     = 0;
    uMoral      = 0;
    uJokes      = 0;
    uTired      = 0;
    uIsABadUser = 0;
    uCurious    = 0;

    name = "default";
    firstName = "default";
    age = 0;

    QFile profil("config/userProfil.inf");
    if(!profil.exists())
        saveProfil();
    profil.open(QIODevice::ReadOnly);
    if(profil.isOpen())
    {
        setUHumor(profil.readLine().toInt());
        setUIsABadUser(profil.readLine().toInt());
        setUJokes(profil.readLine().toInt());
        setUMoral(profil.readLine().toInt());
        setUPolite(profil.readLine().toInt());
        setUCurious(profil.readLine().toInt());
        setUTired(profil.readLine().toInt());
        setAge(profil.readLine().toInt());
        setName(profil.readLine().trimmed());
        setFirstName(profil.readLine().trimmed());
    }

    QTextStream qout(stdout);
    qout << "Bonjour " + getFirstName() + " " + getName() + "\n";

    setAge(20);
    setUCurious(23);
    saveProfil();
}

/**
 * @brief UserProfil::saveProfil save the profil into the file config/userProfil.inf
 */
void UserProfil::saveProfil()
{
    QFile profil("config/userProfil.inf");
    profil.open(QIODevice::WriteOnly);
    if(profil.isOpen())
    {
        QString toWrite;
        toWrite += QString::number(getUHumor());
        toWrite += '\n';
        toWrite += QString::number(getUIsABadUser());
        toWrite += '\n';
        toWrite += QString::number(getUJokes());
        toWrite += '\n';
        toWrite += QString::number(getUMoral());
        toWrite += '\n';
        toWrite += QString::number(getUPolite());
        toWrite += '\n';
        toWrite += QString::number(getUCurious());
        toWrite += '\n';
        toWrite += QString::number(getUTired());
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
