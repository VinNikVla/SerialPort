#ifndef LABELWITHBOX_H
#define LABELWITHBOX_H

#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QVariant>
#include <QLayout>
#include <QResizeEvent>
#include <QDebug>
#include "abstractview.h"

class LabelWithBox : public AbstractView
{
    Q_OBJECT

    QComboBox* value = nullptr;
    QLabel* label;

public:
    explicit LabelWithBox(const QString& _name, QWidget *parent = nullptr);
    int itemData();
    QString currentText();

public slots:
    void addItem(const QString& text, const QVariant& data);

private:
    virtual void createLayout() override;
};

#endif // LABELWITHBOX_H
