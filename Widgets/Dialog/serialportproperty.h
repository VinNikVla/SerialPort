#ifndef SERIALPORTPROPERTY_H
#define SERIALPORTPROPERTY_H

#include "Widgets/View/labelwithbox.h"
#include "CPP/SerialPort/serial_common.h"
#include "Widgets/Dialog/serialportabstract.h"
#include <QSerialPort>
#include <QGroupBox>

class SerialPortProperty : public SerialPortAbstract
{
    Q_OBJECT

    LabelWithBox* baudRate = nullptr;
    LabelWithBox* dataBits = nullptr;
    LabelWithBox* parity = nullptr;
    LabelWithBox* stopBits = nullptr;
    LabelWithBox* flowCotrol = nullptr;

public:
    explicit SerialPortProperty(QWidget *parent = nullptr);
    PropertySerialPort* getProperty();

private:
    void fillBaudRate();
    void fillDataBits();
    void fillParity();
    void fillStopBits();
    void fillFlowControl();
    PropertySerialPort m_property;
};

#endif // SERIALPORTPROPERTY_H
