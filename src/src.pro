include(../defaults.pri)

CONFIG   += console
CONFIG   -= app_bundle
CONFIG   -= qt

TEMPLATE = lib

CONFIG += staticlib
TARGET = myapp

SOURCES += myclass.cpp \
    nodes/node.cpp
HEADERS += myclass.h \
    nodes/node.h
