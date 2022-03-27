#ifndef MODULE_COMMUNICATION_H
#define MODULE_COMMUNICATION_H

#include <QObject>
#include <QTcpSocket>
#include "ModuleConfig.h"

class Module_Communication : public QObject
{
    Q_OBJECT
public:
    explicit Module_Communication(QObject *parent = nullptr);
    ~Module_Communication();
    QString buf;

public slots:
    void GetModuleData(char *ModuleData,int SendModuleID);//获取其他模块数据

signals:
     void readDataChanged(QString data);
     void Sig_ModuleData(char *,int,int);
private slots:
   Q_INVOKABLE  void readData();

private:
    QTcpSocket *socket;

};

#endif // MODULE_COMMUNICATION_H
