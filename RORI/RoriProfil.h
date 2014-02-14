#ifndef RORIPROFIL_H
#define RORIPROFIL_H

#include <QObject>

class RoriProfil : public QObject
{
    Q_OBJECT

public:
    RoriProfil();
    void saveProfil();

public slots:
    //Getters and setters
    inline int getRoriHumor() { return roriHumor;}
    inline int getRoriPolite() { return roriPolite; }
    inline int getRoriJokes()  { return roriJokes; }
    inline int getRoriIsABadIA() { return roriIsABadIA; }
    inline int getRoriScared() { return roriScared; }
    inline int getRoriMoral() { return roriMoral; }

    inline void setRoriHumor(int newValue) { roriHumor = newValue <= 100 && newValue >= 0 ? newValue : roriHumor; saveProfil();}
    inline void setRoriPolite(int newValue) { roriPolite = newValue <= 100 && newValue >= 0 ? newValue : roriPolite; saveProfil();}
    inline void setRoriJokes(int newValue) { roriJokes = newValue <= 100 && newValue >= 0 ? newValue : roriJokes; saveProfil();}
    inline void setRoriIsABadIA(int newValue) { roriIsABadIA = newValue <= 100 && newValue >= 0 ? newValue : roriIsABadIA; saveProfil();}
    inline void setRoriScared(int newValue) { roriScared = newValue <= 100 && newValue >= 0 ? newValue : roriScared; saveProfil();}
    inline void setRoriMoral(int newValue) { roriMoral = newValue <= 100 && newValue >= 0 ? newValue : roriMoral; saveProfil();}

    inline QString getName() { return name; }
    inline QString getFirstName() { return firstName; }
    inline int getAge() { return age; }

    inline void setName(QString newValue) { name = newValue; saveProfil();}
    inline void setFirstName(QString newValue) { firstName = newValue; saveProfil();}
    inline void setAge(int newValue) { age = newValue; saveProfil();}

private:
    int roriHumor;
    int roriPolite;
    int roriJokes;
    int roriIsABadIA;
    int roriScared;
    int roriMoral;

    QString name;
    QString firstName;
    int age;
};


#endif // RORIPROFIL_H
