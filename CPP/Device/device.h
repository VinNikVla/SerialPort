#ifndef DEVICE_H
#define DEVICE_H

#include <QObject>
#include <QThread>
#include <QString>
#include "CPP/Device/parserdevice.h"
#include "CPP/UnitsPageModel/valuemodel.h"

#include <QMap>
#include <QDebug>
#include <QSerialPort>
#include "CPP/SerialPort/serial_common.h"

class Device : public QObject
{
    Q_OBJECT


public:
    explicit Device(QObject *parent = nullptr);
    ValueModel* getValueModel(const QString& name) const;

signals:
    void signalError(const QString& type, const QString& error);
    void signalMessage(const QString& msg);

    void signalStateOpen(bool state);
    void signalStateClose(bool state);

public slots:
    void DataChange(const StructDevice& dataDevice);
    void newProperty(const PropertySerialPort& prop);
    void closeSerialPort();
    void openSerialPort();

private slots:
    void readData();
    void handleError(QSerialPort::SerialPortError error);


private:

    QMap<QString, ValueModel*> mainMap;
    ParserDevice* m_parser;
    QSerialPort* m_serialPort;
    QString m_nameComPort;
    PropertySerialPort m_currentProperty;



};



#endif // DEVICE_H
