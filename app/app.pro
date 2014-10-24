include(../defaults.pri)

CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += static

TEMPLATE = app
SOURCES += main.cpp

LIBS += -L../src -lmyapp

INCLUDEPATH += ../src
DEPENDPATH += ../src

PRE_TARGETDEPS += ../src/*.a
#DEPENDPATH += . ../src
#INCLUDEPATH +=  ../src
