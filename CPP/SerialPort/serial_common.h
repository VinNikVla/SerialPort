#pragma once

#include <QSerialPort>

struct SerialProtocolPropertysStruct /// структура, хранящая настройки порта для сопряжения с различными системами
{
    QString name;
    QSerialPort::BaudRate baudrate;
    QSerialPort::DataBits databits;
    QSerialPort::Parity parity;
    QSerialPort::StopBits stopBits;
    QSerialPort::FlowControl flow;
};
