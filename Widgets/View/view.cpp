#include "view.h"

View::View(const QString &_name, QWidget *parent):
    AbstractView(_name, parent)
{
    m_label = new QLabel(m_name, this);
    m_label->setFrameStyle(QFrame::Plain | QFrame::StyledPanel);

    m_value = new QLabel("UNKNOWN", this);
    m_value->setFrameStyle(QFrame::Plain | QFrame::StyledPanel);

    createLayout();
}

void View::slotValueChanged(const QString &value)
{
    m_value->setText(value);
}

void View::createLayout()
{
    m_layout = new QHBoxLayout(this);

    m_layout->addWidget(m_label);
    m_layout->addWidget(m_value);

    setLayout(m_layout);
}
