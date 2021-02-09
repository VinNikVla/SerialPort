#ifndef SERIALPORTINFO_H
#define SERIALPORTINFO_H

#include <QWidget>
#include <QComboBox>
#include <QtSerialPort/QSerialPortInfo>
#include <QComboBox>
#include <QLabel>
#include <QLayout>
#include <QGroupBox>
#include <QIntValidator>
#include <QLineEdit>
#include <QString>
#include <QList>
#include <QDebug>

static const char blankString[] = QT_TRANSLATE_NOOP("SerialPortINfo", "N/A");
class SerialPortINfo : public QWidget
{
    Q_OBJECT

    QString m_name;

    QComboBox* serialPortInfoListBox = nullptr;
    QLabel* description = nullptr;
    QLabel* manufacturer = nullptr;
    QLabel* serialnumber = nullptr;
    QLabel* location = nullptr;
    QLabel* vendorID = nullptr;
    QLabel* productID = nullptr;


public:
    explicit SerialPortINfo(QWidget *parent = nullptr);
    QString getPortName() const;
    QList<QWidget*> *getElements();



signals:

public slots:

private slots:
    void showPortsInfo(int index);
    void checkCustomDevicePathPolicy(int idx);
private:
    void fillPortsInfo();
    QList<QWidget*> listElements;

    void createElements();



};

#endif // SERIALPORTINFO_H
