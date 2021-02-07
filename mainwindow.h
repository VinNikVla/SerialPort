#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <Widgets/View/view.h>
#include <QGroupBox>
#include <QMap>
#include <QList>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    View* getView(const QString& key);
    QList<View*>* getList();

private:
    QList<View*> mainList;
    QGroupBox* control;

    void createViewBox();
};

#endif // MAINWINDOW_H
