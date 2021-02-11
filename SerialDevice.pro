#-------------------------------------------------
#
# Project created by QtCreator 2021-02-07T20:31:50
#
#-------------------------------------------------

QT       += core gui
QT += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SerialDevice
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
    CPP/Device/device.cpp \
    CPP/Device/parserdevice.cpp \
    CPP/Device/structdevice.cpp \
    CPP/UnitsPageModel/valuemodel.cpp \
    Widgets/View/view.cpp \
    Widgets/Dialog/settingsserialport.cpp \
    Widgets/Dialog/serialportinfo.cpp \
    Widgets/Dialog/serialportproperty.cpp \
    Widgets/View/labelwithbox.cpp \
    CPP/SerialPort/serial_common.cpp \
    Widgets/Dialog/serialportabstract.cpp

HEADERS += \
        mainwindow.h \
    CPP/Device/device.h \
    CPP/Device/parserdevice.h \
    CPP/Device/structdevice.h \
    CPP/UnitsPageModel/valuemodel.h \
    Widgets/View/view.h \
    Widgets/Dialog/settingsserialport.h \
    CPP/SerialPort/serial_common.h \
    Widgets/Dialog/serialportinfo.h \
    Widgets/Dialog/serialportproperty.h \
    Widgets/View/labelwithbox.h \
    Widgets/Dialog/serialportabstract.h

RESOURCES += \
    resourses.qrc
