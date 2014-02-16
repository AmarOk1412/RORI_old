#include "Semantik.h"

Semantik::Semantik() : QObject()
{
    classicPaths.append("/Regex/LDetermine/5");
    classicPaths.append("/Regex/LDetermine/10");
    classicPaths.append("/Regex/LDetermine/15");
    classicPaths.append("/Regex/LDetermine/20");
    classicPaths.append("/Regex/LDetermine/+");
    classicPaths.append("/Regex/LIndetermine");
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
 * @brief Semantik::cutSentence
 * @param sentences
 * @return a QStringList with all sentence in sentences
 */
QStringList Semantik::cutSentence(QString sentences)
{
    QStringList toReturn;
    QString temp;
    QString separator = ",;.!?-_";

    for(int i = 0; i < sentences.length(); ++i)
    {
        if(i < sentences.length() && separator.indexOf(sentences[i]) == -1)
        {
            temp += sentences[i];
            if(i == sentences.length() - 1)
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
 * @brief Semantik::addNewFilePath a path in the arbo to treat
 * @param newPath
 */
void Semantik::addNewFilePath(QString newPath)
{
    activePaths.append(newPath);
}

//TODO : del path into activPaths
void Semantik::delFilePath(QString path)
{
    Q_UNUSED(path)
    //Not implemented Yet
}

/**
 * @brief Semantik::workData treat the message
 * @param message
 */
void Semantik::workData(QString message)
{
    Q_UNUSED(message);
}
