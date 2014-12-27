include(../defaults.pri)

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = toyBrowser
CONFIG -= app_bundle
CONFIG += static

TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp

LIBS += -L../src -lmyapp

INCLUDEPATH += ../src
DEPENDPATH += ../src

PRE_TARGETDEPS += ../src/*.a
#DEPENDPATH += . ../src
#INCLUDEPATH +=  ../src

HEADERS += \
    mainwindow.h

#message($$OUT_PWD)
#message($$PWD)
#install_it.path = $$OUT_PWD
#install_it.files = $$PWD/tt
#INSTALLS += install_it

message($$OUT_PWD)
message($$PWD)
target.path += $$OUT_PWD
target.files += $$PWD/test.*
INSTALLS += target

DISTFILES += \
    test.css \
    test.html

