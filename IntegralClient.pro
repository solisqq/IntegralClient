QT       += core gui network uiplugin multimedia sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++11 plugin #link_pkgconfig #LINUX UNCOMMENT

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS #LINK_LIBUDEV #LINUX UNCOMMENT
#PKGCONFIG += libudev #LINUX UNCOMMENT
# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connection.cpp \
    connection/connectioneditor.cpp \
    connection/integralcommand.cpp \
    connection/packet.cpp \
    connection/packethandler.cpp \
    connection/terminaldialog.cpp \
    connection/view/viewlabel.cpp \
    connection/view/viewwidget.cpp \
    connections.cpp \
    database/database.cpp \
    dbrequest.cpp \
    dialogs/areyousuredialog.cpp \
    dialogs/authorizationdialog.cpp \
    dialogs/configdialog.cpp \
    dialogs/getpassworddialog.cpp \
    dialogs/infodialog.cpp \
    dialogs/inputeditdialog.cpp \
    dialogs/packetdialog.cpp \
    dialogs/passworddialog.cpp \
    dialogs/zoneeditdialog.cpp \
    handlers/authorization/authorizationmodule.cpp \
    handlers/authorization/copyprotection.cpp \
    handlers/errorHandler/error.cpp \
    handlers/errorHandler/errorable.cpp \
    handlers/errorHandler/erroragregator.cpp \
    handlers/errorHandler/errordialog.cpp \
    handlers/errorHandler/errorstatus.cpp \
    handlers/errorHandler/errorwidget.cpp \
    handlers/fileparser/fileparser.cpp \
    handlers/logger/databaseviewwidget.cpp \
    handlers/logger/logger.cpp \
    handlers/logger/loggerdialog.cpp \
    handlers/printable/printable.cpp \
    interfaces/authorizationinterface.cpp \
    interfaces/customstate.cpp \
    interfaces/dbinterface.cpp \
    interfaces/editorfunctions.cpp \
    interfaces/editorinterface.cpp \
    interfaces/fastproxystyle.cpp \
    interfaces/functiontemplate.cpp \
    interfaces/masscontrolwidget.cpp \
    interfaces/statehandler.cpp \
    main.cpp \
    mainmenu.cpp \
    mainwindow.cpp \
    settings.cpp \
    settingsinterface.cpp \
    settingswidget.cpp \
    utils/advancedgraphics.cpp \
    utils/converter.cpp \
    widgets/clickableicon.cpp \
    widgets/fastview.cpp \
    widgets/formwidget.cpp \
    widgets/iconmenu.cpp \
    widgets/inputs.cpp \
    widgets/malfunction.cpp \
    widgets/malfunctionwidget.cpp \
    widgets/mapwidget.cpp \
    widgets/menuelement.cpp \
    widgets/pinpoint/pinpoint.cpp \
    widgets/pinpoint/pointshape.cpp \
    widgets/tinyinput.cpp \
    widgets/zone.cpp \
    widgets/zoneslistwidget.cpp

HEADERS += \
    connection.h \
    connection/bitsmanipulator.h \
    connection/connectioneditor.h \
    connection/integralcommand.h \
    connection/packet.h \
    connection/packethandler.h \
    connection/terminaldialog.h \
    connection/view/viewlabel.h \
    connection/view/viewwidget.h \
    connections.h \
    database/database.h \
    dbrequest.h \
    dialogs/areyousuredialog.h \
    dialogs/authorizationdialog.h \
    dialogs/configdialog.h \
    dialogs/getpassworddialog.h \
    dialogs/infodialog.h \
    dialogs/inputeditdialog.h \
    dialogs/packetdialog.h \
    dialogs/passworddialog.h \
    dialogs/zoneeditdialog.h \
    handlers/authorization/authorizationmodule.h \
    handlers/authorization/copyprotection.h \
    handlers/errorHandler/error.h \
    handlers/errorHandler/errorable.h \
    handlers/errorHandler/erroragregator.h \
    handlers/errorHandler/errordialog.h \
    handlers/errorHandler/errorstatus.h \
    handlers/errorHandler/errorwidget.h \
    handlers/fileparser/fileparser.h \
    handlers/logger/databaseviewwidget.h \
    handlers/logger/logger.h \
    handlers/logger/loggerdialog.h \
    handlers/printable/printable.h \
    interfaces/authorizationinterface.h \
    interfaces/customstate.h \
    interfaces/dbinterface.h \
    interfaces/editorfunctions.h \
    interfaces/editorinterface.h \
    interfaces/fastproxystyle.h \
    interfaces/functiontemplate.h \
    interfaces/masscontrolwidget.h \
    interfaces/statehandler.h \
    mainmenu.h \
    mainwindow.h \
    settings.h \
    settingsinterface.h \
    settingswidget.h \
    utils/advancedgraphics.h \
    utils/converter.h \
    widgets/clickableicon.h \
    widgets/fastview.h \
    widgets/formwidget.h \
    widgets/iconmenu.h \
    widgets/inputs.h \
    widgets/malfunction.h \
    widgets/malfunctionwidget.h \
    widgets/mapwidget.h \
    widgets/menuelement.h \
    widgets/pinpoint/pinpoint.h \
    widgets/pinpoint/pointshape.h \
    widgets/tinyinput.h \
    widgets/zone.h \
    widgets/zoneslistwidget.h

FORMS += \
    connection.ui \
    connection/connectioneditor.ui \
    connection/integralcommand.ui \
    connection/packethandler.ui \
    connection/terminaldialog.ui \
    connection/view/viewwidget.ui \
    connections.ui \
    dialogs/areyousuredialog.ui \
    dialogs/authorizationdialog.ui \
    dialogs/configdialog.ui \
    dialogs/getpassworddialog.ui \
    dialogs/infodialog.ui \
    dialogs/inputeditdialog.ui \
    dialogs/packetdialog.ui \
    dialogs/passworddialog.ui \
    dialogs/zoneeditdialog.ui \
    handlers/errorHandler/erroragregator.ui \
    handlers/errorHandler/errordialog.ui \
    handlers/errorHandler/errorstatus.ui \
    handlers/errorHandler/errorwidget.ui \
    handlers/logger/databaseviewwidget.ui \
    handlers/logger/loggerdialog.ui \
    mainmenu.ui \
    mainwindow.ui \
    settingswidget.ui \
    widgets/clickableicon.ui \
    widgets/fastview.ui \
    widgets/formwidget.ui \
    widgets/iconmenu.ui \
    widgets/inputs.ui \
    widgets/malfunction.ui \
    widgets/malfunctionwidget.ui \
    widgets/mapwidget.ui \
    widgets/pinpoint/pinpoint.ui \
    widgets/pinpoint/pointshape.ui \
    widgets/tinyinput.ui \
    widgets/zone.ui \
    widgets/zoneslistwidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc
