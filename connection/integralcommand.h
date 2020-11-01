/*
40
20
80
*/

#ifndef INTEGRALCOMMAND_H
#define INTEGRALCOMMAND_H

#include <QWidget>
#include "bitsmanipulator.h"

namespace Ui {
class IntegralCommand;
}

class IntegralCommand : public QWidget
{
    Q_OBJECT
    char code;
    QByteArray password;
    int responseLength=0;

public:
    explicit IntegralCommand(const QString &name, char cmd_code, int respLength, bool write, const QString& pass="", QWidget *parent = nullptr);
    ~IntegralCommand();
    QByteArray getFullFrame();
    virtual QList<int> parseResponse(QByteArray response)=0;
    char getCode();
    QString getName() const;
    int getResponseLength() const;
    bool isWritable();
    bool isDialogDataValid();


    QStringList getSuccess() const;
    QStringList getFailure() const;

protected:
    QStringList success;
    QStringList failure;
    void setName(const QString &name);
    QWidget* getContentWidget();
    virtual QByteArray getAdditionalContent();

private:
    Ui::IntegralCommand *ui;
    void parsePassword(QString passToParse);
};

namespace IntegralCmds {
class ReadZonesViolation: public IntegralCommand {
public:
    ReadZonesViolation(QWidget *parent=nullptr): IntegralCommand("Read zones violation", 0x00, 16, false, "", parent) {}
    QList<int> parseResponse(QByteArray response) override { //Returns zones IDs where violation is ( o , o ) YODA
        QList<int> result = QList<int>();
        result.append(BitsManipulator::getSetBitsFromArr(response));
        return result;
    }
};
class ReadZoneAlarms: public IntegralCommand {
public:
    ReadZoneAlarms(QWidget *parent=nullptr): IntegralCommand("Read alarms", 0x02, 16, false, "", parent) {}
    QList<int> parseResponse(QByteArray response) override { //Returns zones IDs where violation is ( o , o ) YODA
        QList<int> result = QList<int>();
        result.append(BitsManipulator::getSetBitsFromArr(response));
        return result;
    }
};

class ReadZonesAlarmsMemory: public IntegralCommand {
public:
    ReadZonesAlarmsMemory(QWidget *parent=nullptr): IntegralCommand("Read alarms memory", 0x15, 4, false, "", parent){}//0x04
    QList<int> parseResponse(QByteArray response) override {//Returns zones IDs where violation is ( o , o ) YODA in memory
        QList<int> result = QList<int>();
        result.append(BitsManipulator::getSetBitsFromArr(response));
        return result;
    }
};

class ReadArmedZones: public IntegralCommand {
public:
    ReadArmedZones(QWidget *parent=nullptr): IntegralCommand("Armed zones", 0x09, 4, false, "", parent){}//0x0A
    QList<int> parseResponse(QByteArray response) override {//Returns zones IDs where violation is ( o , o ) YODA in memory
        QList<int> result = QList<int>();
        result.append(BitsManipulator::getSetBitsFromArr(response));
        return result;
    }
};

class ReadMalfunctions: public IntegralCommand {
public:
    ReadMalfunctions(QWidget *parent=nullptr): IntegralCommand("Malfunctions", 0x20, 47, false, "", parent){}//0x0A
    QList<int> parseResponse(QByteArray response) override {//Returns zones IDs where violation is ( o , o ) YODA in memory
        QList<int> result = QList<int>();
        response = response.mid(40,3);
        result.append(BitsManipulator::getSetBitsFromArr(response));
        return result;
    }
};

class ReadInputStates: public IntegralCommand {
public:
    ReadInputStates(QWidget *parent=nullptr): IntegralCommand("Read input states", static_cast<char>(0x04), 8, false, "", parent){}
    QList<int> parseResponse(QByteArray response) override {//Returns zones IDs where violation is ( o , o ) YODA in memory
        QList<int> result = QList<int>();
        result.append(BitsManipulator::getSetBitsFromArr(response));
        return result;
    }
};

class GetVersion: public IntegralCommand {
public:
    GetVersion(QWidget *parent=nullptr): IntegralCommand("Get version", 0x7E, 14, false, "", parent) {}
    QList<int> parseResponse(QByteArray response) override {
        QList<int> result = QList<int>();
        if(response.count()<14) {
            return result;
        }

        if (response.at(0)==0x01) result.append(32);
        else if (response.at(0)==0x00) result.append(24);
        else if(response.at(0)==0x02) result.append(64);
        else if(response.at(0)==0x03) result.append(128);

        QString ver="";
        for(int i=1; i<4; i++)
            ver+=static_cast<char>(response.at(i));

        result.append(ver.toInt());
        return result;
    }
};

class ArmPartitions: public IntegralCommand {
    QList<int> partitionsToArm;
public:
    ArmPartitions(QList<int>& partitions, const QString& pass, QWidget *parent=nullptr): IntegralCommand("Arm partitions", static_cast<char>(0x80), 16, true, pass, parent) {
        success<<"Uzbrojono"<<"Poprawnie uzbrojono strefy/strefę.";
        failure<<"Nieuzbrojono"<<"Nie udało się uzbroić stref(y). Sprawdź czy komputer poprawnie połączony jest z centralą lub wprowadź inne klucz dostępu.";
        partitionsToArm = partitions;
    }
    QList<int> parseResponse(QByteArray response) override {
        Q_UNUSED(response)
        QList<int> result = QList<int>();
        result.append(1);
        return result;
    }
    QByteArray getAdditionalContent() override {
        return BitsManipulator::get4BArrayFromList(partitionsToArm);
    }
};

class UnarmPartitions: public IntegralCommand {
    QList<int> partitionsToUnarm;
public:
    UnarmPartitions(QList<int>& partitions, const QString& pass, QWidget *parent=nullptr): IntegralCommand("Unarm partitions", static_cast<char>(0x84), 16, true, pass, parent) {
        success<<"Rozbrojono"<<"Poprawnie rozbrojono strefy/strefę.";
        failure<<"Nie rozbrojono"<<"Nie udało się rozbroić stref(y). Sprawdź czy komputer poprawnie połączony jest z centralą lub wprowadź inne klucz dostępu.";
        partitionsToUnarm = partitions;
    }
    QList<int> parseResponse(QByteArray response) override {
        Q_UNUSED(response)
        QList<int> result = QList<int>();
        result.append(1);
        return result;
    }
    QByteArray getAdditionalContent() override {
        return BitsManipulator::get4BArrayFromList(partitionsToUnarm);
    }
};

class CleanAlarm: public IntegralCommand {
    QList<int> partitionsToClean;
public:
    CleanAlarm(QList<int>& partitions, const QString& pass, QWidget *parent=nullptr): IntegralCommand("Clean alarm", static_cast<char>(0x85), 16, true, pass, parent) {
        success<<"Skasowano alarmy"<<"Poprawnie zresetowano alarmy w strefach.";
        failure<<"Nie skasowano alarmów"<<"Alarmy nie zostały skasowane, sprawdź połączenie lub wprowadź inne hasło.";
        partitionsToClean = partitions;
    }
    QList<int> parseResponse(QByteArray response) override {
        Q_UNUSED(response)
        QList<int> result = QList<int>();
        result.append(1);
        return result;
    }
    QByteArray getAdditionalContent() override {
        return BitsManipulator::get4BArrayFromList(partitionsToClean);
    }
};

}

#endif // INTEGRALCOMMAND_H
