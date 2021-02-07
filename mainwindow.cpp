#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    mainList.append(new View("X", this));
    mainList.append(new View("Y", this));
    mainList.append(new View("Z", this));
    mainList.append(new View("W", this));

    QVBoxLayout* layout = new QVBoxLayout(this);


    createViewBox();

    layout->addWidget(control);

    setLayout(layout);


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

void MainWindow::createViewBox()
{
    control = new QGroupBox("Данные от устройства", this);

    QVBoxLayout* layout = new QVBoxLayout(this);


    for(auto itb = mainList.begin(), ite = mainList.end(); itb != ite; ++itb)
    {
        layout->addWidget(*itb);
    }

    control->setLayout(layout);
}
