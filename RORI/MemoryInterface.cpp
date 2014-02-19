#include "MemoryInterface.h"

#include <QTextStream>
#include <qdebug.h>

MemoryInterface::MemoryInterface() : QObject()
{

}

//TODOSend categorie to a PH1 Interface
/**
 * @brief MemoryInterface::sendCategorie
 */
void MemoryInterface::sendCategorie()
{
    QStringList categories;
    QString tempLine, fichier;
    QFile arborescenceFile("wordDir/arbo.txt");
    arborescenceFile.open(QIODevice::ReadWrite);
    if(arborescenceFile.isOpen())
    {
        fichier = arborescenceFile.readAll();
        for(int i = 0; i <= fichier.length(); ++i)
        {
            if(fichier[i] == '/' || fichier[i] == '\n')
            {
                if(categories.indexOf(tempLine) == -1)
                    categories.append(tempLine);
                tempLine = "";
            }
            else
                tempLine += fichier[i];
        }
        QString message;
        for(int i = 0; i < categories.length(); ++i)
        {
            message += categories.at(i);
            message += ",";
        }
    }
    else
    {
        QTextStream qout(stdout);
        qout << tr("Erreur lors de l'ouverture du fichier d'aborescence");
    }
}

//TODOSearch a line with the words
/**
 * @brief MemoryInterface::searchWord
 * @param mot1
 * @param mot2
 * @return
 */
QStringList MemoryInterface::searchWord(QString mot1, QString mot2)
{
    mot2 = "/" + mot2;
    QStringList phrasesRecuperer;
    QStringList categories;
    QFile arborescenceFile("wordDir/arbo.txt");
    arborescenceFile.open(QIODevice::ReadWrite);
    QString line;
    if(arborescenceFile.isOpen())
    {
        while(!arborescenceFile.atEnd())
        {
            line = arborescenceFile.readLine();
            if((line.indexOf(mot1) != -1 && line.indexOf(mot2) != -1) || (line.indexOf(mot1) != -1 || line.indexOf(mot2) != -1))
                phrasesRecuperer.append(line);
        }

        QStringList words;
        for(int i = 0; i < phrasesRecuperer.count(); ++i)
        {
            int j = 0, k = 0;
            QString temp;
            while(j < phrasesRecuperer.at(i).length())
            {
                if(phrasesRecuperer.at(i).at(j) != '/')
                    temp += phrasesRecuperer.at(i).at(j);
                else
                {
                    words.append(temp);
                    temp.clear();
                }

                if(j == phrasesRecuperer.at(i).length() - 1)
                {
                    words.append(temp);
                    temp.clear();
                }
                ++j;
            }

            while(k < words.count())
            {
                int indexOfWord = phrasesRecuperer.at(i).indexOf(words.at(k).trimmed());
                int indexOfCategorie;

                if(mot1 == "?")
                    indexOfCategorie = phrasesRecuperer.at(i).indexOf(mot2);
                else
                    indexOfCategorie = phrasesRecuperer.at(i).indexOf(mot1);

                if(indexOfWord < indexOfCategorie && mot1 == "?")
                    categories.append(words.at(k).trimmed());
                else if(indexOfWord >= indexOfCategorie && mot2 == "?")
                    categories.append(words.at(k).trimmed());

                ++k;
            }

        }
    }
    else
    {
        QTextStream qout(stdout);
        qout << tr("Erreur lors de l'ouverture du fichier d'aborescence");
    }

    return categories;
}

/**
 * @brief MemoryInterface::createFolder Create a folder, and write files into this folder (after we must move this file at his place)
 * @param path
 */
void MemoryInterface::createFolder(QString path)
{
    QDir *base = new QDir();
    QString direction(path);
    base->mkdir(direction);
}

/**
 * @brief MemoryInterface::createDefinition create a file for definition
 * @param nomPath
 * @param nomFichier
 * @param definition
 */
void MemoryInterface::createDefinition(QString nomPath, QString nomFichier, QString definition)
{
    QFile definitionFile(nomPath + "/" + nomFichier + "-def.txt");
    definitionFile.open(QIODevice::WriteOnly);
    if(definitionFile.isOpen())
    {
        QTextStream out(&definitionFile);
        out << definition.trimmed();
    }
    else
    {
        QTextStream qout(stdout);
        qout << "Error the programm can't create " + nomPath + "/" + nomFichier + "-def.txt";
    }
}

/**
 * @brief MemoryInterface::createSynonymeFile create a file for synonyme in path
 * @param nomPath
 * @param synonymes
 */
void MemoryInterface::createSynonymeFile(QString path, QStringList synonymes)
{
    for(int i = 0; i < synonymes.count(); ++i)
    {
        QFile defFile(path + "/" + synonymes.at(i) + ".syn");
        defFile.open(QIODevice::WriteOnly);
    }
}

