#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "settings.h"
#include <QMainWindow>
#include "connection.h"
#include <QDebug>
#include "mainmenu.h"

#ifdef WINDOWS_OS
    #include <Windows.h>
#endif
#ifdef LINUX_OS
    #include <string.h>
    #include <libudev.h>
    #include <sys/stat.h>
#endif
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Connection *connection=nullptr;
    #ifdef WINDOWS_OS
    DWORD dwVolSerial;
    #endif
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setViewMode(int mode);

    MainMenu *getMenu();
    bool validate();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
