include(../defaults.pri)

CONFIG   += console
CONFIG   -= app_bundle
CONFIG   -= qt

TEMPLATE = lib

CONFIG += staticlib
TARGET = myapp

SOURCES += myclass.cpp
HEADERS += myclass.h
