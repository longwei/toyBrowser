include(../defaults.pri)
QT += testlib
QT -= gui
TARGET = Test
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    test1.cpp \
    test2.cpp \
    testa.cpp

LIBS += -L../src -lmyapp

HEADERS += AutoTest.h \
    test1.h \
    test2.h \
    testa.h
