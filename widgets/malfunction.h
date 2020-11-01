#ifndef MALFUNCTION_H
#define MALFUNCTION_H

#include <QWidget>
#include "handlers/errorHandler/error.h"
#include <interfaces/customstate.h>

namespace Ui {
class Malfunction;
}

class Malfunction : public QWidget
{
    Q_OBJECT
    CustomState warning;
    CustomState ok;
public:
    explicit Malfunction(QString name, QWidget *parent = nullptr);
    ~Malfunction();
    void setName(const QString& text);
    bool getState();

public slots:
    bool setState(bool state);

private:
    Ui::Malfunction *ui;
};

#endif // MALFUNCTION_H
