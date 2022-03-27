#include "module_dvr.h"
#include <QDebug>
Module_DVR::Module_DVR(QObject *parent) : QObject(parent)
{

}

Module_DVR::~Module_DVR()
{

}

void Module_DVR::GetModuleData(char *ModuleData, int SendModuleID)
{
    switch (SendModuleID)
    {
        case ModuleHomeID :
             qDebug()<<ModuleData;
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
