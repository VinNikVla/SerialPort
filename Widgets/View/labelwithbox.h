#ifndef LABELWITHBOX_H
#define LABELWITHBOX_H

#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QVariant>
#include <QLayout>
#include <QResizeEvent>
#include <QDebug>

class LabelWithBox : public QWidget
{
    Q_OBJECT

    QLabel* label = nullptr;
    QComboBox* value = nullptr;

    QString m_name;
public:
    explicit LabelWithBox(const QString& _name, QWidget *parent = nullptr);
    int itemData();
signals:

public slots:
    void addItem(const QString& text, const QVariant& data);

    // QWidget interface
protected:
    virtual void resizeEvent(QResizeEvent *event);
};

#endif // LABELWITHBOX_H
