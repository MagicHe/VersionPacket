#-------------------------------------------------
#
# Project created by QtCreator 2016-04-14T21:42:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VersionPacket
TEMPLATE = app


SOURCES += main.cpp\
        frmmain.cpp \
    api/app.cpp \
    api/appinit.cpp \
    api/iconhelper.cpp \
    usercontrol/frminputbox.cpp \
    usercontrol/frmmessagebox.cpp

HEADERS  += frmmain.h \
    api/app.h \
    api/appinit.h \
    api/iconhelper.h \
    api/myhelper.h \
    usercontrol/frminputbox.h \
    usercontrol/frmmessagebox.h

FORMS    += frmmain.ui \
    usercontrol/frminputbox.ui \
    usercontrol/frmmessagebox.ui

RESOURCES += \
    other/rc.qrc

DISTFILES += \
    other/main.ico \
    other/main.rc
