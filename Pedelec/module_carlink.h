#ifndef MODULE_CARLINK_H
#define MODULE_CARLINK_H

#include <QObject>
#include "ModuleConfig.h"

class Module_Carlink : public QObject
{
    Q_OBJECT
public:
    explicit Module_Carlink(QObject *parent = nullptr);
    ~Module_Carlink();

public slots:
    void GetModuleData(char *ModuleData,int SendModuleID);//获取其他模块数据

signals:
    void Sig_ModuleData(char *,int,int);
};

#endif // MODULE_CARLINK_H
