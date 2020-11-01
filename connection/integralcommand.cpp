#include "integralcommand.h"
#include "ui_integralcommand.h"

IntegralCommand::IntegralCommand(const QString &name, char cmd_code, int respLength, bool write, const QString& pass, QWidget *parent) :
    QWidget(parent),
    code(cmd_code),
    responseLength(respLength),
    ui(new Ui::IntegralCommand)
{
    ui->setupUi(this);
    setName(name);
    if(write) {
        ui->readWriteLabel->setText("Write Only");
        parsePassword(pass);
    }
}
void IntegralCommand::parsePassword(QString passToParse) {
    QStringList characters;
    for(int i=0; i<passToParse.length(); i+=2) {
        QString toAdd="";
        toAdd+=passToParse.at(i);
        if(i+1>=passToParse.length()) {
            toAdd +="F";
        } else {
            toAdd+=passToParse.at(i+1);
        }
        characters.append(toAdd);
    }

    for(auto character : characters) {
        bool ok=false;
        password.append(character.toUInt(&ok, 16));
    }
    for(int i=0; i<8-characters.count(); i++)
        password.append(static_cast<unsigned char>(0xFF));
    qDebug()<<password.toHex();
}
int IntegralCommand::getResponseLength() const
{
    return responseLength;
}

IntegralCommand::~IntegralCommand()
{
    delete ui;
}

void IntegralCommand::setName(const QString &name)
{
    this->ui->nameLabel->setText(name);
}

QString IntegralCommand::getName() const
{
    return this->ui->nameLabel->text();
}


QWidget *IntegralCommand::getContentWidget()
{
    return ui->additionalContentWidget;
}

char IntegralCommand::getCode()
{
    return code;
}

QByteArray IntegralCommand::getAdditionalContent()
{
    return QByteArray();
}

bool IntegralCommand::isWritable()
{
    return (ui->readWriteLabel->text().at(0)=='W');
}

bool IntegralCommand::isDialogDataValid()
{
    return (getFailure().count()>1 && getSuccess().count()>1);
}

QStringList IntegralCommand::getSuccess() const
{
    return success;
}

QStringList IntegralCommand::getFailure() const
{
    return failure;
}

QByteArray IntegralCommand::getFullFrame()
{
    QByteArray toRet;
    toRet.append(code);
    if(isWritable())
        toRet.append(password);
    toRet.append(getAdditionalContent());
    return toRet;
}

