#include "settingsserialport.h"

SettingsSerialPort::SettingsSerialPort(QWidget *parent):QDialog(parent),
    m_infoAboutPort(new SerialPortINfo(this)),
    m_propertyPort(new SerialPortProperty(this)),
    buttonApply(new QPushButton("Apply", this))
{

    connect(buttonApply, &QPushButton::clicked, this, &SettingsSerialPort::apply);

    mainLayout = new QGridLayout(this);

    mainLayout->addWidget(createInfoAboutPort(), 0, 0);
    mainLayout->addWidget(createPropertyPort(), 0, 1);
    mainLayout->addWidget(buttonApply, 5, 0, 5, 2);
    setLayout(mainLayout);
}

void SettingsSerialPort::apply()
{
    m_currentSettings = *m_propertyPort->getProperty();
    m_currentSettings.name = m_infoAboutPort->getPortName();

    emit newProperty(m_currentSettings);
    hide();
}

QGroupBox *SettingsSerialPort::createInfoAboutPort()
{
    QGroupBox* boxInfoAboutPort = new QGroupBox("Select Serial Port", this);

    QVBoxLayout* vLayout = new QVBoxLayout(this);

    for(auto itb = m_infoAboutPort->getElements()->begin(), ite = m_infoAboutPort->getElements()->end(); itb != ite; ++itb)
    {
        vLayout->addWidget(*itb);
    }

    boxInfoAboutPort->setLayout(vLayout);

    return boxInfoAboutPort;

}

QGroupBox *SettingsSerialPort::createPropertyPort()
{
    QGroupBox* boxPropertyPort = new QGroupBox("Select Parameters", this);

    QVBoxLayout* vLayout = new QVBoxLayout(this);

    for(auto itb = m_propertyPort->getElements()->begin(), ite = m_propertyPort->getElements()->end(); itb != ite; ++itb)
    {
        vLayout->addWidget(*itb);
    }

    boxPropertyPort->setLayout(vLayout);

    return boxPropertyPort;
}
