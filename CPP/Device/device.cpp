#include "device.h"

Device::Device(QObject *parent) :
    QObject(parent),
    parser(new ParserDevice(this)),
    m_serialPort(new QSerialPort(this))
{
    mainMap["X"] = new ValueModel(this);
    mainMap["Y"] = new ValueModel(this);
    mainMap["Z"] = new ValueModel(this);
    mainMap["W"] = new ValueModel(this);

    connect(parser, &ParserDevice::newData, this, &Device::DataChange);

    connect(m_serialPort, &QSerialPort::errorOccurred, this, &Device::handleError);
    connect(m_serialPort, &QSerialPort::readyRead, this, &Device::readData);
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

void Device::newProperty(const PropertySerialPort &prop)
{
    m_currentProperty = prop;

    if(!m_serialPort->isOpen())
    {
        m_serialPort->setPortName(prop.name);
        m_serialPort->setBaudRate(prop.baudRate);
        m_serialPort->setDataBits(prop.dataBits);
        m_serialPort->setParity(prop.parity);
        m_serialPort->setStopBits(prop.stopBits);
        m_serialPort->setFlowControl(prop.flowControl);
    }
}

void Device::readData()
{
    const QByteArray data = m_serialPort->readAll();
    parser->answer(data);
}

void Device::handleError(QSerialPort::SerialPortError error)
{
    if(error == QSerialPort::ResourceError)
    {
        emit signalError("Critical Error", m_serialPort->errorString());
        closeSerialPort();
    }
}

void Device::closeSerialPort()
{
    if(m_serialPort->isOpen())
    {
        m_serialPort->close();
    }

    signalStateClose(m_serialPort->isOpen());
    signalMessage("Disconnect");
}

void Device::openSerialPort()
{
    if(m_serialPort->open(QIODevice::ReadOnly))
    {
        emit signalMessage("Connected to: \n" + toString(m_currentProperty));
    }
    else
    {
        emit signalError("Error", m_serialPort->errorString());
        emit signalMessage("Open Error");
    }

    emit signalStateOpen(m_serialPort->isOpen());

}

