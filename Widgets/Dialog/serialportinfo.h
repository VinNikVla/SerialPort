#ifndef SERIALPORTINFO_H
#define SERIALPORTINFO_H

#include <QComboBox>
#include <QtSerialPort/QSerialPortInfo>
#include <QComboBox>
#include <QLabel>
#include <QLayout>
#include <QGroupBox>
#include <QIntValidator>
#include <QLineEdit>
#include <QString>
#include "Widgets/Dialog/serialportabstract.h"

static const char blankString[] = QT_TRANSLATE_NOOP("SerialPortINfo", "N/A");
class SerialPortInfo : public SerialPortAbstract
{
    Q_OBJECT

    QString m_name;

    QComboBox* serialPortInfoListBox = nullptr;
    QLabel* description = nullptr;
    QLabel* manufacturer = nullptr;
    QLabel* serialnumber = nullptr;
    QLabel* location = nullptr;
    QLabel* vendorID = nullptr;
    QLabel* productID = nullptr;


public:
    explicit SerialPortInfo(QWidget *parent = nullptr);
    QString getPortName() const;

private slots:
    void showPortsInfo(int index);
    void checkCustomDevicePathPolicy(int idx);

private:
    void fillPortsInfo();
    void createElements();



};

#endif // SERIALPORTINFO_H
