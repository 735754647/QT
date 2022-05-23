#-------------------------------------------------
#
# Project created by QtCreator 2015-06-29T22:59:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ImageChoose
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    wimage.cpp

HEADERS  += mainwindow.h \
    wimage.h

FORMS    += mainwindow.ui


RC_FILE += icon.qrc
