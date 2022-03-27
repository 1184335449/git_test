#include "module_setting.h"

Module_Setting::Module_Setting(QObject *parent) : QObject(parent)
{

}

Module_Setting::~Module_Setting()
{

}

void Module_Setting::GetModuleData(char *ModuleData, int SendModuleID)
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
