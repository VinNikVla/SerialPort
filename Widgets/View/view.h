#ifndef VIEW_H
#define VIEW_H

#include <QWidget>
#include <QLabel>
#include <QLayout>

class View : public QWidget
{
    Q_OBJECT
public:
    explicit View(const QString& _name, QWidget *parent = nullptr);
    QString getName() const;
public slots:
    void slotValueChanged(const QString& value);

private:
    QString m_name;
    QLabel* m_value;
};

#endif // VIEW_H
