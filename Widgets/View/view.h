#ifndef VIEW_H
#define VIEW_H

#include <QWidget>
#include <QLabel>
#include <QLayout>
#include <QDebug>
#include "abstractview.h"

class View : public AbstractView
{
    Q_OBJECT

    QLabel* m_label;
    QLabel* m_value;

public:
    explicit View(const QString& _name, QWidget *parent = nullptr);

public slots:
    void slotValueChanged(const QString& value);

private:
    virtual void createLayout() override;

};

#endif // VIEW_H
