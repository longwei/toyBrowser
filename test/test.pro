include(../defaults.pri)
QT += testlib
QT -= gui
TARGET = Test
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    testqstring.cpp \
    testparser.cpp

LIBS += -L../src -lmyapp

HEADERS += AutoTest.h \
    testqstring.h \
    testparser.h
