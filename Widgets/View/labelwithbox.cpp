#include "labelwithbox.h"

LabelWithBox::LabelWithBox(const QString &_name, QWidget *parent) :
    AbstractView(_name, parent)
{
    label = new QLabel(m_name, this);
    label->setMinimumSize(100, 30);
    value = new QComboBox(this);
    value->setMinimumSize(100, 30);

    createLayout();

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

void LabelWithBox::createLayout()
{

    m_layout = new QHBoxLayout(this);

    m_layout->addWidget(label);
    m_layout->addWidget(value);
    setLayout(m_layout);
}
