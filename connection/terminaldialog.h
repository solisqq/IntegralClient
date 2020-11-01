#ifndef TERMINALDIALOG_H
#define TERMINALDIALOG_H

#include <QDialog>

namespace Ui {
class TerminalDialog;
}

class TerminalDialog : public QDialog
{
    Q_OBJECT

public:
    enum Source {
        In,
        Out
    };
    explicit TerminalDialog(QWidget *parent = nullptr);
    void updateTerminal(Source src, QByteArray& arr, QString adnotation="");
    ~TerminalDialog();

private:
    Ui::TerminalDialog *ui;
};

#endif // TERMINALDIALOG_H
