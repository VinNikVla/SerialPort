#pragma once

#include <QObject>

//https://evileg.com/ru/post/305/ the same

class ValueModel :public QObject
{
    Q_OBJECT
public:
    ValueModel(QObject *parent, QString val = "UNKNOWN");

    QString getValue() const;

signals:
    void  valueChanged(const QString& val);

public slots:
    void setValue(QString val);
    void setValue(double val,int precision=1);
    void setValue(int val);

protected:
    QString m_value;


};
