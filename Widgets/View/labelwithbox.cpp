#include "labelwithbox.h"

LabelWithBox::LabelWithBox(const QString &_name, QWidget *parent) :
    QWidget(parent),
    m_name(_name)
{
    label = new QLabel(m_name, this);
    label->setMinimumSize(100, 30);
    value = new QComboBox(this);
    value->setMinimumSize(100, 30);

    QHBoxLayout* mainlayout = new QHBoxLayout(this);

    mainlayout->addWidget(label);
    mainlayout->addWidget(value);
    setLayout(mainlayout);
}

int LabelWithBox::itemData()
{
    return value->itemData(value->currentIndex()).toInt();
}

QString LabelWithBox::currentText()
{
    return value->currentText();
}

void LabelWithBox::addItem(const QString &text, const QVariant &data)
{
    value->addItem(text, data);
}


void LabelWithBox::resizeEvent(QResizeEvent *event)
{
    qDebug() << event->size();
    //setMinimumSize(label->size() + value->size());
    qDebug() << event->size();
}
