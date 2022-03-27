#include "module_communication.h"

Module_Communication::Module_Communication(QObject *parent) : QObject(parent)
{
    socket = new QTcpSocket();
    //连接信号槽
    QObject::connect(socket, &QTcpSocket::readyRead, this, &Module_Communication::readData);

    //取消已有的连接
    socket->abort();
    //连接服务器
    socket->connectToHost("172.18.0.189", 8888);
    //等待连接成功
    if(!socket->waitForConnected(300))
    {
        qDebug() << "Connection failed!";
        return;
    }
    qDebug() << "Connect successfully!";

}

void Module_Communication::readData()
{

    QByteArray buffer;
    //读取缓冲区数据
    buffer = socket->readAll();
    if(!buffer.isEmpty())
    {
        buf = buf.prepend(buffer);
        emit readDataChanged(buf);
    }
}
Module_Communication::~Module_Communication()
{

}

void Module_Communication::GetModuleData(char *ModuleData, int SendModuleID)
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
