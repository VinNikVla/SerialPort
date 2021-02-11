#ifndef SETTINGSSERIALPORT_H
#define SETTINGSSERIALPORT_H

#include <QDialog>
#include "CPP/SerialPort/serial_common.h"
#include "serialportinfo.h"
#include "serialportproperty.h"
#include <QPushButton>

class SettingsSerialPort:public QDialog
{
    Q_OBJECT
public:
    explicit SettingsSerialPort(QWidget *parent = nullptr);

private slots:
    void apply();

signals:
    void newProperty(const PropertySerialPort& prop);

private:
    PropertySerialPort m_currentSettings;
    SerialPortInfo* m_infoAboutPort;
    SerialPortProperty* m_propertyPort;

    QGridLayout* mainLayout = nullptr;
    QGroupBox* createBox(const QString& name, const QList<QWidget*>* container);
    QPushButton* buttonApply = nullptr;

};

#endif // SETTINGSSERIALPORT_H
