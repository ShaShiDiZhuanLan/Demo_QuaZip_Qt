#-------------------------------------------------
#
# Project created by QtCreator 2017-10-11 沙振宇
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Demo_qCompress
TEMPLATE = app

CONFIG(debug, debug|release) {
    DESTDIR = $$PWD/../../bin_debug
    LIBS += -L$$PWD/../../bin_debug -lquazip
}
CONFIG(release, debug|release) {
    DESTDIR = $$PWD/../../bin_release
    LIBS += -L$$PWD/../../bin_release -lquazip
}


SOURCES += main.cpp\
        mainwindow.cpp \
    squazip.cpp

HEADERS  += mainwindow.h \
    squazip.h

FORMS    += mainwindow.ui

RESOURCES +=
