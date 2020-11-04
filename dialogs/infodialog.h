#ifndef INFODIALOG_H
#define INFODIALOG_H

#include <QDialog>
#include <widgets/menuelement.h>

namespace Ui {
class InfoDialog;
}

class InfoDialog : public QDialog
{
    Q_OBJECT

public:
    enum Type {
        Error=2,
        Warning=1,
        Info=0
    };
    explicit InfoDialog(Type dialogType, QString title, QString msg, QWidget *parent = nullptr, bool log=false);
    ~InfoDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::InfoDialog *ui;
};

#endif // INFODIALOG_H
