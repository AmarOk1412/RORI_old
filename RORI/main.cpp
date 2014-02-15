#include <QCoreApplication>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>

#include "RORI.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QString locale = QLocale::system().name();
    QTranslator translator;
    translator.load(QString("qt_") + locale, QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    app.installTranslator(&translator);
    app.setApplicationName("RORI v2.1");

    srand(time(NULL));

    RORI Rori;

    return app.exec();
}
