#include "abstractview.h"

AbstractView::AbstractView(const QString &_name, QWidget *parent):
    QWidget(parent),
    m_name(_name)
{

}

const QString *AbstractView::getName() const
{
    return &m_name;
}
