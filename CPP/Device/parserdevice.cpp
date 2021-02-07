#include "parserdevice.h"

ParserDevice::ParserDevice(QObject *parent) : QObject(parent)
{

}

void ParserDevice::answer(QByteArray ba)
{
    if(ba.size() != 17)
    {
        qDebug() << "Неизвестный ответ!!!";
        return;
    }


    QDataStream ds(&ba, QIODevice::ReadOnly);

    quint8 tmp;
    ds >> tmp;

    if(tmp != DeviceCommand::PREFIX)
    {
        qDebug() << "Неверный префикс!!!";
        return;
    }


    ds >> m_data;
    qDebug() << m_data;
    emit newData(m_data);



}
