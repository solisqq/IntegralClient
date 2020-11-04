#ifndef ERRORAGREGATOR_H
#define ERRORAGREGATOR_H

#include <QDialog>
#include "errorwidget.h"
#include <QList>
#include <settings.h>
namespace Ui {
class ErrorAgregator;
}

class ErrorAgregator : public QDialog
{
    Q_OBJECT
    QTimer blinkTimer;
    QString currentColor="rgb(155,29,29)";
public:
    explicit ErrorAgregator(QWidget *parent = nullptr);
    ~ErrorAgregator();
    void closeEvent(QCloseEvent *event);
    void updateErrors(QList<Error*>& error);
    void setVisible(bool visible);
    void setBorderColor(const QString &clr);

private:
    Ui::ErrorAgregator *ui;
    void clearLay();
signals:
    void errorsAccepted();
private slots:
    void blinkWindow();
};

#endif // ERRORAGREGATOR_H
