#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <Widgets/View/view.h>
#include <QGroupBox>
#include <QMap>
#include <QList>
#include "Widgets/Dialog/settingsserialport.h"
#include <QObject>
#include <QLabel>
#include <QMenuBar>
#include <QToolBar>
#include <QDebug>
#include <QStatusBar>
#include <QMessageBox>



class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    View* getView(const QString& key);
    const QList<View*>* getList() const ;

signals:
    void newProperty(const PropertySerialPort& prop);
    void closeSerialPort();
    void openSerialPort();

public slots:
    void showStatusMessage(const QString& msg);
    void showError(const QString& type, const QString& msg);

    void slotCloseSerialPort(bool close);
    void slotOpenSerialPort(bool open);

private slots:
    void slotNewProperty(const PropertySerialPort& prop);

private:
    QList<View*> mainList;
    QLabel *m_status;
    SettingsSerialPort* m_settings = nullptr;
    QToolBar* toolBar;

    QGroupBox *createViewBox();
    QToolBar *createToolBar();
    QGroupBox *createStatusBar();

    void EnableAction(bool equal, const QString& type);
};

#endif // MAINWINDOW_H
