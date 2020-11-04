#ifndef PINPOINT_H
#define PINPOINT_H

#include <QVBoxLayout>
#include <QWidget>
#include "handlers/errorHandler/errorable.h"
#include "pointshape.h"
#include "settings.h"
#include <QHostAddress>
#include <QLayout>
#include <QMouseEvent>
#include <QDebug>
#include "handlers/errorHandler/errorstatus.h"
#include "utils/converter.h"
#include "connection.h"
#include <utils/advancedgraphics.h>

namespace Ui {
class PinPoint;
}

class PinPoint : public QWidget, public ErrorAble, public AdvancedGraphics
{
    Q_OBJECT
    QHostAddress ipAddress;
    QPointF position;
    Connection connection;
    int id=-1;
public:

    explicit PinPoint(QWidget *parent = nullptr);
    ~PinPoint() override;

    void setPos(const QPointF &pos);
    void fillSetup(const QString &address, const QString &name);

    QPointF getPos();
    QString getText();
    QString getStateString();
    void setName(const QString &text);
    QHostAddress getIP();
    int getId() const;
    void setId(int value);
    bool isFakeElement();
private:
    Ui::PinPoint *ui;
    Global::States getStateByID(const QByteArray &array, int id, int lane);
    void refreshHint();
    void setIP(const QString &ip);

signals:
    void mouseOverMe();
    void closeToPointEvent(QMouseEvent *event);
    void setupDeclared();
    void removeMe(PinPoint* point);
    void updateDatabase(PinPoint &pinpoint);

public slots:
    void mouseOverPin();

private slots:
    void updateState(CustomState *state, QList<Zone*> source);
    void updateView(const QHostAddress &address, uint16_t port);
    void onUpdateEmit();

public:
    Connection &getConnection();

    // QWidget interface
protected:
    void enterEvent(QEvent *event) override;
    void leaveEvent(QEvent *event) override;

    // QWidget interface
protected:
    void mouseReleaseEvent(QMouseEvent *event) override;
};

#endif // PINPOINT_H
