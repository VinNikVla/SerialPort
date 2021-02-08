//#include "serialportinfo.h"

//SerialPortINfo::SerialPortINfo(QWidget *parent) : QWidget(parent)
//{
//    QGroupBox* infoAboutPort = new QGroupBox("Select Serial Port", this);


//    serialPortInfoListBox = new QComboBox(this);
//    description = new QLabel(this);
//    manufacturer = new QLabel(this);
//    serialnumber = new QLabel(this);
//    location  = new QLabel(this);
//    vendorID = new QLabel(this);
//    productID = new QLabel(this);



//    connect(serialPortInfoListBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
//            this, &SerialPortINfo::showPortsInfo);





//    fillPortsInfo();
//    showPortsInfo(serialPortInfoListBox->currentIndex());

//    QVBoxLayout* layout = new QVBoxLayout(this);

//    layout->addWidget(serialPortInfoListBox);
//    layout->addWidget(description);
//    layout->addWidget(manufacturer);
//    layout->addWidget(serialnumber);
//    layout->addWidget(location);
//    layout->addWidget(vendorID);
//    layout->addWidget(productID);

//    infoAboutPort->setLayout(layout);
//}

//void SerialPortINfo::showPortsInfo(int index)
//{
//    if(index == -1)
//        return;

//    const QStringList list = serialPortInfoListBox->itemData(index).toStringList();


//    description ->setText("Description: "         + (list.count() > 1 ? list.at(1) : blankString));
//    manufacturer->setText("Manufacturer: "        + (list.count() > 2 ? list.at(2) : blankString));
//    serialnumber->setText("Serial number: "       + (list.count() > 3 ? list.at(3) : blankString));
//    location    ->setText("Location: "            + (list.count() > 4 ? list.at(4) : blankString));
//    vendorID    ->setText("Vendor Identifier: "   + (list.count() > 5 ? list.at(5) : blankString));
//    productID   ->setText("Product Identifier: "  + (list.count() > 6 ? list.at(6) : blankString));
//}

//void SerialPortINfo::fillPortsInfo()
//{
//    serialPortInfoListBox->clear();

//    for(const auto& info : QSerialPortInfo::availablePorts())
//    {
//        QStringList list;

//        list << info.portName()
//             << (!info.description().isEmpty() ? info.description() : blankString)
//             << (!info.manufacturer().isEmpty() ? info.manufacturer() : blankString)
//             << (!info.manufacturer().isEmpty() ? info.serialNumber() : blankString)
//             << info.systemLocation()
//             << (info.vendorIdentifier() ? QString::number(info.vendorIdentifier(), 16) : blankString)
//             << (info.productIdentifier() ? QString::number(info.productIdentifier(), 16) : blankString);

//        serialPortInfoListBox->addItem(list.first(), list);
//    }
//    serialPortInfoListBox->addItem("Custom");

//}
