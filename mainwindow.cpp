#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent),
      m_settings(new SettingsSerialPort(this))
{


    mainList.append(new View("X", this));
    mainList.append(new View("Y", this));
    mainList.append(new View("Z", this));
    mainList.append(new View("W", this));

    QVBoxLayout* layout = new QVBoxLayout(this);

    layout->addWidget(createToolBar());
    layout->addWidget(createViewBox());
    layout->addWidget(createStatusBar());

    setLayout(layout);


    //setMinimumSize(200, 420);

    connect(m_settings, &SettingsSerialPort::newProperty, this, &MainWindow::slotNewProperty);


}

MainWindow::~MainWindow()
{

}

View *MainWindow::getView(const QString &key)
{
    for(auto itb = mainList.begin(), ite = mainList.end(); itb != ite; ++itb)
    {
        if(key == (*itb)->getName())
        {
            return *itb;
        }
    }

}

QList<View *> *MainWindow::getList()
{
    return &mainList;

}



void MainWindow::showStatusMessage(const QString &msg)
{
    m_status->setText(msg);
}

void MainWindow::showError(const QString &type, const QString &msg)
{
    QMessageBox::critical(this, type, msg);
}

void MainWindow::slotCloseSerialPort(bool close)
{
    if(!close)
    {
//        for(const auto& i : toolBar->actions())
//        {
//            i->setEnabled(i->text() != "disconnect");
//        }
        EnableAction(false, "disconnect");
    }
}

void MainWindow::slotOpenSerialPort(bool open)
{
    if(open)
    {
//        for(const auto& i : toolBar->actions())
//        {
//            i->setEnabled(i->text() == "disconnect");
//        }
        EnableAction(true, "disconnect");
    }
}

void MainWindow::slotNewProperty(const PropertySerialPort &prop)
{
//    for(const auto& i : toolBar->actions())
//    {
//        i->setEnabled(i->text() != "disconnect");
//    }
    EnableAction(false, "disconnect");
    showStatusMessage("Requested Parameters\n" + toString(prop));

    emit newProperty(prop);
}

QGroupBox* MainWindow::createViewBox()
{
    QGroupBox* view = new QGroupBox("Data from Device", this);

    QVBoxLayout* layout = new QVBoxLayout(this);


    for(auto itb = mainList.begin(), ite = mainList.end(); itb != ite; ++itb)
    {
        layout->addWidget(*itb);
    }

    view->setLayout(layout);

    return view;
}



QToolBar* MainWindow::createToolBar()
{
    toolBar = new QToolBar("Управление последовательным портом", this);

    toolBar->addAction(QPixmap(":/Images/settings.png"), "settings", m_settings, &SettingsSerialPort::show);
    toolBar->addSeparator();
    toolBar->addAction(QPixmap(":/Images/connect.png"), "connect", this,&MainWindow::openSerialPort);
    toolBar->addSeparator();
    toolBar->addAction(QPixmap(":/Images/disconnect.png"), "disconnect", this, &MainWindow::closeSerialPort);

//    for(const auto& i : toolBar->actions())
//    {
//        i->setEnabled(i->text() == "settings");
//    }
    EnableAction(true, "settings");

    return toolBar;
}

QGroupBox* MainWindow::createStatusBar()
{
    QGroupBox* statusBar = new QGroupBox("Messages", this);

    QVBoxLayout* layout = new QVBoxLayout(this);

    m_status = new QLabel(this);
    m_status->setMinimumSize(140, 120);

    layout->addWidget(m_status);

    statusBar->setLayout(layout);

    return statusBar;
}

void MainWindow::EnableAction(bool equal, const QString &type)
{

    for(const auto& i : toolBar->actions())
    {
        if(equal)
        {
            i->setEnabled(i->text() == type);
        }
        else
        {
            i->setEnabled(i->text() != type);
        }
    }
}
