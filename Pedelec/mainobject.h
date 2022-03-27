#ifndef MAINOBJECT_H
#define MAINOBJECT_H
#include <QObject>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include <QQmlContext>
#include "module_communication.h"
#include "module_home.h"
#include "module_usb_music.h"
#include "module_bt_music.h"
#include "module_carlink.h"
#include "module_setting.h"
#include "module_usb_video.h"
#include "module_dvr.h"
#include "ModuleConfig.h"

class MainObject : public QObject
{
    Q_OBJECT
public:
    explicit MainObject(QObject *parent = nullptr);
    ~MainObject();
    void QmlInit();//QML初始化
    void ModuleInit();//模块初始化

public slots:
    void ModuleInteraction(char *ModuleData,int SendModuleID,int ReceModuleID);//模块数据交互 SendModuleID:发送端ID   ReceModuleID:接收端ID

signals:
    void Sig_ToBTMusic(char *,int);
    void Sig_ToCarlink(char *,int);
    void Sig_ToCommunication(char *,int);
    void Sig_ToDvr(char *,int);
    void Sig_ToHome(char *,int);
    void Sig_ToSetting(char *,int);
    void Sig_ToUsbMusic(char *,int);
    void Sig_ToUsbVideo(char *,int);

private:
    QQmlApplicationEngine qml_engine;
    Module_Home *module_home;
    Module_Communication *module_communication;
    Module_USB_Music *module_usb_music;
    Module_Bt_Music *module_bt_music;
    Module_Carlink *module_carlink;
    Module_Setting *module_setting;
    Module_USB_Video *module_usb_video;
    Module_DVR *module_dvr;
};

#endif // MAINOBJECT_H
