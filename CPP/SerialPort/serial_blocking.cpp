#include "serial_blocking.h"

BlockComPort::BlockComPort(QString comPort, SerialProtocolPropertysStruct comProp, QObject *parent) :
    QObject(parent),
    comProperty(comProp),
    serialPort(new QSerialPort(this)),
    comPortName(comPort)
{
    openCom();
}

BlockComPort::~BlockComPort()
{
    serialPort->close();
    emit stop();
}

QString BlockComPort::getPortName()
{
    return comPortName;
}

void BlockComPort::executeCommand(QByteArray ba)
{
    execute(ba,commonTimeout);
}

void BlockComPort::executeCommandEx(QByteArray ba, int personalTimeout)
{
    execute(ba,personalTimeout);
}

void BlockComPort::openCom()
{
    serialPort->setPortName(comPortName);
    serialPort->setBaudRate(comProperty.baudrate);
    serialPort->setDataBits(comProperty.databits);
    serialPort->setParity(comProperty.parity);
    serialPort->setStopBits(comProperty.stopBits);
    serialPort->setFlowControl(comProperty.flow);
    commonTimeout=comProperty.timeout;
    if (!serialPort->open(QIODevice::ReadWrite))
    {
        comPortStillNotOpen++;
        if (comPortStillNotOpen>=100)
        {
            emit Message(Log::Info,QString("COM %1: Не удалось открыть СОМ-порт ").arg(serialPort->portName())+serialPort->errorString());
            comPortStillNotOpen=0;
        }

    }   else
    {
        emit Message(Log::Info,QString("COM %1: СОМ-порт открыт.").arg(serialPort->portName()));
        comPortStillNotOpen=99;
    }
}

//короче он должен возвращать еще и саму команду
void BlockComPort::execute(QByteArray ba, int timeout)
{
    if (serialPort->isOpen())
    {
       serialPort->write(ba);
       serialPort->readAll(); //предварительно почистили входной буфер
       if (serialPort->waitForBytesWritten(timeout))
       {
           if  (serialPort->waitForReadyRead(timeout))
           {
               QByteArray answ=(serialPort->readAll());
               while (serialPort->waitForReadyRead(5))  //на мелком компе больше 8 байт  не проходит за 1 раз
               {
                   answ.append(serialPort->readAll());
               }
               if (answ.size()>0)
               {
                   emit newData(answ);
                   emit finish(ComPortResultOfWork::OK,ba);
               }
               else finish(ComPortResultOfWork::Unknown,ba);
           }
           else
           {
               emit Message(Log::Warning,QString("COM %1: Тайм-аут ответа").arg(serialPort->portName()));
               emit finish(ComPortResultOfWork::Timeout,ba);
           }
       }
       else
       {
           emit Message(Log::Warning,QString("COM %1: Ошибка записи в порт %2").arg(
                            serialPort->portName(),
                            serialPort->errorString()));
           emit finish(ComPortResultOfWork::ErrorWrite,ba);
      }
    }
    else {
        emit finish(ComPortResultOfWork::CantOpenCom,ba);
        openCom();
    }
}


