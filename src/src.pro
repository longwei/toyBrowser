include(../defaults.pri)

CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = lib
#DEFINES += CSS_DEBUG

CONFIG += staticlib
TARGET = myapp

SOURCES += myclass.cpp \
    nodes/elementnode.cpp \
    nodes/textnode.cpp \
    nodes/node.cpp \
    parser/parser.cpp \
    parser/domparser.cpp \
    parser/cssparser.cpp \
    parser/stylesheet.cpp
HEADERS += myclass.h \
    nodes/elementnode.h \
    nodes/textnode.h \
    nodes/node.h \
    parser/parser.h \
    parser/domparser.h \
    nodes/nodetypes.h \
    parser/cssparser.h \
    parser/stylesheet.h
