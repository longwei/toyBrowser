include(../defaults.pri)

CONFIG   += console
CONFIG   -= app_bundle
QT += widgets

TEMPLATE = lib

CONFIG += staticlib
TARGET = myapp

SOURCES += \
    nodes/elementnode.cpp \
    nodes/textnode.cpp \
    nodes/node.cpp \
    parser/parser.cpp \
    parser/domparser.cpp \
    parser/cssparser.cpp \
    parser/stylesheet.cpp \
    parser/cssrule.cpp \
    document.cpp \
    render/paintarea.cpp
HEADERS += \
    nodes/elementnode.h \
    nodes/textnode.h \
    nodes/node.h \
    parser/parser.h \
    parser/domparser.h \
    nodes/nodetypes.h \
    parser/cssparser.h \
    parser/stylesheet.h \
    parser/cssrule.h \
    document.h \
    render/paintarea.h
