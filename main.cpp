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

    for(QList<View*>::iterator itb = w.getList()->begin(), ite = w.getList()->end(); itb != ite; itb++)
    {
        qDebug() << (*itb)->getName();
        QObject::connect(mainDevice->getValueModel((*itb)->getName()), &ValueModel::valueChanged, *itb, &View::slotValueChanged);
    }

    w.show();

    return a.exec();
}
