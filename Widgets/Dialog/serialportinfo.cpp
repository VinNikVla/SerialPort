#include "serialportinfo.h"

SerialPortINfo::SerialPortINfo(QWidget *parent) : QWidget(parent)
{

    createElements();

    connect(serialPortInfoListBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &SerialPortINfo::showPortsInfo);
    connect(serialPortInfoListBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &SerialPortINfo::checkCustomDevicePathPolicy);


    fillPortsInfo();
    showPortsInfo(serialPortInfoListBox->currentIndex());

}

QString SerialPortINfo::getPortName() const
{
    qDebug() << "portinfo" << serialPortInfoListBox->currentText();
    return serialPortInfoListBox->currentText();
}

QList<QWidget *>*SerialPortINfo::getElements()
{
    return &listElements;
}

void SerialPortINfo::showPortsInfo(int index)
{
    if(index == -1)
        return;

    const QStringList list = serialPortInfoListBox->itemData(index).toStringList();


    description ->setText("Description: "         + (list.count() > 1 ? list.at(1) : blankString));
    manufacturer->setText("Manufacturer: "        + (list.count() > 2 ? list.at(2) : blankString));
    serialnumber->setText("Serial number: "       + (list.count() > 3 ? list.at(3) : blankString));
    location    ->setText("Location: "            + (list.count() > 4 ? list.at(4) : blankString));
    vendorID    ->setText("Vendor Identifier: "   + (list.count() > 5 ? list.at(5) : blankString));
    productID   ->setText("Product Identifier: "  + (list.count() > 6 ? list.at(6) : blankString));
}

void SerialPortINfo::checkCustomDevicePathPolicy(int idx)
{
    const bool isCustomPath = !serialPortInfoListBox->itemData(idx).isValid();
    serialPortInfoListBox->setEditable(isCustomPath);
    if (isCustomPath)
        serialPortInfoListBox->clearEditText();
}

void SerialPortINfo::fillPortsInfo()
{
    serialPortInfoListBox->clear();

    for(const auto& info : QSerialPortInfo::availablePorts())
    {
        QStringList list;

        list << info.portName()
             << (!info.description().isEmpty() ? info.description() : blankString)
             << (!info.manufacturer().isEmpty() ? info.manufacturer() : blankString)
             << (!info.manufacturer().isEmpty() ? info.serialNumber() : blankString)
             << info.systemLocation()
             << (info.vendorIdentifier() ? QString::number(info.vendorIdentifier(), 16) : blankString)
             << (info.productIdentifier() ? QString::number(info.productIdentifier(), 16) : blankString);

        serialPortInfoListBox->addItem(list.first(), list);
    }
    serialPortInfoListBox->addItem("Custom");

}

void SerialPortINfo::createElements()
{
    serialPortInfoListBox = new QComboBox(this);
    listElements.append(serialPortInfoListBox);

    description = new QLabel(this);
    listElements.append(description);

    manufacturer = new QLabel(this);
    listElements.append(manufacturer);

    serialnumber = new QLabel(this);
    listElements.append(serialnumber);

    location  = new QLabel(this);
    listElements.append(location);

    vendorID = new QLabel(this);
    listElements.append(vendorID);

    productID = new QLabel(this);
    listElements.append(productID);
}
