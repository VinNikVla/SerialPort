#ifndef ABSTRACTVIEW_H
#define ABSTRACTVIEW_H

#include <QWidget>
#include <QString>
#include <QLayout>

class AbstractView : public QWidget
{
    Q_OBJECT
public:
    explicit AbstractView(const QString& _name, QWidget *parent = nullptr);
    const QString *getName() const;

protected:
    QString m_name;
    QLayout* m_layout;

    virtual void createLayout() = 0;
};

#endif // ABSTRACTVIEW_H
