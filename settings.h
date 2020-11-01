#ifndef SETTINGS_H
#define SETTINGS_H

#define APP_VERSION 0.4B
#define PRODUCTION

#define WINDOWS_OS  //WINDOWS UNCOMMENT
//#define LINUX_OS  //LINUX UNCOMMENT
#define DISK_PROTECTION_OFF false

#define minCompare(x,y) x<y ? x : y
#define maxCompare(x,y) x>y ? x : y

#include "handlers/logger/logger.h"
#include "settingsinterface.h"
#include <QWidget>
#include <widgets/menuelement.h>
#include <QColor>
#include <QMediaPlayer>
#include <handlers/authorization/authorizationmodule.h>
#include <dialogs/authorizationdialog.h>

#define GET_VAR_NAME(Variable) (#Variable)
class ErrorStatus;

class Settings: public QObject
{
    Q_OBJECT
    SETUP::SettingsInterface interface;
public:
    SETUP::S8INT ViewMode;
    SETUP::SINT ErrorHandlerTimeOut;
    SETUP::SINT packetTimeout;
    SETUP::SINT zonesUpdateTimeInMS;
    SETUP::SINT packetSenderUpdateInMS;
    SETUP::SINT mapResolution;
    SETUP::SINT volume;
    //SETUP::SINT connectionTimeOut
    SETUP::SQSTRING imgPath;
    SETUP::SBOOL production;
    SETUP::SBOOL blink;
    SETUP::SINT connectionTimeOut;
    SETUP::SQSTRING dbpath;
    SETUP::SINT defaultConnectionBackground;
    SETUP::SINT contenersCount;
    SETUP::SQSTRING apid;
    Settings():
        QObject(nullptr),
        interface(),
        ViewMode(GET_VAR_NAME(ViewMode), 0, this, &interface),
        ErrorHandlerTimeOut(GET_VAR_NAME(ErrorHandlerTimeOut), 1, this, &interface),
        packetTimeout(GET_VAR_NAME(packetTimeout), 3000, this, &interface),
        zonesUpdateTimeInMS(GET_VAR_NAME(zonesUpdateTimeInMS), 400, this, &interface),
        packetSenderUpdateInMS(GET_VAR_NAME(packetSenderUpdateInMS), 1000, this, &interface),
        mapResolution(GET_VAR_NAME(mapResolution), 1000, this, &interface),
        volume(GET_VAR_NAME(volume), 50, this, &interface),
        imgPath(GET_VAR_NAME(imgPath), "map2.jpg", this, &interface),
        production(GET_VAR_NAME(production), false, this, &interface),
        blink(GET_VAR_NAME(blink), false, this, &interface),
        connectionTimeOut(GET_VAR_NAME(connectionTimeOut), 100, this, &interface),
        dbpath(GET_VAR_NAME(dbpath), "/home/zalfon/db/main.db", this, &interface),
        defaultConnectionBackground(GET_VAR_NAME(defaultConnectionBackground), 0, this, &interface),
        contenersCount(GET_VAR_NAME(contenersCount), 2, this, &interface),
        apid(GET_VAR_NAME(apid), "112|469|434|478|706|534|714|604|458|176",this,&interface)
      //apid(GET_VAR_NAME(apid), "112|469|434|478|706|534|714|604|458|176",this,&interface)
    {this->load();}
    ~Settings() override;
    SETUP::SettingsInterface &getInterface();
    void setByString(const QString &varName, const QString &value);

private:
    QString getReadyString();

public slots:
    void save();
    void load();
};

extern Settings settings;


class Global {
public:
    static ErrorStatus *errorHandler;
    static Logger *logger;
    static AuthorizationDialog *authorization;
    static QPoint middlePoint;
    static QPoint getMiddleOf(int width, int height);
    static int errorIDCounter;
    enum States {OK=1,ALARM=2,CON_LOST=3,N_CON=4};
    class Colors {
    public:
        static QColor armedColor;
        static QColor alarmColor;
        static QColor wlamColor;
        static QColor unarmedColor;
        static QColor disconnectedColor;
        static QColor defaultCells;
        static QColor whiteColor;
    };
    class Alarm {
    public:
        static QMediaPlayer *player;
        static void turnOn();
        static void turnOff();
    };
};

#endif // SETTINGS_H
