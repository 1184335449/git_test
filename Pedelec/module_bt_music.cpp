#include "module_bt_music.h"

Module_Bt_Music::Module_Bt_Music(QObject *parent) : QObject(parent)
{

}

Module_Bt_Music::~Module_Bt_Music()
{

}

void Module_Bt_Music::GetModuleData(char *ModuleData, int SendModuleID)
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
