#ifndef MODULE_SETTING_H
#define MODULE_SETTING_H

#include <QObject>
#include "ModuleConfig.h"

class Module_Setting : public QObject
{
    Q_OBJECT
public:
    explicit Module_Setting(QObject *parent = nullptr);
    ~Module_Setting();

public slots:
    void GetModuleData(char *ModuleData,int SendModuleID);//获取其他模块数据

signals:
    void Sig_ModuleData(char *,int,int);
};

#endif // MODULE_SETTING_H
