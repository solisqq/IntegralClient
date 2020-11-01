#ifndef LOGGERDIALOG_H
#define LOGGERDIALOG_H

#include <QDialog>

namespace Ui {
class LoggerDialog;
}

class LoggerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoggerDialog(QWidget *parent = nullptr);
    ~LoggerDialog();

private:
    Ui::LoggerDialog *ui;
};

#endif // LOGGERDIALOG_H
