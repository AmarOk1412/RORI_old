#include <QApplication>
#include <QTranslator>
#include <QLibraryInfo>
#include <QMessageBox>

#include "Interface.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    QString locale = QLocale::system().name();
    QTranslator translator;
    translator.load(QString("qt_") + locale, QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    app.installTranslator(&translator);
    app.setApplicationName("RORI");
    app.setQuitOnLastWindowClosed(true);

    Interface interface;
    interface.show();

    return app.exec();
}
