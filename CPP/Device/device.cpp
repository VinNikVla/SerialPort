#include "device.h"

Device::Device(QObject *parent) :
    QObject(parent),
    parser(new ParserDevice(this))
{
    mainMap["X"] = new ValueModel(this);
    mainMap["Y"] = new ValueModel(this);
    mainMap["Z"] = new ValueModel(this);
    mainMap["W"] = new ValueModel(this);
}

ValueModel *Device::getValueModel(const QString &name) const
{
    if(mainMap.contains(name))
    {
        qDebug() << "Подключение сигналов и слотов логика" << name;
        return mainMap[name];
    }

    qDebug() << "UNKNOWN KEY!!!" << name;
}


void Device::DataChange(const StructDevice &dataDevice)
{

    mainMap["X"]->setValue(dataDevice.x);
    mainMap["Y"]->setValue(dataDevice.y);
    mainMap["Z"]->setValue(dataDevice.z);
    mainMap["W"]->setValue(dataDevice.w);

}

//void Device::setettingsComPort(const SerialProtocolPropertysStruct &property)
//{

//}


