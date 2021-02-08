#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent),
      m_serial(new QSerialPort(this))
{





    createToolBar();



    mainList.append(new View("X", this));
    mainList.append(new View("Y", this));
    mainList.append(new View("Z", this));
    mainList.append(new View("W", this));

    QVBoxLayout* layout = new QVBoxLayout(this);


    createViewBox();
    createStatusBar();

    layout->addWidget(toolBar);
    layout->addWidget(view);
    layout->addWidget(statusBar);

    //setMinimumSize(300, 300);
    setLayout(layout);

    connect(m_serial, &QSerialPort::readyRead, this, &MainWindow::readData);


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

void MainWindow::test()
{
    qDebug() << "Pressed Congigure";
    showStatusMessage("Pressed Configure///////////////////////////////////////////////////////////////////////");
}

void MainWindow::closeSerialPort()
{
    if(m_serial->isOpen())
    {
        m_serial->close();
    }

    for(const auto& i : toolBar->actions())
    {
        i->setEnabled(i->text() != "disconnect");
    }





    showStatusMessage("Disconnected");
}

void MainWindow::openSerialPort()
{
    if(m_serial->open(QIODevice::ReadOnly))
    {
        for(const auto& i : toolBar->actions())
        {
            i->setEnabled(i->text() == "disconnect");
        }
    }
    else
    {
        QMessageBox::critical(this, "Error", m_serial->errorString());
        showStatusMessage("Open Error");
    }
}

void MainWindow::readData()
{
    const QByteArray data = m_serial->readAll();

    emit newData(data);

}

void MainWindow::showStatusMessage(const QString &msg)
{
    m_status->setText(msg);
}

void MainWindow::createViewBox()
{
    view = new QGroupBox("Data from Device", this);

    QVBoxLayout* layout = new QVBoxLayout(this);


    for(auto itb = mainList.begin(), ite = mainList.end(); itb != ite; ++itb)
    {
        layout->addWidget(*itb);
    }

    view->setLayout(layout);
}



void MainWindow::createToolBar()
{
    toolBar = new QToolBar("Управление последовательным портом", this);

    toolBar->addAction(QPixmap(":/Images/settings.png"), "settings", this,SLOT(test()));
    toolBar->addSeparator();
    toolBar->addAction(QPixmap(":/Images/connect.png"), "connect", this,SLOT(openSerialPort()));
    toolBar->addSeparator();
    toolBar->addAction(QPixmap(":/Images/disconnect.png"), "disconnect", this,SLOT(closeSerialPort()));

    for(const auto& i : toolBar->actions())
    {
        i->setEnabled(i->text() != "disconnect");
    }

}

void MainWindow::createStatusBar()
{
    statusBar = new QStatusBar(this);
    m_status = new QLabel(this);
    statusBar->addWidget(m_status);
}
