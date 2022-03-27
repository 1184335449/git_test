#include "mainobject.h"
#include <QDebug>
int mainobject_cpp = 1;
int a=0;
int b=0;


MainObject::MainObject(QObject *parent) : QObject(parent)
{
    ModuleInit();
    QmlInit();

}

MainObject::~MainObject()
{
    delete module_home;
}

void MainObject::QmlInit()
{
    QQmlContext *ctx = qml_engine.rootContext();
    if(ctx!=nullptr){
        ctx->setContextProperty("module_home",module_home);
        ctx->setContextProperty("module_communication",module_communication);
        ctx->setContextProperty("module_usb_music",module_usb_music);
        ctx->setContextProperty("module_bt_music",module_bt_music);
        ctx->setContextProperty("module_carlink",module_carlink);
        ctx->setContextProperty("module_setting",module_setting);
        ctx->setContextProperty("module_usb_video",module_usb_video);
        ctx->setContextProperty("module_dvr",module_dvr);
    }
    qml_engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

}

void MainObject::ModuleInit()
{
     module_home = new Module_Home();
     module_communication = new Module_Communication();
     module_usb_music = new Module_USB_Music();
     module_bt_music  = new Module_Bt_Music();
     module_carlink   = new Module_Carlink();
     module_setting   = new Module_Setting();
     module_usb_video = new Module_USB_Video();
     module_dvr       = new Module_DVR();

     connect(module_home, SIGNAL(Sig_ModuleData(char *,int,int)), this, SLOT(ModuleInteraction(char *,int,int)));
     connect(module_communication, SIGNAL(Sig_ModuleData(char *,int,int)), this, SLOT(ModuleInteraction(char *,int,int)));
     connect(module_usb_music, SIGNAL(Sig_ModuleData(char *,int,int)), this, SLOT(ModuleInteraction(char *,int,int)));
     connect(module_bt_music, SIGNAL(Sig_ModuleData(char *,int,int)), this, SLOT(ModuleInteraction(char *,int,int)));
     connect(module_carlink, SIGNAL(Sig_ModuleData(char *,int,int)), this, SLOT(ModuleInteraction(char *,int,int)));
     connect(module_setting, SIGNAL(Sig_ModuleData(char *,int,int)), this, SLOT(ModuleInteraction(char *,int,int)));
     connect(module_usb_video, SIGNAL(Sig_ModuleData(char *,int,int)), this, SLOT(ModuleInteraction(char *,int,int)));
     connect(module_dvr, SIGNAL(Sig_ModuleData(char *,int,int)), this, SLOT(ModuleInteraction(char *,int,int)));


     connect(this, SIGNAL(Sig_ToBTMusic(char *,int)), module_bt_music, SLOT(GetModuleData(char *,int)));
     connect(this, SIGNAL(Sig_ToCarlink(char *,int)), module_carlink, SLOT(GetModuleData(char *,int)));
     connect(this, SIGNAL(Sig_ToCommunication(char *,int)), module_communication, SLOT(GetModuleData(char *,int)));
     connect(this, SIGNAL(Sig_ToDvr(char *,int)), module_dvr, SLOT(GetModuleData(char *,int)));
     connect(this, SIGNAL(Sig_ToHome(char *,int)), module_home, SLOT(GetModuleData(char *,int)));
     connect(this, SIGNAL(Sig_ToSetting(char *,int)), module_setting, SLOT(GetModuleData(char *,int)));
     connect(this, SIGNAL(Sig_ToUsbMusic(char *,int)), module_usb_music, SLOT(GetModuleData(char *,int)));
     connect(this, SIGNAL(Sig_ToUsbVideo(char *,int)), module_usb_video, SLOT(GetModuleData(char *,int)));
}

void MainObject::ModuleInteraction(char *ModuleData,int SendModuleID,int ReceModuleID)
{
    switch (ReceModuleID)
    {
        case ModuleHomeID :
                emit Sig_ToHome(ModuleData,SendModuleID);
            break;
        case ModuleCommunicationID :
                emit Sig_ToCommunication(ModuleData,SendModuleID);
            break;
        case ModuleUsbMusicID :
                emit Sig_ToUsbMusic(ModuleData,SendModuleID);
            break;
        case ModuleBtMusicID :
                emit Sig_ToBTMusic(ModuleData,SendModuleID);
            break;
        case ModuleCarLinkID :
                emit Sig_ToCarlink(ModuleData,SendModuleID);
            break;
        case ModuleSettingID :
                emit Sig_ToSetting(ModuleData,SendModuleID);
            break;
        case ModuleUsbVideoID :
                emit Sig_ToUsbVideo(ModuleData,SendModuleID);
            break;
        case ModuleDvrID :
                emit Sig_ToDvr(ModuleData,SendModuleID);
            break;
        default :
            break;
    }
}
