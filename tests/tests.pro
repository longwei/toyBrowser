include(../defaults.pri)

CONFIG += console
CONFIG -= app_bundle
QT += testlib

TEMPLATE = app

SOURCES += \
    testa.cpp \
    main.cpp

LIBS += -L../src -lmyapp

HEADERS += \
    testa.h
