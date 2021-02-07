#ifndef DEVICE_H
#define DEVICE_H

#include <QObject>
#include <QThread>
#include <QString>
#include "CPP/Device/parserdevice.h"
//#include "CPP/SerialPort/serial_blocking.h"
#include "CPP/UnitsPageModel/valuemodel.h"
//#include "CPP/SerialPort/serial_common.h"
#include <QMap>
#include <QDebug>

class Device : public QObject
{
    Q_OBJECT


public:
    explicit Device(QObject *parent = nullptr);
    ValueModel* getValueModel(const QString& name) const;

signals:
    //нужно как-то обработать имя порта
    //будет типа раскрывающееся меню, а в нем доступные порты
    //как палитра в 2221-6

public slots:
    void DataChange(const StructDevice& dataDevice);
    //void setettingsComPort(const SerialProtocolPropertysStruct& property);
private:

    QMap<QString, ValueModel*> mainMap;
    ParserDevice* parser;
    //BlockComPort* comPortDevice;
    QString m_nameComPort;



};



#endif // DEVICE_H
