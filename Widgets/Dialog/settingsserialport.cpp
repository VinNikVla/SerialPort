#include "settingsserialport.h"

SettingsSerialPort::SettingsSerialPort(QWidget *parent):QDialog(parent),
    m_infoAboutPort(new SerialPortInfo(this)),
    m_propertyPort(new SerialPortProperty(this)),
    buttonApply(new QPushButton("Apply", this))
{

    connect(buttonApply, &QPushButton::clicked, this, &SettingsSerialPort::apply);

    mainLayout = new QGridLayout(this);

    mainLayout->addWidget(createBox("Select Serial Port", m_infoAboutPort->getElements()), 0, 0);
    mainLayout->addWidget(createBox("Select Parameters", m_propertyPort->getElements()), 0, 1);
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

QGroupBox *SettingsSerialPort::createBox(const QString &name, const QList<QWidget *> *container)
{
    QGroupBox* box = new QGroupBox(name, this);

    QVBoxLayout* vLayout = new QVBoxLayout(this);

    for(auto itb = container->begin(), ite = container->end(); itb != ite; ++itb)
    {
        vLayout->addWidget(*itb);
    }

    box->setLayout(vLayout);

    return box;

}

