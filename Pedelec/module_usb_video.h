#ifndef MODULE_USB_VIDEO_H
#define MODULE_USB_VIDEO_H

#include <QObject>
#include "ModuleConfig.h"

class Module_USB_Video : public QObject
{
    Q_OBJECT
public:
    explicit Module_USB_Video(QObject *parent = nullptr);
    ~Module_USB_Video();

public slots:
    void GetModuleData(char *ModuleData,int SendModuleID);//获取其他模块数据

signals:
    void Sig_ModuleData(char *,int,int);
};

#endif // MODULE_USB_VIDEO_H
