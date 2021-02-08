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
    QList<View*>* getList();

signals:
    void newData(const QByteArray& data);

public slots:
    void showStatusMessage(const QString& msg);
private slots:
    void test();
    void closeSerialPort();
    void openSerialPort();
    void readData();

private:
    QList<View*> mainList;
    QGroupBox* view;
    QGroupBox* control;
    QLabel *m_status;
    //SettingsSerialPort* m_settings = nullptr;
    QToolBar* toolBar;
    QStatusBar* statusBar;
    QSerialPort *m_serial = nullptr;

    void createViewBox();

    void createToolBar();

    void createStatusBar();
};

#endif // MAINWINDOW_H
