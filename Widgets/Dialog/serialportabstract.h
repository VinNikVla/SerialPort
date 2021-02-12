#ifndef SERIALPORTABSTRACT_H
#define SERIALPORTABSTRACT_H

#include <QWidget>
#include <QList>
#include <QDebug>

class SerialPortAbstract : public QWidget
{
    Q_OBJECT

public:
    explicit SerialPortAbstract(QWidget *parent = nullptr);
    const QList<QWidget*>* getElements() const;

protected:
    QList<QWidget*> listElements;
    virtual void createElements() = 0;
};

#endif // SERIALPORTABSTRACT_H
