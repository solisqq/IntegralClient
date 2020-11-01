#ifndef ERRORSTATUS_H
#define ERRORSTATUS_H

#include <QScrollArea>
#include <QSplitter>
#include <QTimer>
#include <QVBoxLayout>
#include <QWidget>
#include "errorable.h"
#include "settings.h"
#include "errorwidget.h"
#include <QtMultimedia/QMediaPlayer>
#include <QFile>
#include <database/database.h>
#include "erroragregator.h"
#include "widgets/menuelement.h"

namespace Ui {
class ErrorStatus;
}

class ErrorStatus : public QWidget, public MenuElement
{
    Q_OBJECT
    QList<Error*> errors;
    QTimer *timer;
    ErrorAgregator *agregator;
    Database *database=nullptr;

public:
    explicit ErrorStatus(QWidget *parent = nullptr);
    ~ErrorStatus() override;
    void abort();
    QWidget * getView() override;
    void setDatabase(Database &value);
    Database *getDatabase() const;

public slots:
    void checkForErrors();
    void handleAgregatorAccept();

private:
    Ui::ErrorStatus *ui;
    void clear(QLayout *layout);
    void updateErrors();
};

#endif // ERRORSTATUS_H
