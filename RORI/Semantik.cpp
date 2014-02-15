#include "Semantik.h"

Semantik::Semantik() : QObject()
{

}

/**
 * @brief Semantik::saySomethingSlot
 * @param message
 */
void Semantik::saySomethingSlot(QString message)
{
    emit saySomething(message);
}

/**
 * @brief Semantik::getWords transform a QString in a QStringList with each words
 * @param sentence the sentence to transform
 * @return the QStringList with each words
 */
QStringList Semantik::getWords(QString sentence)
{
    QStringList toReturn;
    QString temp;
    QString separator = " ,;.!?-_";

    for(int i = 0; i < sentence.length(); ++i)
    {
        if(i < sentence.length() && separator.indexOf(sentence[i]) == -1)
        {
            temp += sentence[i];
            if(i == sentence.length() - 1)
                toReturn.append(temp);
        }
        else
        {
            if(!temp.isEmpty())
                toReturn.append(temp);
            temp.clear();
        }
    }

    return toReturn;
}
/**
 * @brief Semantik::workData treat the message
 * @param message
 */
void Semantik::workData(QString message)
{

}
