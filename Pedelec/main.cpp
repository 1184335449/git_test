#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "mainobject.h"


static MainObject* mainobject = nullptr;
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    mainobject = new MainObject();

    return app.exec();
}
