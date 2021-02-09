#ifndef SERIALPORTPROPERTY_H
#define SERIALPORTPROPERTY_H

#include <QWidget>
#include "Widgets/View/labelwithbox.h"
#include "CPP/SerialPort/serial_common.h"
#include <QSerialPort>
#include <QGroupBox>

class SerialPortProperty : public QWidget
{
    Q_OBJECT
    LabelWithBox* baudRate = nullptr;
    LabelWithBox* dataBits = nullptr;
    LabelWithBox* parity = nullptr;
    LabelWithBox* stopBits = nullptr;
    LabelWithBox* flowCotrol = nullptr;

public:
    explicit SerialPortProperty(QWidget *parent = nullptr);
    QList<QWidget*>* getElements();
    PropertySerialPort* getProperty();

signals:

public slots:

private:
    void fillBaudRate();
    void fillDataBits();
    void fillParity();
    void fillStopBits();
    void fillFlowControl();
    PropertySerialPort m_property;
    QList<QWidget*> list;
};

#endif // SERIALPORTPROPERTY_H
