#include "module_usb_video.h"

Module_USB_Video::Module_USB_Video(QObject *parent) : QObject(parent)
{

}

Module_USB_Video::~Module_USB_Video()
{

}

void Module_USB_Video::GetModuleData(char *ModuleData, int SendModuleID)
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
