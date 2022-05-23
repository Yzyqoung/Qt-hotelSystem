#-------------------------------------------------
#
# Project created by QtCreator 2022-04-22T11:45:34
#
#-------------------------------------------------

QT       += core gui
QT       += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Hotel_Manage
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
#-------------------------------------------------
#
# Project created by QtCreator 2022-04-22T11:45:34
#
#-------------------------------------------------

QT       += core gui
QT       += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Hotel_Manage
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
        LOG_CONFIG/log.cpp \
        login.cpp \
        dbpage.cpp \
        frmdbpage.cpp \
        accountauthorization.cpp \
        saveloginuser.cpp \
        unpayfrmdbpage.cpp \
        payfrmdbpage.cpp \
        customerinfo.cpp \
        backupssql.cpp

HEADERS += \
        mainwindow.h \
        SQL_CONFIG/sql_connect.h \
        LOG_CONFIG/log.h \
        login.h \
        dbpage.h \
        frmdbpage.h \
        unpayfrmdbpage.h \
        accountauthorization.h \
        payfrmdbpage.h \
        saveloginuser.h \
        customerinfo.h \
        backupssql.h

FORMS += \
        mainwindow.ui \
        login.ui \
        frmdbpage.ui\
        unpayfrmdbpage.ui \
        accountauthorization.ui \
        payfrmdbpage.ui \
        customerinfo.ui \
        backupssql.ui

DISTFILES +=

RESOURCES += \
    images.qrc
