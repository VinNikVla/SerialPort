#include "view.h"

View::View(const QString &_name, QWidget *parent):
    QWidget(parent),
    m_name(_name)
{
    m_label = new QLabel(m_name, this);
    m_label->setFrameStyle(QFrame::Plain | QFrame::StyledPanel);

    m_value = new QLabel("UNKNOWN", this);
    m_value->setFrameStyle(QFrame::Plain | QFrame::StyledPanel);

    QHBoxLayout* layout = new QHBoxLayout(this);

    layout->addWidget(m_label);
    layout->addWidget(m_value);

    setLayout(layout);
}

QString View::getName() const
{
    return m_name;
}

void View::slotValueChanged(const QString &value)
{
    m_value->setText(value);
}

void View::resizeEvent(QResizeEvent *event)
{
    qDebug() << size().width() << " " << size().height();
//    m_label->resize(this->size().width() * 0.25, this->size().height());
//    m_value->resize(this->size().width() * 0.75, this->size().height());
}
