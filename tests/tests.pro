include(../defaults.pri)

CONFIG += console
CONFIG -= app_bundle
#CONFIG -= qt
QT += testlib

TEMPLATE = app

SOURCES += \
    testa.cpp

LIBS += -L../src -lmyapp

HEADERS += \
    testa.h
