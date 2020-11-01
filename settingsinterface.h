#ifndef SETTINGSINTERFACE_H
#define SETTINGSINTERFACE_H

#include <QString>
#include <QList>
#include <QObject>
#include <QLineEdit>
#include <QPushButton>

namespace SETUP {

class BY_STRING_EDITABLE;
class SettingsInterface
{
public:
    QList<BY_STRING_EDITABLE*> variables;
    SettingsInterface(){}
    void append(BY_STRING_EDITABLE* editable) {
        variables.append(editable);
    }
};

class BY_STRING_EDITABLE: public QObject
{
    Q_OBJECT
    QString name="";
protected:
    BY_STRING_EDITABLE() {}
    QString typeName="";
    QLineEdit *lineEdit=nullptr;
    QPushButton *button=nullptr;
public:
    BY_STRING_EDITABLE(const QString &_name, QObject *parent, SettingsInterface* sparent): QObject(parent), name(_name) {sparent->append(this);}
    virtual ~BY_STRING_EDITABLE(){}
    QString getName() {return name;}
    QString getTypeName(){return typeName;}
    virtual QString toString(){return "";}
    void addHandler(QLineEdit *handlerLineEdit, QPushButton *handlerPushButton) {
        lineEdit=handlerLineEdit;
        button=handlerPushButton;
        if(lineEdit==nullptr || button==nullptr) return;
        connect(button, &QPushButton::clicked, this, &BY_STRING_EDITABLE::handlePushButton);
    }
public slots:
    virtual bool setByQString(const QString& valueInString){Q_UNUSED(valueInString) return false;}
    void handlePushButton(){
        if(!setByQString(lineEdit->text()))
            lineEdit->setText(toString());
    }
};

class SDOUBLE: public BY_STRING_EDITABLE {
    Q_OBJECT
    double value=0;
public:
    SDOUBLE(QString name, double val, QObject *parent, SettingsInterface* sparent): BY_STRING_EDITABLE(name, parent, sparent), value(val){
        BY_STRING_EDITABLE::typeName = "double";
    }
    QString toString() override {return QString::number(value);}
    double& get() {return value;}

public slots:
    bool setByQString(const QString& valueInQString) override {
        double result = valueInQString.toDouble();
        if(result!=0.0 || valueInQString=="0"){
            value = result;
            return true;
        }
        return false;
    }
};

class SINT: public BY_STRING_EDITABLE {
    Q_OBJECT
    int value=0;

public:
    SINT(QString name, int val, QObject *parent, SettingsInterface* sparent): BY_STRING_EDITABLE(name, parent, sparent), value(val){BY_STRING_EDITABLE::typeName = "int";}
    QString toString() override {return QString::number(value);}
    int& get() {return value;}
public slots:
    bool setByQString(const QString& valueInQString) override {
        int result = valueInQString.toInt();
        if(result!=0 || valueInQString=="0"){
            value = result;
            return true;
        }
        return false;
    }
};

class SU8INT: public BY_STRING_EDITABLE {
    Q_OBJECT
    uint8_t value=0;
public:
    SU8INT(QString name, uint8_t val, QObject *parent, SettingsInterface* sparent): BY_STRING_EDITABLE(name, parent, sparent), value(val){BY_STRING_EDITABLE::typeName = "uint8_t";}
    QString toString() override {return QString::number(value);}
    uint8_t& get() {return value;}

public slots:
    bool setByQString(const QString& valueInQString) override {
        uint8_t result = valueInQString.toInt();
        if(result!=0 || valueInQString=="0"){
            value = result;
            return true;
        }
        return false;
    }
};

class S8INT: public BY_STRING_EDITABLE {
    Q_OBJECT
    int8_t value=0;
public:
    S8INT(QString name, int8_t val, QObject *parent, SettingsInterface* sparent): BY_STRING_EDITABLE(name, parent, sparent), value(val){
        BY_STRING_EDITABLE::typeName = "int8_t";
    }
    QString toString() override {return QString::number(value);}
    int8_t& get() {return value;}
public slots:
    bool setByQString(const QString& valueInQString) override {
        int8_t result = valueInQString.toInt();
        if(result!=0 || valueInQString=="0"){
            value = result;
            return true;
        }
        return false;
    }
};

class SQSTRING: public BY_STRING_EDITABLE {
    Q_OBJECT
    QString value="";
public:
    SQSTRING(QString name, QString val, QObject *parent, SettingsInterface* sparent): BY_STRING_EDITABLE(name, parent, sparent), value(val){
        BY_STRING_EDITABLE::typeName = "String";
    }
    QString toString() override {return value;}
    QString& get() {return value;}
public slots:
    bool setByQString(const QString& valueInQString) override {
        value = valueInQString;
        return true;
    }
};

class SBOOL: public BY_STRING_EDITABLE {
    Q_OBJECT
    bool value=false;
public:
    SBOOL(QString name, bool val, QObject *parent, SettingsInterface* sparent): BY_STRING_EDITABLE(name, parent, sparent), value(val){
        BY_STRING_EDITABLE::typeName = "bool";
    }
    QString toString() override {return QString::number(value);}
    bool& get() {return value;}
public slots:
    bool setByQString(const QString& valueInQString) override {
        if(valueInQString=="0") {
            value = false;
            return true;
        }
        if(valueInQString=="1") {
            value = true;
            return true;
        }
        return false;
    }
};

}

#endif // SETTINGSINTERFACE_H
