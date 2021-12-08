#include "mainwindow.h"

#include <QApplication>
#include <QStringList>
#include <QString>
#include <QLocale>
#include <QTranslator>
#include <QFileInfo>
#include <QDebug>
#include "message.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QStringList languages = QLocale().uiLanguages();// e.g. ("en-US")
    if (languages.size()) {
        QString language =languages.at(0);
        QString qmFile = QString("../message-in-a-parachute/message-in-a-parachute-%1.qm").arg(language);
        if (QFileInfo(qmFile).exists()) {
            QTranslator * translator = new QTranslator(&a);
            translator->load(qmFile);
            a.installTranslator(translator);
        }
    }
    MainWindow w;
    w.show();
    return a.exec();
}
