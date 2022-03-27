#include "module_home.h"
#include "QDebug"
Module_Home::Module_Home(QObject *parent) : QObject(parent)
{
    mycolor = "blue";
}

Module_Home::~Module_Home()
{

}

void Module_Home::GetModuleData(char *ModuleData, int SendModuleID)
{
    switch (SendModuleID)
    {
        case ModuleHomeID :

            break;
        case ModuleCommunicationID :

            break;
        case ModuleUsbMusicID :

            break;
        case ModuleBtMusicID :

            break;
        case ModuleCarLinkID :

            break;
        case ModuleSettingID :

            break;
        case ModuleUsbVideoID :

            break;
        case ModuleDvrID :

            break;
        default :
            break;
    }
}

void Module_Home::home_open()
{
    qDebug()<<"Home_open\r\n";
    char *test_data = "ModuleHome ->ModuleDvr";
    emit Sig_ModuleData(test_data,ModuleHomeID,ModuleDvrID);
}

QString Module_Home::qml_color()
{
    qDebug() << "read color";
    return mycolor;
}

void Module_Home::setColor(QString color)
{
    if(mycolor != color)
    {
        qDebug() << "write color";
        mycolor = color;
        emit colorChanged();
    }
}
