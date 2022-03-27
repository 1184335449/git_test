#ifndef MODULE_DVR_H
#define MODULE_DVR_H

#include <QObject>
#include "ModuleConfig.h"

class Module_DVR : public QObject
{
    Q_OBJECT
public:
    explicit Module_DVR(QObject *parent = nullptr);
    ~Module_DVR();

public slots:
    void GetModuleData(char *ModuleData,int SendModuleID);//获取其他模块数据

signals:
    void Sig_ModuleData(char *,int,int);
};

#endif // MODULE_DVR_H
