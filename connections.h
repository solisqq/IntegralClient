#ifndef CONNECTIONS_H
#define CONNECTIONS_H

#include <QWidget>
#include <connection/connectioneditor.h>
#include <database/database.h>
#include "settings.h"
#include "handlers/errorHandler/errorstatus.h"

namespace Ui {
class Connections;
}

class Connections : public QWidget
{
    Q_OBJECT
    ConnectionEditor editor;
    Database database;
    QList<PinPoint*> points;
    QSize prevSize;
public:
    explicit Connections(QWidget *parent = nullptr);
    ~Connections() override;
    ConnectionEditor *getEditor();
    void createPoint(const QPointF &pos, const QString &ipAddress="", const QString &name="", int id=-1, QStringList zonesList=QStringList(), const QString& pass="", int bgId=0);
    void loadPoints();
    void delay();
    Database& getDatabase();
private:
    Ui::Connections *ui;
    void loadMap();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void enterEvent(QEvent *event) override;
    void leaveEvent(QEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
public slots:
    void removePoint(PinPoint *toRemove);
private slots:
    void updatePointInDatabase(PinPoint &pinPoint);
};

#endif // CONNECTIONS_H
