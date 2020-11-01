#ifndef MAPWIDGET_H
#define MAPWIDGET_H

#include "inputs.h"
#include "tinyinput.h"
#include <QWidget>
#include <QMouseEvent>
#include <dialogs/inputeditdialog.h>
#include <database/database.h>
#include <QResizeEvent>
#include "malfunctionwidget.h"
#include "settings.h"

namespace Ui {
class MapWidget;
}

class MapWidget : public QWidget, public AuthorizationInterface
{
    Q_OBJECT
    int bgId=0;
    QList<Inputs*> inputs;
    bool adderState=false;
    Database* database=nullptr;
    int connectionID=0;
    QSize prevSize;
    QList<TinyInput*> tinyInputs;
    QStringList availableBackgrounds;
public:
    explicit MapWidget(QWidget *parent = nullptr);
    ~MapWidget() override;
    void passDatabase(Database& db, int connid);
    QString getBackgroundPath() const;
    void setConnectionID(int value);
    void updateInputStatus(const QList<int> &items);
    QStringList getAvailableBackgrounds() const;
    int getBackgroundId() const;
    void setInputsCount(int count);

    MalfunctionWidget &getMalfunctionWidget();
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void createInput(const QPointF &_pos, const QString &_name="Unknown", int id=-1, int dbID=-1, int type=-1);
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void on_addButton_clicked();
    void showEditDialog(Inputs &_input);
    void saveInput(Inputs &_input);

public slots:
    void setBackground(int id);

private:
    Ui::MapWidget *ui;
    void clearLayout(QLayout *layoutt);
};

#endif // MAPWIDGET_H
