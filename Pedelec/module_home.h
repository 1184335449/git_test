#ifndef MODULE_HOME_H
#define MODULE_HOME_H

#include <QObject>
#include "ModuleConfig.h"
#include "QTimer"

class Module_Home : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString qml_color READ qml_color WRITE setColor NOTIFY colorChanged)
public:
    explicit Module_Home(QObject *parent = nullptr);
    ~Module_Home();
    Q_INVOKABLE void home_open();
    QString qml_color();
    void setColor(QString color);

public slots:
    void GetModuleData(char *ModuleData,int SendModuleID);//获取其他模块数据

signals:
    void Sig_ModuleData(char *,int,int);
    void colorChanged();

private:
    QString mycolor;
};

#endif // MODULE_HOME_H
