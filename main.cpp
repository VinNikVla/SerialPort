#include "mainwindow.h"
#include <QApplication>
#include "CPP/Device/device.h"
#include "Widgets/View/view.h"
#include "CPP/UnitsPageModel/valuemodel.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Device* mainDevice = new Device(&a);

    MainWindow w;

    QObject::connect(&w, &MainWindow::newProperty, mainDevice, &Device::newProperty);//change property


    QObject::connect(&w, &MainWindow::openSerialPort, mainDevice, &Device::openSerialPort);//open Com-порт
    QObject::connect(mainDevice, &Device::signalStateOpen , &w, &MainWindow::slotOpenSerialPort);

    QObject::connect(&w, &MainWindow::closeSerialPort, mainDevice, &Device::closeSerialPort);//close com-port
    QObject::connect(mainDevice, &Device::signalStateClose , &w, &MainWindow::slotCloseSerialPort);

    QObject::connect(mainDevice, &Device::signalMessage, &w, &MainWindow::showStatusMessage);//show message
    QObject::connect(mainDevice, &Device::signalError, &w, &MainWindow::showError);



    for(QList<View*>::const_iterator itb = w.getList()->begin(), ite = w.getList()->end(); itb != ite; itb++)//connect business-logic with view
    {
        qDebug() << *(*itb)->getName();
        QObject::connect(mainDevice->getValueModel(*(*itb)->getName()), &ValueModel::valueChanged, *itb, &View::slotValueChanged);
    }

    w.show();

    return a.exec();
}
