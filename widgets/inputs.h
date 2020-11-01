#ifndef INPUTS_H
#define INPUTS_H

#include <QWidget>
#include <interfaces/statehandler.h>

namespace Ui {
class Inputs;
}

class Inputs : public QWidget, public StateHandler
{
public:
    enum Type {Common=0,PIR=1,TEMP_LOW=2,TEMP_HIGH=3,KONTAKTRON=4};
private:
    Q_OBJECT
    int dbID=-1;
    QString name="";
    int inputID=1;
    Type sensorType=Type::Common;
    QPointF position;
    CustomState alarm;
    CustomState ok;
    QPointF offsets;

public:
    explicit Inputs(const QString _name="Unkown", int _id=-1, QWidget *parent = nullptr);
    ~Inputs() override;
    void updateGui();
    void updateName(const QString &newName);
    int getInputID() const;
    void setInputID(int value);
    QString getName() const;
    void setPos(const QPointF &pos, qreal xoffset=0, qreal yoffset=0);
    void setSensorType(const Type &value);
    Type getSensorType() const;
    QPointF getPosition() const;
    int getDbID() const;
    void setDbID(int value);

public slots:
    bool setAlarm(bool on=true);
    void setup(const QString& _name, int id, int type);

private:
    Ui::Inputs *ui;
    bool setState(CustomState &stateToChange, bool dualState = false) override;

signals:
    void noAlarmEmited();
    void alarmEmited();
    void editEmited(Inputs& input);
    void saveMe(Inputs& input);

private slots:
    void on_indicator_clicked();
};

#endif // INPUTS_H
