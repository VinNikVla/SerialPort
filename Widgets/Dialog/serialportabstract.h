#ifndef SERIALPORTABSTRACT_H
#define SERIALPORTABSTRACT_H

#include <QWidget>

class SerialPortAbstract : public QWidget
{
    Q_OBJECT
public:
    explicit SerialPortAbstract(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // SERIALPORTABSTRACT_H