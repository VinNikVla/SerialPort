#ifndef ABSTRACTVIEW_H
#define ABSTRACTVIEW_H

#include <QWidget>

class AbstractView : public QWidget
{
    Q_OBJECT
public:
    explicit AbstractView(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // ABSTRACTVIEW_H