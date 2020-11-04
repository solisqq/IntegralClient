#ifndef INPUTEDITDIALOG_H
#define INPUTEDITDIALOG_H

#include <QDialog>

#include <widgets/inputs.h>
#include "settings.h"
namespace Ui {
class InputEditDialog;
}

class InputEditDialog : public QDialog
{
    Q_OBJECT
    Inputs* input;
    int itemsCount=0;
public:
    InputEditDialog(Inputs &_input, int count, QWidget *parent = nullptr);
    ~InputEditDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::InputEditDialog *ui;

protected:
    void showEvent(QShowEvent *event);
};

#endif // INPUTEDITDIALOG_H
