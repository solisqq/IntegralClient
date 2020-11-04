#ifndef AREYOUSUREDIALOG_H
#define AREYOUSUREDIALOG_H

#include <QDialog>

namespace Ui {
class AreYouSureDialog;
}

class AreYouSureDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AreYouSureDialog(QString question, QWidget *parent = nullptr);
    ~AreYouSureDialog();

private:
    Ui::AreYouSureDialog *ui;
};

#endif // AREYOUSUREDIALOG_H
