#include "serialportabstract.h"

SerialPortAbstract::SerialPortAbstract(QWidget *parent) : QWidget(parent)
{

}

const QList<QWidget *> *SerialPortAbstract::getElements() const
{
    return &listElements;
}
