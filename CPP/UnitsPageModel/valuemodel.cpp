#include "valuemodel.h"

ValueModel::ValueModel(QObject *parent, QString val):
    QObject(parent),
    m_value(val)
{}

QString ValueModel::getValue() const
{
    return m_value;
}


void ValueModel::setValue(QString val)
{
    if(m_value == val)
        return;

    m_value = val;
    emit valueChanged(m_value);
}

void ValueModel::setValue(double val, int precision)
{
    QString temp = QString::number(val,'f',precision);
    setValue(temp);
}

void ValueModel::setValue(int val)
{
    setValue(QString::number(val));
}
