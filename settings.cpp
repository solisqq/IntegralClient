#include "settings.h"

QPoint Global::middlePoint = QPoint(0,0);
QPoint Global::getMiddleOf(int width, int height)
{
    return QPoint(static_cast<int>(static_cast<double>(Global::middlePoint.x()) - static_cast<double>(width) * 0.5), static_cast<int>(static_cast<double>(Global::middlePoint.y()) - static_cast<double>(height) * 0.5));
}

ErrorStatus *Global::errorHandler = nullptr;
int Global::errorIDCounter = 0;
Logger *Global::logger = nullptr;

QMediaPlayer *Global::Alarm::player = nullptr;
AuthorizationDialog *Global::authorization = nullptr;

QColor Global::Colors::armedColor = QColor(51, 102, 0);
QColor Global::Colors::alarmColor = QColor(255,0,0);
QColor Global::Colors::wlamColor = QColor(255,0,0);
QColor Global::Colors::unarmedColor = QColor(196,98,16);
QColor Global::Colors::disconnectedColor = QColor(90,83,83);
QColor Global::Colors::defaultCells = QColor(38,36,36);
QColor Global::Colors::whiteColor = QColor(240,240,240);

void Global::Alarm::turnOn()
{
    player->play();
}

void Global::Alarm::turnOff()
{
    player->stop();
}



Settings::~Settings(){}
SETUP::SettingsInterface &Settings::getInterface(){return interface;}

void Settings::setByString(const QString& varName, const QString &value)
{
    QList<SETUP::BY_STRING_EDITABLE*>::iterator it;
    for(it=interface.variables.begin(); it!=interface.variables.end(); ++it) {
        if(varName==it.i->t()->getName()) {
            it.i->t()->setByQString(value);
        }
    }
}

QString Settings::getReadyString()
{
    QString result="";
    QList<SETUP::BY_STRING_EDITABLE*>::iterator it;
    for(it=interface.variables.begin(); it!=interface.variables.end(); ++it) {
        result+=it.i->t()->getName()+" "+it.i->t()->toString()+"\n";
    }
    return result;
}

void Settings::save()
{
    QFile file(QDir::currentPath()+"/settings.cfg");
    bool isOpen = file.open(QIODevice::WriteOnly);

    if(!isOpen) return;
    QTextStream stream(&file);
    qDebug()<<QDir::currentPath()+"/settings.cfg";
    stream<<getReadyString();
}

void Settings::load()
{
    QFile file(QDir::currentPath()+"/settings.cfg");
    if(!file.open(QIODevice::ReadOnly)){save();return;}
    QTextStream in(&file);
    //source.append(init);

    for(int i=0; !in.atEnd(); i++) {
        QString line = in.readLine();
        QStringList splited = line.split(" ");
        if(splited.count()==2)
            setByString(splited.at(0), splited.at(1));

        //source.append(list);
    }
}
Settings settings;


