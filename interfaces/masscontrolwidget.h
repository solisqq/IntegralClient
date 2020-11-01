#ifndef MASSCONTROLWIDGET_H
#define MASSCONTROLWIDGET_H

#include <QObject>
#include <QWidget>

class MassControlWidget : public QObject
{
    Q_OBJECT
    QList<QWidget*> widgetsToControl;
public:
    MassControlWidget(QObject *parent = nullptr);
    MassControlWidget(std::initializer_list<QWidget*>, QObject *parent = nullptr);

    void addControlls(std::initializer_list<QWidget *> controlls);
public slots:
    void show();
    void hide();
    void enable();
    void disable();
signals:

};

#endif // MASSCONTROLWIDGET_H
