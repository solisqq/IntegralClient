/*
 *obsługa awarii
 *awaria na zolto
Kasuj alarm
dla kazdego obiektu rozne haslo
Powiadomienia po kliknieciu odzbroj uzbroj itp
obserwowanie obiektów i ruchu
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "handlers/errorHandler/errorstatus.h"
#include <QApplication>
#include <QSettings>
#include "database/database.h"
#include "QDesktopWidget"
#include "handlers/authorization/copyprotection.h"
#include <dialogs/infodialog.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    //Make sure Globals are initialized before setupUi
    Global::authorization = new AuthorizationDialog(this);
    Global::Alarm::player = new QMediaPlayer; //Buzzer
    Global::Alarm::player->setMedia(QUrl::fromLocalFile(QFileInfo("beep.mp3").absoluteFilePath())); //set buzzzer path
    Global::Alarm::player->setVolume(settings.volume.get());

    ui->setupUi(this);

    ui->connectionLayout->addWidget(&this->ui->menuWidget->connectionsWidget); //Custom add connections widget (display map and connections)
    setViewMode(settings.ViewMode.get()); //set view mode, depend on settings (full screen, maximised, normal)
    if(!validate()) QTimer::singleShot(10, this, &MainWindow::close); //check if hashed drive serial is equal to the hashed one in settings file
    QTimer::singleShot(10, Global::authorization, &AuthorizationDialog::OnLogOut); //Make sure that user is logged out

    QFont f = QApplication::font(); //Setup global font antialiasing
    f.setStyleStrategy(QFont::PreferAntialias);//Setup global font antialiasing
    QApplication::setFont(f);//Setup global font antialiasing
}

bool MainWindow::validate() {
    if(!settings.production.get()==false) { qDebug()<<"TEST MODE (NON-PRODUCTION)"; return true; }
    else qDebug()<<"Zalfon Integral v1.1 Production";
#ifdef WINDOWS_OS
    GetVolumeInformation(TEXT("C:\\"), nullptr, NULL, &dwVolSerial, nullptr, nullptr, nullptr, NULL);
    int mult1=0, mult2=0;
    QString serial = QString::number(dwVolSerial);
    CopyProtection::hash(serial, mult1, mult2);
    if(CopyProtection::unhash(settings.apid.get())==serial) return true;
    else {
        if(CopyProtection::unhash(settings.apid.get(),true)==serial) return true;
        auto errdialog = new InfoDialog(InfoDialog::Type::Warning, "Pirat", "Kopiowanie oprogramowania zabronione! Kod błędu: "+QString::number(mult1)+QString::number(mult2));
        errdialog->show();
    }
    return DISK_PROTECTION_OFF;
#endif
#ifdef LINUX_OS
    struct udev *ud = NULL;
    struct stat statbuf;
    struct udev_device *device = NULL;
    struct udev_list_entry *entry = NULL;

    ud = udev_new();
    if (NULL == ud) {
        fprintf(stderr, "Failed to create udev.\n");
    } else {
        if (0 != stat("/dev/sda", &statbuf)) {
            fprintf(stderr, "Failed to stat /dev/sda.\n");
        } else {
            device = udev_device_new_from_devnum(ud, 'b', statbuf.st_rdev);
            if (NULL == device) {
                fprintf(stderr, "Failed to open /dev/sda.\n");
            } else {
                entry = udev_device_get_properties_list_entry(device);
                while (NULL != entry) {
                    if (0 == strcmp(udev_list_entry_get_name(entry),
                                    "ID_SERIAL")) {
                        break;
                    }
                    entry = udev_list_entry_get_next(entry);
                }
                auto splitted = QString(udev_list_entry_get_value(entry)).split("_");
                int mult1=0, mult2=0;
                CopyProtection::hash(splitted.last(), mult1, mult2);
                if(CopyProtection::unhash(settings.apid.get())==splitted.last()) return true;
                else {
                    auto errdialog = new InfoDialog(InfoDialog::Type::Warning, "Pirat", "Kopiowanie oprogramowania zabronione! Kod błędu: "+QString::number(mult1)+QString::number(mult2));
                    errdialog->show();
                    return DISK_PROTECTION_OFF;
                }
                udev_device_unref(device);
            }
        }

        (void)udev_unref(ud);
    }
    return DISK_PROTECTION_OFF;
#endif
    return false;
}

MainMenu* MainWindow::getMenu() {
    return this->ui->menuWidget;
}

MainWindow::~MainWindow()
{
    ui->connectionLayout->removeWidget(&this->ui->menuWidget->connectionsWidget);
    delete ui;
}

void MainWindow::setViewMode(int mode)
{
    QRect desktopRect = QApplication::desktop()->availableGeometry(this);
    Global::middlePoint = desktopRect.center();
    //asd
    if(mode<=0) { //NORMAL
        move(Global::getMiddleOf(width(),height()));
    } else if(mode==1) { //MAXIMIZED
        setWindowState(Qt::WindowMaximized);
    } else if(mode<=2) { //FULLSCREEN
        QMainWindow::showFullScreen();
    }
}
