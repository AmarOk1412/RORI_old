#include "Semantik.h"

#include <QTextStream>
#include <QFile>

Semantik::Semantik() : QObject()
{
    profiler = new Profiler;
    memInt = new MemoryInterface;

    classicPaths.append("Regex/LDetermine/5");
    classicPaths.append("Regex/LDetermine/10");
    classicPaths.append("Regex/LDetermine/15");
    classicPaths.append("Regex/LDetermine/20");
    classicPaths.append("Regex/LDetermine/+");
    classicPaths.append("Regex/LIndetermine");
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
 * @brief Semantik::setCategoriesWords
 * @param words to treat
 * @return a QStringList contains the categorie of a list of words
 */
QStringList Semantik::setCategoriesWords(QStringList words)
{
    QStringList categorieList;

    for(int i = 0; i < words.count(); ++i)
        categorieList.append(memInt->getCategorie(words[i]));

    return categorieList;
}

/**
 * @brief Semantik::setTypesWords
 * @param words to treat
 * @return a QStringList contains the type of a list of words
 */
QStringList Semantik::setTypesWords(QStringList words)
{
    QStringList typesList;

    for(int i = 0; i < words.count(); ++i)
        typesList.append(memInt->getType(words[i]));

    return typesList;
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
    if(message.indexOf("TCHAT:") == 0)
    {
        //cut the 6 first letter
        QString receivedMessage;
        for(int i = 6; i < message.length(); ++i)
            receivedMessage += message[i];
        QTextStream qout(stdout);
        qout << tr("Message receive : ") + receivedMessage + '\n';

        //Put the message into history file
        QFile history("files/history");
        if(!history.exists())
        {
            history.open(QIODevice::ReadWrite);
            history.close();
        }
        history.open(QIODevice::Append);
        if(history.isOpen())
        {
            QTextStream out(&history);
            out << "\nMe : " + receivedMessage;
        }

        receivedMessage = receivedMessage.toLower();

        QStringList sentences;
        sentences = cutSentence(receivedMessage);

        //For each sentence
        for(int k = 0; k < sentences.count(); ++k)
        {
            QStringList words;
            words = getWords(sentences.at(k));
            QStringList categoriesWords;
            categoriesWords = setCategoriesWords(words);
            QStringList typesWords;
            typesWords = setTypesWords(words);

            bool regExpTrouve = false;
            QString funcToExecute;
            QString params;
            params = " ";
            QStringList toDo(activePaths);

            if(words.count() <= 5)
                toDo.append(classicPaths.at(0));
            else if(words.count() <= 10)
                toDo.append(classicPaths.at(1));
            else if(words.count() <= 15)
                toDo.append(classicPaths.at(2));
            else if(words.count() <= 20)
                toDo.append(classicPaths.at(3));
            else
                toDo.append(classicPaths.at(4));

            toDo.append(classicPaths.at(5));

            //Search a regex
            for(int o = 0; o < toDo.length(); ++o)
            {
                QFile file(toDo.at(o) + "/pathFunction");
                file.open(QIODevice::ReadWrite);
                QString tempPath;
                while(!regExpTrouve && !file.atEnd())
                {
                    tempPath = file.readLine();
                    QFile temp(toDo.at(o) + '/' + tempPath.trimmed());
                    temp.open(QIODevice::ReadOnly);
                    while(!regExpTrouve && !temp.atEnd())
                    {
                        QString regExpTest = temp.readLine().trimmed();
                        //Replace the word by the categorie of the word
                        if(!regExpTest.isEmpty())
                        {
                            int indexReplace = regExpTest.indexOf("--");
                            if(indexReplace != -1)
                            {
                                QString tempCate;
                                indexReplace += 2;
                                while(regExpTest[indexReplace] != '-' && indexReplace < regExpTest.length() - 1)
                                {
                                    tempCate += regExpTest[indexReplace];
                                    ++indexReplace;
                                }
                                QStringList temp = setCategoriesWords(words);
                                int indexCate = -1;
                                for(int z = 0; z < temp.count(); ++z)
                                {
                                    if(temp.at(z).indexOf(tempCate.toLower()) != -1)
                                        indexCate = z;
                                }
                                if(indexCate != -1)
                                {
                                    regExpTest.replace("--" + tempCate + "--", words.at(indexCate));
                                    params += "--" + words.at(indexCate) + "--";
                                }
                            }
                            if(sentences.at(k).toLower().indexOf(QRegExp(regExpTest)) != - 1)
                            {
                                regExpTrouve = true;
                                funcToExecute = temp.readLine().trimmed();
                            }
                            else
                                temp.readLine();
                        }
                    }
                }
            }
            if(!funcToExecute.isEmpty())
            {
                //On remplace --CATEGORIE-- par ce qu'il faut
                funcToExecute.replace("--SENTENCESEND--", receivedMessage);
                funcToExecute += params;
                profiler->workData(funcToExecute);
                receivedMessage.clear();
            }
            else if(!sentences.at(k).trimmed().isEmpty())//If we doesn't know the sentence
            {
                int nbLignes = 0;
                QFile *UnknownSentences = new QFile("files/unknownSentences");
                UnknownSentences->open(QIODevice::ReadWrite);
                if(UnknownSentences->isOpen())
                {
                    while(!UnknownSentences->atEnd())
                    {
                        UnknownSentences->readLine();
                        ++nbLignes;
                    }
                    QTextStream out(UnknownSentences);
                    out << receivedMessage + '\n';
                }

                int actiontoDo = 1;
                if(actiontoDo == 2)
                {
                    QFile *UnknownWord = new QFile("files/unknowWords");
                    UnknownWord->open(QIODevice::ReadWrite);
                    if(UnknownWord->isOpen())
                    {
                        int nbLines = 0;
                        while(!UnknownWord->atEnd())
                        {
                            UnknownWord->readLine();
                            ++nbLines;
                        }
                        if(nbLines == 0)
                            break;
                        int numMot = rand()%nbLines;
                        nbLines = 0;
                        UnknownWord->close();
                        UnknownWord->open(QIODevice::ReadWrite);
                        QString newFile;
                        while(nbLines < numMot)
                        {
                            newFile += UnknownWord->readLine();
                            ++nbLines;
                        }
                        newFile.truncate(newFile.length()-1);
                        QString word = UnknownWord->readLine();
                        while(!UnknownWord->atEnd())
                        {
                            newFile += UnknownWord->readLine();
                        }

                        UnknownWord->close();
                        UnknownWord->remove();
                        UnknownWord->open(QIODevice::ReadWrite);

                        QTextStream out(UnknownWord);
                        out << newFile;

                        /*TODOaddWord = new AddWord(word);
                        addWord->show();
                        connect(addWord, SIGNAL(sendWord(QString,QString,QString,QString)), this, SLOT(addWordSlot(QString,QString,QString,QString)));
                        */
                    }
                }
                else
                {
                    int ligne = rand()%nbLignes, i = 0;
                    UnknownSentences->close();
                    UnknownSentences->open(QIODevice::ReadOnly);
                    QString phraseNonConnue;
                    while(i < ligne)
                    {
                        UnknownSentences->readLine();
                        ++i;
                    }
                    phraseNonConnue = UnknownSentences->readLine();
                    //TODO what do you do in the event of this sentece ?
                }
                //TODO ask user
            }

            //TODO trier selon l'occurence
        }

    }
}
