#include "serialportproperty.h"

SerialPortProperty::SerialPortProperty(QWidget *parent) : QWidget(parent)
{

    baudRate =  new LabelWithBox("Baud Rate:", this);
    fillBaudRate();
    list.append(baudRate);

    dataBits = new LabelWithBox("Data Bits:", this);
    fillDataBits();
    list.append(dataBits);

    parity = new LabelWithBox("Parity:", this);
    fillParity();
    list.append(parity);

    stopBits = new LabelWithBox("Stop Bits:", this);
    fillStopBits();
    list.append(stopBits);

    flowCotrol = new LabelWithBox("Flow Control:", this);
    fillFlowControl();
    list.append(flowCotrol);


}

QList<QWidget *> *SerialPortProperty::getElements()
{
    return &list;
}

PropertySerialPort *SerialPortProperty::getProperty()
{
    m_property.baudRate = static_cast<QSerialPort::BaudRate>(baudRate->itemData());
    m_property.stringBaudRate = QString::number(m_property.baudRate);
    qDebug() << m_property.stringBaudRate;

    m_property.dataBits = static_cast<QSerialPort::DataBits>(dataBits->itemData());
    m_property.stringDataBits = QString::number(m_property.dataBits);
    qDebug() << m_property.stringDataBits;

    m_property.parity = static_cast<QSerialPort::Parity>(parity->itemData());
    m_property.stringParity = parity->currentText();
    qDebug() << m_property.stringParity;

    m_property.stopBits = static_cast<QSerialPort::StopBits>(stopBits->itemData());
    m_property.stringStopBits = stopBits->currentText();
    qDebug() << m_property.stringStopBits;

    m_property.flowControl = static_cast<QSerialPort::FlowControl>(flowCotrol->itemData());
    m_property.stringFlowControl = flowCotrol->currentText();
    qDebug() << m_property.stringFlowControl;

    return &m_property;
}

void SerialPortProperty::fillBaudRate()
{
    baudRate->addItem(QStringLiteral("1200"), QSerialPort::Baud1200);
    baudRate->addItem(QStringLiteral("2400"), QSerialPort::Baud2400);
    baudRate->addItem(QStringLiteral("4800"), QSerialPort::Baud4800);
    baudRate->addItem(QStringLiteral("9600"), QSerialPort::Baud9600);
    baudRate->addItem(QStringLiteral("19200"), QSerialPort::Baud19200);
    baudRate->addItem(QStringLiteral("38400"), QSerialPort::Baud38400);
    baudRate->addItem(QStringLiteral("57600"), QSerialPort::Baud57600);
    baudRate->addItem(QStringLiteral("115200"), QSerialPort::Baud115200);
}

void SerialPortProperty::fillDataBits()
{
    dataBits->addItem(QStringLiteral("5"), QSerialPort::Data5);
    dataBits->addItem(QStringLiteral("6"), QSerialPort::Data6);
    dataBits->addItem(QStringLiteral("7"), QSerialPort::Data7);
    dataBits->addItem(QStringLiteral("8"), QSerialPort::Data8);
}

void SerialPortProperty::fillParity()
{
    parity->addItem(tr("None"), QSerialPort::NoParity);
    parity->addItem(tr("Even"), QSerialPort::EvenParity);
    parity->addItem(tr("Odd"), QSerialPort::OddParity);
    parity->addItem(tr("Mark"), QSerialPort::MarkParity);
    parity->addItem(tr("Space"), QSerialPort::SpaceParity);
}

void SerialPortProperty::fillStopBits()
{
    stopBits->addItem(QStringLiteral("1"), QSerialPort::OneStop);
    stopBits->addItem(QStringLiteral("2"), QSerialPort::TwoStop);
}

void SerialPortProperty::fillFlowControl()
{
    flowCotrol->addItem(tr("None"), QSerialPort::NoFlowControl);
    flowCotrol->addItem(tr("RTS/CTS"), QSerialPort::HardwareControl);
    flowCotrol->addItem(tr("XON/XOFF"), QSerialPort::SoftwareControl);
}

