#ifndef MODULE_BT_MUSIC_H
#define MODULE_BT_MUSIC_H

#include <QObject>
#include "ModuleConfig.h"

class Module_Bt_Music : public QObject
{
    Q_OBJECT
public:
    explicit Module_Bt_Music(QObject *parent = nullptr);
    ~Module_Bt_Music();

public slots:
    void GetModuleData(char *ModuleData,int SendModuleID);//获取其他模块数据

signals:
    void Sig_ModuleData(char *,int,int);
};

#endif // MODULE_BT_MUSIC_H
