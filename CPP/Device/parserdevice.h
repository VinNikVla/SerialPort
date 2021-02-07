#ifndef PARSERDEVICE_H
#define PARSERDEVICE_H

#include <QObject>
#include "CPP/Device/structdevice.h"
#include "QByteArray"

class ParserDevice : public QObject
{
    Q_OBJECT
public:
    explicit ParserDevice(QObject *parent = nullptr);

signals:
    void DataNoChanged();
    void newData(const StructDevice& dataDevice);

public slots:
    void answer(QByteArray ba);

private:
    StructDevice m_data;

};

#endif // PARSERDEVICE_H
