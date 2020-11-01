#ifndef MALFUNCTIONWIDGET_H
#define MALFUNCTIONWIDGET_H

#include "malfunction.h"
#include <QWidget>

namespace Ui {
class MalfunctionWidget;
}

class MalfunctionWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MalfunctionWidget(QWidget *parent = nullptr);
    ~MalfunctionWidget();
    QList<Malfunction *> getMalfunctions();
public slots:
    void setStates(const QList<int> &list);
private:
    Ui::MalfunctionWidget *ui;
    void addMalfunctions(const std::initializer_list<QString> &);
    Malfunction *getMalfunctionByID(int id);
signals:
    void malfunctionStateChanged(const Malfunction& malfunction);
};

#endif // MALFUNCTIONWIDGET_H
