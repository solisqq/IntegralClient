#ifndef FORMWIDGET_H
#define FORMWIDGET_H

#include <QLineEdit>
#include <QWidget>

namespace Ui {
class FormWidget;
}

class FormWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FormWidget(const QString &name, const QString &defaultVal="", QWidget *parent = nullptr);
    ~FormWidget();
    QLineEdit *getField();
private:
    Ui::FormWidget *ui;
};

#endif // FORMWIDGET_H
