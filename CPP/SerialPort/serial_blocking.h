#pragma once

#include <QObject>
//#include <QSerialPort>
#include <QThread>
//#include "log.h"
#include "serial_common.h"

/*!
  \brief Класс BlockComPort

    Класс работает в блокирующем режиме, т.е. должен вызываться в отдельном потоке.

    \code BlockComPort* com=new BlockComPort(name,com_tm2404);
    QThread* thread = new QThread();
    com->moveToThread(thread);
    QObject::connect(com,&BlockComPort::newData,this,&DataBus::newData,Qt::QueuedConnection);
    QObject::connect(com,&BlockComPort::finish,this,&DataBus::comFinishWork);
    QObject::connect(this, &DataBus::stopAllThreads,com, &BlockComPort::deleteLater);
    QObject::connect(com, &BlockComPort::stop, thread, &QThread::deleteLater);
    thread->start();
    \endcode

    Для отправки данных на порт используется слот #executeCommand(QByteArray ba).
    Для особо задумчивых блоков (типа  TM2404 и TM2414) выгоднее использовать #executeCommandEx(QByteArray ba, int personalTimeout).
    В этом случае, для каждой команды устанавливается свой таймаут (см  #timeout(Command2437 com)).

    Результатом работы порта являются сигналы:
    -  #newData(QByteArray ba). Испускается в случае успешной работы порта. Подключаем к парсу ответа.
        Анализ работы устройства, подключенного к порту
    -  #finish(int comPortResultOfWork, QByteArray command). Испускается по окончанию работы порта , в том числе таймаут или нет ответа.
        Удобно применять в случаях, когда к одному порту подключены несколько (тем более разнотипных) устройств для быстрого анализа состояния самого порта - DataBus
*/

class BlockComPort : public QObject
{
    Q_OBJECT
public:
    BlockComPort(QString comPort, SerialProtocolPropertysStruct comProp, QObject *parent = nullptr); ///<  \param comPorts - имя порта. \param comProp - структура, описывающая параметры порта
    ~BlockComPort(); ///<корректно закрываем
    QString getPortName(); ///< получить имя порта
    enum  ComPortResultOfWork ///результат работы порта
    {
        CantOpenCom, ///<порт не может быть открыт
        Timeout,   ///<нет ответа, timeout
        ErrorWrite, ///<ошибка записи
        Unknown, ///<недокументированная ошибка
        OK ///<ошибок нет, все ОТЛИЧНО :)
    };
signals:
   // void Message(Log::LoggerMsg lm,  QString message); ///< Отправка сообщений в глобальный лог \param lm тип сообщения Log::LoggerMsg \param message текст сообщения
    void newData(QByteArray ba); ///< сигнал с массивом полученных данных для анализа \param ba - ответный массив байт
    void finish(int resultOfWork, QByteArray command); ///< сигнал с результатом работы порта.\param resultOfWork - BlockComPort::ComPortResultOfWork - результат работы \param command - команда, которая отправлялась через порт
    void stop(); ///< сигнал остановки порта. Нужен для закрытия потока, в котором крутится порт
public slots:
    void settings(const SerialProtocolPropertysStruct& property);
    void executeCommand(QByteArray ba); ///< слот отправки данных на порт
    void executeCommandEx(QByteArray ba, int personalTimeout); ///< слот отправки данных на порт, с индивидуальным таймаутом (в мс)
private:
    SerialProtocolPropertysStruct comProperty;
    QSerialPort* serialPort;
    int commonTimeout;
    void openCom();
    QString comPortName;
    quint8 comPortStillNotOpen=99;
    void execute(QByteArray ba, int  timeout);
};