/**
 * @brief MemoryInterface::moveFolder move folderToMove into intoThisFolder
 * @param folderToMove
 * @param intoThisFolder
 * @return
 */
QString MemoryInterface::moveFolder(QString folderToMove, QString intoThisFolder)
{
    QFile arborescenceFile("wordDir/arbo.txt");
    arborescenceFile.open(QIODevice::ReadWrite);
    QString line, pathOfIntoThisFolder = "wordDir/";
    if(arborescenceFile.isOpen())
    {
        while(!arborescenceFile.atEnd())
        {
            line = arborescenceFile.readLine();
            if(line.indexOf(intoThisFolder) != -1)
            {
                pathOfIntoThisFolder = "wordDir/";
                for(int i = 0; i < line.indexOf(intoThisFolder) + intoThisFolder.length(); ++i)
                {
                    pathOfIntoThisFolder += line[i];
                }
            }
        }

    }
    else
    {
        QTextStream qout(stdout);
        qout << tr("Erreur lors de l'ouverture du fichier d'aborescence");
    }

    return pathOfIntoThisFolder + "/" + folderToMove;
}

/**
 * @brief MemoryInterface::addPathToArboTxt add path into intoThisFolder
 * @param path
 * @param syn
 * @param intoThisFolder
 */
void MemoryInterface::addPathToArboTxt(QString path, QStringList syn, QString intoThisFolder)
{
    QFile arborescenceFile("wordDir/arbo.txt");
    arborescenceFile.open(QIODevice::ReadWrite);
    QString line, pathOfIntoThisFolder = "wordDir/", toWrite;
    bool contains = false, isWrite = false;
    if(arborescenceFile.isOpen())
    {
        while(!arborescenceFile.atEnd())
        {
            line = arborescenceFile.readLine();
            if(line.indexOf(intoThisFolder) != -1)
            {
                contains = true;
                pathOfIntoThisFolder = "";
                for(int i = 0; i < line.indexOf(intoThisFolder) + intoThisFolder.length(); ++i)
                {
                    pathOfIntoThisFolder += line[i];
                }
                toWrite = pathOfIntoThisFolder + "/" + path;
                for(int i = 0; i < syn.count(); ++i)
                {
                    toWrite += "\n" + pathOfIntoThisFolder + "/" + syn.at(i);
                }
            }
        }


        if(!isWrite)
        {
            QTextStream out(&arborescenceFile);
            out << toWrite;
        }
    }
    else
    {
        QTextStream qout(stdout);
        qout << tr("Erreur lors de l'ouverture du fichier d'aborescence");
    }
}

/**
 * @brief MemoryInterface::removeDir
 * @param aDir
 * @return remove aDir
 */
bool MemoryInterface::removeDir(QDir aDir)
{
    bool has_err = false;
    if (aDir.exists())
    {
        QFileInfoList entries = aDir.entryInfoList(QDir::NoDotAndDotDot | QDir::Dirs | QDir::Files);

        int count = entries.size();

        for (int idx = 0; ((idx < count) && !has_err); idx++)
        {
            QFileInfo entryInfo = entries[idx];
            QString path = entryInfo.absoluteFilePath();

            if (entryInfo.isDir())
                has_err = removeDir(QDir(path));
            else
            {
                QFile file(path);
                if (!file.remove())
                    has_err = true;
            }
        }

        if (!aDir.rmdir(aDir.absolutePath()))
        {
            QTextStream qout(stdout);
            qout << "Erreur de suppression de rép: " + aDir.absolutePath().toLatin1();
            has_err = true;
        }
    }
    return(has_err);
}

/**
 * @brief MemoryInterface::getCategorie
 * @param word to treat
 * @return the categorie of word
 */
QString MemoryInterface::getCategorie(QString word)
{
    QString toReturn = "(";
    QStringList temp = searchWord("?",word);
    for(int i = 0; i < temp.count(); ++i)
    {
        toReturn += temp.at(i);;
        toReturn += '|';
    }
    if(temp.count() == 0)
    {
        QFile *UnknownWords = new QFile("files/unknownWords");
        UnknownWords->open(QIODevice::ReadWrite);
        if(UnknownWords->isOpen())
        {
            QString file = UnknownWords->readAll();
            if(file.indexOf(word) == -1)
            {
                QTextStream out(UnknownWords);
                out << word + '\n';
            }
        }
    }

    toReturn.truncate(toReturn.length() - 1);
    toReturn += ")";

    return toReturn;
}

//TODO
QString MemoryInterface::getType(QString word)
{
    QString toReturn;
    Q_UNUSED(word);

    return toReturn;
}
