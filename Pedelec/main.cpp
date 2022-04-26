#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "mainobject.h"
int main_cpp = 2;
int d = 0;


static MainObject* mainobject = nullptr;
int main(int argc, char *argv[])
{
    //EEE
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    mainobject = new MainObject();
    //aaaaaa


    //bbbbbbbbbbbbb
    //ccccc


    //dddd
    return app.exec();
}
