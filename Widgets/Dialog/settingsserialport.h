#ifndef SETTINGSSERIALPORT_H
#define SETTINGSSERIALPORT_H

#include <QDialog>
#include <QtSerialPort/QSerialPort>
#include "CPP/SerialPort/serial_common.h"
#include <QComboBox>

class SettingsSerialPort:public QDialog
{
    Q_OBJECT
public:






    explicit SettingsSerialPort(QWidget *parent = nullptr);

//private slots:
//    void showPortInfo(int idx);
//    void apply();
//    void checkCustomBaudRatePolicy(int idx);
//    void checkCustomDevicePathPolicy(int idx);
//private:
//    void fillPortsParameters();
//    void fillPortsInfo();
//    void updateSettings();

private:
    QComboBox* serialPortInfoListBox = nullptr;
    PropertySerialPort m_currentSettings;

};

#endif // SETTINGSSERIALPORT_H
