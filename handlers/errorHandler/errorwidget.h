#ifndef ERRORWIDGET_H
#define ERRORWIDGET_H

#include "error.h"

#include <QWidget>

namespace Ui {
class errorWidget;
}

class errorWidget : public QWidget
{
    Q_OBJECT
public:
    Error *error = nullptr;
    explicit errorWidget(Error *_error, QWidget *parent = nullptr);
    ~errorWidget();

private:
    Ui::errorWidget *ui;
};

#endif // ERRORWIDGET_H
